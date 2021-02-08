//Jorge Rafael Hurtado Garcia
//18052
//Oscilador.c
//Funcion Para seleccionar la Frecuencia del oscilador Interno del Pic.

#include "oscilador.h"

void initosc(uint8_t IRCF){
    
    switch(IRCF){
        case 0: //31 kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 0;
            break;
                    
        case 1: //125 kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 1;
            break;
        case 2: //250 kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
        case 3: //500kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 1;
            break;
        case 4: //1MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 0;
            break;    
        case 5: //2MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 1;
            break;
        case 6: //4MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
        case 7: //8MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 1;
            break;
        default:
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
    }
    OSCCONbits.SCS = 1;//System clock select internal oscilator
}
