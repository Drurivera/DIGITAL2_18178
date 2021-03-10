/*******************************************************************************
 * File:   mainTemplate.c
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Archivo template 
 * 
 * Created on March 1, 2021
/*******************************************************************************
 */
//**************************
// Importacion de librerias y variables
//**************************
#include <xc.h>
#include <stdint.h>
#include "pic16f887.h"
#include "I2C.h" 
#include "eusart.h"
#include "RTC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t i;
uint8_t second;
uint8_t minute;
uint8_t hour;
uint8_t m_day;
uint8_t month;
uint8_t year;
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
#define _XTAL_FREQ 8000000




//**************************
// Prototipos de funciones
//**************************
void setup(void);

void main(void) {
    setup();
    I2C_Master_Init(100000);
    S_RTC(second, minute, hour, m_day, month, year);

    //**************************
    // Loop principal
    //**************************
    while (1) {
        //PORTDbits.RD1  =1;
        //PORTD = second;
        R_RTC();


    }
}

//**************************
// Configuracion
//**************************

void setup(void) {
    //ARREGLAR PINOUT
    ANSEL = 0b00000000;
    ANSELH = 0b00000000;

    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISD = 0b00000000;
    TRISC = 0b00000000;
    TRISE = 0b00000000;

    PORTA = 0b00000000;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;

    //    SPBRGH = 0;
    //    SPBRG = 25; //
    //    TXSTA = 0b00100100;
    //    RCSTA = 0b10010000;
    //    BAUDCTLbits.BRG16 = 0;

    OSCCONbits.IRCF = 0b111; //8Mhz
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;

    uint8_t second = 46;
    uint8_t minute = 30;
    uint8_t hour = 6;
    uint8_t m_day = 23;
    uint8_t month = 7;
    uint8_t year = 99;
}
