/*
 * File:   interrupciones.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 26, 2015, 7:06 PM
 */


#include "xc.h"

void init_T1(void)
{
    TMR1=0;
    T1CONbits.TCKPS=0;
    PR1=40;
    IFS0bits.T1IF=0; 
    IEC0bits.T1IE=1; 
    T1CONbits.TON=1; 
}

