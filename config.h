/**
 * @file     config.h
 *
 * @author   José Daniel Muñoz Frías, Jaime Boal Martín-Larrauri
 *
 * @version  1.0.0
 *
 * @date     17/09/2015
 *
 * @brief    Bits de configuración y funciones de inicialización del 
 *           microcontrolador.
 */

#ifndef _CONFIG_H
#define _CONFIG_H

// -----------------------------------------------------------------------------
// -------------------------------- PARÁMETROS ---------------------------------
// -----------------------------------------------------------------------------

/// Frecuencia de operación del microprocesador (Hz)
#define FCY 39613750

// -----------------------------------------------------------------------------
// ------------------- PROTOTIPOS DE LAS FUNCIONES PUBLICAS --------------------
// -----------------------------------------------------------------------------

/**
 * Inicializa el reloj interno FRC con PLL.
 *
 * Configura la frecuencia del oscilador FRC (FOSC), cuya frecuencia nominal
 * (Fin) son 7.37 MHz, para que el microprocesador opere a 40 MIPS (FCY).
 * FOSC = Fin * M/(N1*N2)   FCY = FOSC/2
 * FOSC = 79.2275 MHz       FCY = 39.61375 MHz
 */
void InicializarReloj(void);

#endif
