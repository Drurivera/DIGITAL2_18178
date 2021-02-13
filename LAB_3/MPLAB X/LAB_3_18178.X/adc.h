/* 
 * File: Oscilador.h  
 * Author: Mariandree Rivera
 * Comments: .h File to config. Oscilator.
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H
#endif 

#define _XTAL_FREQ 4000000
#include <xc.h> // include processor files - each processor file is guarded.  

#include "LCD.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include processor files - each processor file is guarded.  
#define _XTAL_FREQ 4000000
void ADC(void); //llama la funcion del adc.
void PC (int n); //funcion del PC.
