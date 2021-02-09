#include "adc.h"
#include <pic16f887.h>

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



void convertor(int channel){
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;//Bandera del ADC
    ADCON0=0b01000000;//Fosc/8 Selected. Channel AN0 is set as default.GoDone
    //Cleared. ADC Enable Bit set to 0 waiting further instructions.
    ADCON1=0b00000000;//Right Justified default. Voltage ref. Vdd et Vss.
    ADCON0bits.CHS= channel;
    PIR1bits.ADIF = 0;//Bandera del ADC
    
}