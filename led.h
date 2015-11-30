/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _LED_H
#define	_LED_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define FCY 39613750

void EnciendeLed(int pos);
void ApagaLed(int pos);
#endif

