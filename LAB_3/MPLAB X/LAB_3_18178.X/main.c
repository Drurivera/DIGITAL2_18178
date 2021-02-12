/*******************************************************************************
 * File:   mainTemplate.c
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Archivo template 
 * 
 * Created on February 08, 2021,
/*******************************************************************************
*/
//**************************
// Importacion de librerias
//**************************
#include <xc.h>
#include <stdint.h>
#include "pic16f887.h"
#include "LCD.h"

#include "adc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*La inicializacion de la LCD se tomo de este video: https://www.youtube.com/watch?v=ve1PcD6Cegw&feature=youtu.be*/


//**************************
// Palabra de configuracion
//**************************

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

//**************************
// Variables
//**************************


#define RS PORTCbits.RC3
#define RW PORTCbits.RC4
#define EN PORTCbits.RC5
#define LCD PORTB

//**********
// Interrupciones
//**********

void __interrupt() ISR()
{
 //esto se activara si la interrupcion viene del receptor en el UART
    if (PIR1bits.RCIF == 1)
    {
        //esto nos limpiara la interrupcion
        PIR1bits.RCIF = 0;
        TXREG = (RCREG + 1);
        while (TXSTAbits.TRMT == 0);
        
    }
}
//**************************
// Prototipos de funciones
//**************************
void setup(void);

//**************************
// Ciclo principal
//**************************

void main(void){

    setup ();
    //**************************
    // Loop principal
    //**************************
    while (1) {
        inicio(); 
        ADC();
}
}

//**************************
// Configuracion
//**************************

void setup(void) {
 
    ANSEL = 0b00000011;
    ANSELH= 0b00000000;
    TRISA = 0b00000011;
    TRISB = 0b00000000; 
    TRISD = 0b00000000;
    TRISC = 0b00000000;
    TRISE = 0;
    
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    
    OSCCONbits.IRCF = 0b110; //8Mhz
    OSCCONbits.OSTS= 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1; 
}
