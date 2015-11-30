/*
 * File:   ConversorAD.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 21, 2015, 10:39 AM
 */


#include "xc.h"


void init_ad(int pines, int n_pines ){
    TRISB |= pines & 0x3F >> 2 ;
    TRISA |= pines & 3 ;
    AD1PCFGL = ~pines;
    AD1CSSL = pines;
    AD1CON3 = 0x0105; // SAMC = 1, ADCS = 5 -> 1 ciclo de muestreo
    AD1CON2 = 0x0400 | (n_pines << 2); // CSCNA, SMPI escaneo
    AD1CON1 = 0x80E4; // ADON, SSRC = 111, ASAM = 1.
}

void get_ad(int n_pines, int* valores){
    int * pBuf = (int*)0x300; // 0x300 es la dirección de memoria del AD1CBUF0
    int i;
    IFS0bits.AD1IF = 0;
    while (!IFS0bits.AD1IF); // conversión terminada?
    for ( i = 0; i < n_pines; i++){
       valores[i] = *(pBuf+i);
    }
}
