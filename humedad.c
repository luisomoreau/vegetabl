/*
 * File:   humedad.c
 * Author: beatriztorreiromosquera
 *
 * Created on November 21, 2015, 10:32 AM
 */


#include "xc.h"
#include "humedad.h"
#include "led.h"
#include "ConversorAD.h"

void humedad(int dato)
{
    if(dato<102){
        ApagaLed(15);
        ApagaLed(14);
        ApagaLed(13);
        ApagaLed(12);
        ApagaLed(11);  
    }
    if(dato>=102 && dato<204){
        EnciendeLed(15);
        ApagaLed(14);
        ApagaLed(13);
        ApagaLed(12);
        ApagaLed(11);
    }
     if(dato>=204 && dato<306){
        EnciendeLed(15);
        EnciendeLed(14);
        ApagaLed(13);
        ApagaLed(12);
        ApagaLed(11);
    }
    if(dato>=306 && dato<408){
        EnciendeLed(15);
        EnciendeLed(14);
        EnciendeLed(13);
        ApagaLed(12);
        ApagaLed(11);
    }
    if(dato>=408 && dato<=512){
        EnciendeLed(15);
        EnciendeLed(14);
        EnciendeLed(13);
        EnciendeLed(12);
        ApagaLed(11);
    }
    if(dato>0x0200){
        EnciendeLed(15);
        EnciendeLed(14);
        EnciendeLed(13);
        EnciendeLed(12);
        EnciendeLed(11);
    }
}


