/*******************************************************************************
 * File:   oscilador.h
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Comments: .h File to config. Oscilator.
 * 
 * Created on February 07, 2021,
/*******************************************************************************
*/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef OSCILADOR_H
#define	OSCILADOR_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

//iniosc
//Inicializacion de oscilador interno
//Tiene parametro la opcion del IRCF pag 62 del manual del pic
void initosc(uint8_t IRCF);


#endif	/* OSCILADOR_H */
