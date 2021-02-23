/* 
 * File:   Template Digital 2
 * Author: Mariandree Rivera 18178
 * 
 * Libreria para ADC
 * 
 * Created on 2021
 */
//Iniciar Condiciones para generar la Interrupcion
#define _XTAL_FREQ 8000000

#include "adc.h"
#include <pic16f887.h>

void ADCInicio(int channel){
    INTCONbits.GIE = 1; //habilitacion de las interrupciones.
    INTCONbits.PEIE = 1; //habilitacion del las interrupciones del ADC.
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;// para el inicio colocamos la bandera del ADC en 0.
    ADCON0=0b01000000;//Fosc/8 Seleccionado. Usaremos el puerto AN0.
    ADCON1=0b00000000;//derecha justificada.
    ADCON0bits.CHS= channel;
    PIR1bits.ADIF = 0;//limpiamos la bandera del ADC
    
}
