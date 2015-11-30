#ifndef _INTERRUPCIONES_H 
#define	_INTERRUPCIONES_H

#include <xc.h> // include processor files - each processor file is guarded.

#define FCY 39613750

void init_T1(void);
//void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void);

#endif
