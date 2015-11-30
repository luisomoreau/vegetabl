/*
 * File:   luminosidad.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 26, 2015, 12:59 PM
 */

#include "xc.h"
#include "humedad.h"
#include "led.h"
#include "ConversorAD.h"

void luminosidad(int dato)
{
    if(dato<150){
        ApagaLed(10);
        ApagaLed(9);
        ApagaLed(8);
        ApagaLed(7);
        ApagaLed(6);  
    }
    if(dato>=150 && dato<200){
        EnciendeLed(10);
        ApagaLed(9);
        ApagaLed(8);
        ApagaLed(7);
        ApagaLed(6);
    }
     if(dato>=200 && dato<300){
        EnciendeLed(10);
        EnciendeLed(9);
        ApagaLed(8);
        ApagaLed(7);
        ApagaLed(6);
    }
    if(dato>=300 && dato<700){
        EnciendeLed(10);
        EnciendeLed(9);
        EnciendeLed(8);
        ApagaLed(7);
        ApagaLed(6);
    }
    if(dato>=700 && dato<=900){
        EnciendeLed(10);
        EnciendeLed(9);
        EnciendeLed(8);
        EnciendeLed(7);
        ApagaLed(6);
    }
    if(dato>900){
        EnciendeLed(10);
        EnciendeLed(9);
        EnciendeLed(8);
        EnciendeLed(7);
        EnciendeLed(6);
    }
}
