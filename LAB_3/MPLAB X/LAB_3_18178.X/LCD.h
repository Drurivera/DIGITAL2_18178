/*
 *File: LCD.h
 * Se tomo y se adaptaron las librerias de Ligo George
 * de la pagina www.electrosome.com
 * Pagina: https://electrosome.com/lcd-pic-mplab-xc8/
 

 */
#ifndef LCD_H
#define LCD_H
#endif


#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000

#ifndef RS
#define RS PORTAbits.RA0
#endif

#ifndef RW
#define RW PORTAbits.RA1
#endif

#ifndef EN
#define EN PORTAbits.RA2
#endif

#ifndef D0
#define D0 PORTDbits.RD0
#endif

#ifndef D1
#define D1 PORTDbits.RD1
#endif

#ifndef D2
#define D2 PORTDbits.RD2
#endif

#ifndef D3
#define D3 PORTDbits.RD3
#endif

#ifndef D4
#define D4 PORTDbits.RD4
#endif

#ifndef D5
#define D5 PORTDbits.RD5
#endif

#ifndef D6
#define D6 PORTDbits.RD6
#endif

#ifndef D7
#define D7 PORTDbits.RD7
#endif


#include <xc.h>

void Lcd_Port (char a);
void Lcd_Cmd (char a);
void Lcd_Clear (char a);
void Lcd_Set_Cursor (char a, char b);
void Lcd_Init (void);
void Lcd_Write_Char (char a);
void Lcd_Write_String (char *a);
void Lcd_Shift_Right (void);
void Lcd_Shift_Left (void);
#endif




