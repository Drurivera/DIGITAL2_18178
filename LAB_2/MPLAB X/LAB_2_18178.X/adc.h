/* 
 * File: Oscilador.h  
 * Author: Jorge Hurtado
 * Comments: .h File to config. Oscilator.
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void conversion(int channel);

#endif	/* OSCILADOR_H */