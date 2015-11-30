/*
 * File:   led.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 14, 2015, 10:45 AM
 */


#include "xc.h"
#include "led.h"
void EnciendeLed(int pos)
{
    PORTB &= ~(1<<pos);
}
void ApagaLed(int pos)
 {
    PORTB |= (1<<pos); 
 }
