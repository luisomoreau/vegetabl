#ifndef _TEMPERATURA_H 
#define	_TEMPERATURA_H

#include <xc.h> // include processor files - each processor file is guarded.

#define FCY 39613750

void read_DHT11(int n_pin,double* valores);
void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void);
void temperatura(double* valores);

#endif
