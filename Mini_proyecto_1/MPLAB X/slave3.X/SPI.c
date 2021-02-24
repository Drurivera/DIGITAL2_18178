/*
 * File:   SPI.c
 * Author: Mariandree Rivera
 *
 * Created on February 23, 2021, 8:38 PM
 */


#include <xc.h>

void SPIMaster(void) {
    //CONFIGURACION PARA SPI DE SLAVE.
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 0;
    SSPCONbits.SSPEN = 1;
    SSPCONbits.CKP = 1;
    SSPCONbits.SSPM = 0b0010; 
    //CONFIGURACION DE LOS TRIS PARA LAS PUERTOS
    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC3 = 0;
    // ACTIVACION DE LAS INTERRUPCIONES
    PIE1bits.SSPIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    PIR1bits.SSPIF = 0;
}
void SPISlave(void) {
    //CONFIGURACION PARA SPI DE SLAVE.
     SSPSTATbits.SMP = 0;
     SSPSTATbits.CKE = 0;
     SSPCONbits.SSPEN = 1;
     SSPCONbits.CKP = 1;
     SSPCONbits.SSPM = 0b0100;
     //CONFIGURACION DE LOS TRIS PARA LAS PUERTOS
     TRISCbits.TRISC5 = 0;
     TRISCbits.TRISC3 = 1;
     TRISAbits.TRISA5 = 1;
     // ACTIVACION DE LAS INTERRUPCIONES DE SPI
     PIE1bits.SSPIE = 1;
     INTCONbits.PEIE = 1;
     INTCONbits.GIE = 1;
     PIR1bits.SSPIF = 0;
}
