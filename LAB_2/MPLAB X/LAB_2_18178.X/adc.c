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
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;//Bandera del ADC
    ADCON0=0b01000000;//Fosc/8 Seleccionado. Usaremos el puerto AN0.
    ADCON1=0b00000000;//derecha justificada.
    ADCON0bits.CHS= channel;
    PIR1bits.ADIF = 0;//Bandera del ADC
    
}