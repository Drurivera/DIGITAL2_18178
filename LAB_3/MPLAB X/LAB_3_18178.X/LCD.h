/*
 *File: LCD.h
 * Se tomo y se adaptaron las librerias de Ligo George
 * de la pagina www.electrosome.com
 * Pagina: https://electrosome.com/lcd-pic-mplab-xc8/
 

 */
#ifndef LCD_H
#define LCD_H
#endif

#ifndef RS
#define RS PORTCbits.RC3
#endif

#ifndef RW
#define RW PORTCbits.RC4
#endif

#ifndef EN
#define EN PORTCbits.RC5
#endif

#ifndef LCD
#define  LCD PORTB
#endif

#include <xc.h>

void LCD_cmd(unsigned char x);
void LCD_dwr(unsigned char x);
void LCD_msg(unsigned char *c);
void LCD_ready(void);
void LCD_lat(void);
void inicio(void);


