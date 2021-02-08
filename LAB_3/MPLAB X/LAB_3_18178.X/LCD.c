/*
 *File: LCD.c
 * Se tomo y se adaptaron las librerias de Ligo George
 * de la pagina www.electrosome.com
 * Pagina: https://electrosome.com/lcd-pic-mplab-xc8/
 */


#include "LCD.h"

void Lcd_Port(char a) {
    if (a & 1)
        D4 = 1;
    return;
}

void Lcd_Cmd(char a) {
    RS = 0;
    Lcd_Port (a);
    EN = 1;
    __delay_ms(4);
    EN = 0;
}

void Lcd_Clear(void) {
    Lcd_Cmd(0);
    
}

void Lcd_Init(void) {
    Lcd_Port(0x00);
    __delay_ms(30);
    Lcd_Cmd (0x30);
    __delay_ms(6);
    Lcd_Cmd (0x30);
    __delay_ms(15);
    Lcd_Cmd (0x30);
    //////////////////////////////////////////////////////////////////////////
    
    
    
    
    
    
}