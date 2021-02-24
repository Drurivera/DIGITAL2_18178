/*
 * File:   SPI.c
 * Author: HP
 *
 * Created on February 23, 2021, 8:38 PM
 */


#include <xc.h>

void SPIInicio(void) {
    SSPCONbits.SSPOV = 1
    
}

void SPIMaster(void) {
    PORTD = 0;
}
void SPISlave(void) {
    PORTD = 0;
}