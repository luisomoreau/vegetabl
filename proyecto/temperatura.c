/*
 * File:   temperatura.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 25, 2015, 8:45 PM
 */


#include "xc.h"
//SI SE CONECTA A ANALÓGICO CAMBIAR PORTB POR PORTA
static unsigned int cont=0;
void read_DHT11(int n_pin,double * valores)
{
    unsigned int vez=0;
    unsigned int error=0;
    unsigned int i;
    
    TRISB &= ~(1<<n_pin);
    PORTB &= ~(1<<n_pin);
    cont=0;
    while(cont!=18000);
    PORTB |= (1<<n_pin);
    while((PORTB & (1<<n_pin))>>n_pin==1);
    TRISB |= (1<<n_pin);
    cont=0;
    if(cont==80 && vez==1){
        if((PORTB & (1<<n_pin))>>n_pin==0){
            cont=0;
            vez++;
        }else{
            error++;
        }
    }
    if(cont==80 && vez==2 && error==0){
        if((PORTB & (1<<n_pin))>>n_pin==1){
            cont=0;
            vez++;
        }else{
            error++;
        }
    }
    
    for(i=0;i<40;i++){
        while(cont!=50);
        cont=0;
        while((PORTB & (1<<n_pin))>>n_pin==1);
        if(cont>=26 && cont<=28)
            valores[i]=0;
        if(cont==70)
            valores[i]=1;
        cont=0;
    }
}
void temperatura(double* valores)
{
    unsigned int temperatura=0;
    
    temperatura = (valores & 0xF00)>>8;
    
}
void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void)
{
    IFS0bits.T1IF=0;
    cont++;
    
}

