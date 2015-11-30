/*
 * File:   humedad.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 21, 2015, 10:32 AM
 */


#include "xc.h"
#include "agua.h"
#include "led.h"
#include "ConversorAD.h"

void da_agua(int pine, int millis){
    
    PORTB &= ~(1<<pine);
    PORTB |= (1<<pine); 
    
};


