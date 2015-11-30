
#include <xc.h> 
#include "config.h"
#include "led.h"
#include "ConversorAD.h"
#include "humedad.h"
#include "luminosidad.h"
#include "interrupciones.h"
#include "temperatura.h"
#include "agua.h"

int main(void)
{
	InicializarReloj();
	AD1PCFGL = 0xFFDF; // Configura AN5 como analógico y el resto como digital
	
    int datos[3];
	PORTB = 0xFFFF; 
	TRISB = 0x003F; 

    
	init_ad(25,3);
    init_T1();
    
	while(1){ 
        get_ad(3,datos);
        //humedad(datos[0]);
        //luminosidad(datos[1]);
        //temperatura(datos[2]);
        
	}
}