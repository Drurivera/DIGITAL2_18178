/* 
 * File:   eusart.h
 * Author: Mariandree Rivera
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _UART_H
#define	_UART_H

//**************************

//Se define para poder utilizar la frecuencia de oscilación en el cálculo del Baud Rate

//**************************
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif

//**************************

//Prototipos de Funciones

//**************************
uint8_t UART_INIT(const long int baudrate);
uint8_t UART_READ(void);
void UART_Read_Text(char *Output, unsigned int length);
void UART_WRITE(char data);
void UART_Write_Text(char *text);

#endif	/* UART_H */
