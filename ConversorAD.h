/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef _CONVERSORAD_H
#define	_CONVERSORAD_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define FCY 39613750

void init_ad(int pines, int n_pines );
void get_ad(int n_pines, int* valores);

#endif