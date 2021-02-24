/* 
 * File: ADC.h  
 * Author: Mariandree Rivera 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#define	SPI_H
#define _XTAL_FREQ 8000000;

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <string.h>

void SPIMaster(void);
void SPISlave(void);
