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
#include "eusart.h"

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


#define RS PORTCbits.RC3   //definicion para definir si es comando o dato.
#define RW PORTCbits.RC4   //definicion para definir si leera o escribira en la LCD.
#define EN PORTCbits.RC5   // habilita el funcionamiento de la LCD.
#define LCD PORTB          //habilita los puertos para el display.

//**********
// Interrupciones
//**********


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
    TRISC = 0b10000000;
    TRISE = 0;
    
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    
    PIE1bits.RCIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    PIR1bits.RCIF = 0;
    PIR1bits.TXIF = 0;
    SPBRGH = 0;
    SPBRG = 25; //
    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
    BAUDCTLbits.BRG16 = 0;
    OSCCONbits.IRCF = 0b110; //8Mhz
    OSCCONbits.OSTS= 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1; 
}
