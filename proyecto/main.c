
#include <xc.h> 
#include "config.h"
#include "led.h"
#include "ConversorAD.h"
#include "humedad.h"
#include "luminosidad.h"
#include "temperatura.h"
#include "interrupciones.h"

int main(void)
{
	InicializarReloj();
	AD1PCFGL = 0xFFDF; // Configura AN5 como analógico y el resto como digital
	
    int datos[2];
    double temperaturas[40];
	PORTB = 0xFFFF; 
	TRISB = 0x003F; 
    
	init_ad(3,2);
    init_T1();
    
	while(1){ 
        get_ad(2,datos);
        humedad(datos[0]);
        luminosidad(datos[1]);
        read_DHT11(3,temperaturas);
        temperatura(temperaturas);
        
	}
}

