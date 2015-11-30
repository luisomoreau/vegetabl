/**
 * @file     config.c
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

// -----------------------------------------------------------------------------

#include <xc.h> // Como se usa el compilador XC16, con este include se añaden
                // automáticamente las definiciones de los puertos del micro.
#include "config.h"

// -----------------------------------------------------------------------------
// --------------------------- BITS DE CONFIGURACIÓN ---------------------------
// -----------------------------------------------------------------------------

// 1. Eliminar el segmento de arranque flash
// 2. Permitir la escritura del segmento de arranque flash
_FBS(BSS_NO_BOOT_CODE & BWRP_WRPROTECT_OFF);

// 1. No proteger la memoria de programa contra escritura
// 2. No proteger el código
_FGS(GWRP_OFF & GCP_OFF);

// 1. Utilizar el oscilador interno (FRC) en el arranque
// 2. Arrancar directamente con el oscilador seleccionado
_FOSCSEL(FNOSC_FRC & IESO_OFF);

// 1. Permitir la conmutación del reloj y deshabilitar el control de fallos
// 2. Desactivar el oscilador primario
// 3. Utilizar el oscilador secundario como entrada y salida digital
// 4. Permitir múltiples remapeos de los pines
_FOSC(FCKSM_CSECMD & POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF);

// 1. Deshabilitar el watchdog timer
_FWDT(FWDTEN_OFF);

// 1. Esperar 128 ms y resetear el microcontrolador al enchufar la alimentación
// 2. Utilizar los pines estándar (SDA1 y SCL1) para el I2C
_FPOR(FPWRT_PWR128 & ALTI2C_OFF);

// 1. Programar y depurar a través de los pines PGEC1 y PGED1
// 2. Desactivar el interfaz para JTAG
_FICD(ICS_PGD1 & JTAGEN_OFF);

// -----------------------------------------------------------------------------
// --------------------------------- FUNCIONES ---------------------------------
// -----------------------------------------------------------------------------

/**
 * Inicializa el reloj interno FRC con PLL.
 *
 * Configura la frecuencia del oscilador FRC (FOSC), cuya frecuencia nominal
 * (Fin) son 7.37 MHz, para que el microprocesador opere a 40 MIPS (FCY).
 * FOSC = Fin * M/(N1*N2)   FCY = FOSC/2
 * FOSC = 79.2275 MHz       FCY = 39.61375 MHz
 */

void InicializarReloj(void) {
    CLKDIVbits.PLLPRE  =  0;  // Preescalado del PLL:   N1 = 2
    PLLFBD             = 41;  // Multiplicador del PLL: M = PLLFBD + 2 = 43
    CLKDIVbits.PLLPOST =  0;  // Postescalado del PLL:  N2 = 2

    // Funciones para desbloquear la escritura del registro OSCCON
    __builtin_write_OSCCONH(0x01);           // Nuevo reloj: FRC w/ PLL
    __builtin_write_OSCCONL(OSCCON | 0x01);  // Iniciar el cambio de reloj

    while (OSCCONbits.COSC != 1);  // Esperar al cambio de reloj
    while (OSCCONbits.LOCK != 1);  // Esperar a que se sincronice el PLL
}
