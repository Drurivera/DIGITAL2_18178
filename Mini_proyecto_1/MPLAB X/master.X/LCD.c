/*
 * Se tomo y se adaptaron las librerias 
 * Pagina: https://electrosome.com/lcd-pic-mplab-xc8/
 * File:   LCD.c
 * Author: Mariandree Rivera
 *
 * Created on 11 de febrero de 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include "LCD.h"
#include<xc.h>
#define _XTAL_FREQ 4000000

void LCD_cmd(unsigned char x){ 
    LCD_ready();
    LCD = x;
    RS = 0;
    RW = 0;
    LCD_lat();    
}

void LCD_lat(void){
    EN = 1;
   __delay_ms(30);
   EN = 0;
}
void LCD_ready(void) { //esta funcion es la habilitacion del ADC.
    LCD = 0xFF;
    LCD &= 0x80;
    RS = 0;
    RW = 1;
    EN = 0;
    __delay_ms(30);
    EN = 1;
    if (LCD == 0x80){
        EN = 0;
        __delay_ms(30);
        EN = 1;  
    }

}
void LCD_dwr(unsigned char x){ 
    LCD_ready();
    LCD = x;
    RS = 1;
    RW = 0;
    LCD_lat(); 
}

void LCD_msg(unsigned char *c){  //transmision de los mensajes.
    while(*c != 0)
        LCD_dwr(*c++);
}

void inicio(void){   
    LCD_cmd(0x38);
    LCD_cmd(0x0C);
    LCD_cmd(0x01);
    LCD_cmd(0x06);
    LCD_cmd(0x80);  
}



