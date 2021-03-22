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
uint8_t lr=0b00000000;

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
#define _XTAL_FREQ 4000000




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
        TXREG=minute;
        __delay_ms(40);
        PORTD=lr;


    }
}

//**************************
// Configuracion
//**************************

void setup(void) {
    TRISD = 0b00000000;
    TRISC = 0b11011000;
    TRISE = 0b00000000;
    PORTA = 0b00000000;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    OSCCONbits.IRCF = 0b110; //4Mhz
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIR1bits.RCIF = 0;
    BAUDCTLbits.BRG16 = 0; //9600
    SPBRGH = 0;
    SPBRG = 0b00011001;
    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
    I2C_Master_Init(100000);
    second = 36;
    minute = 30;
    hour = 6;
    m_day = 23;
    month = 7;
    year = 99;
}

void __interrupt() ISR(void) {
    if(PIR1bits.RCIF==1){
        PIR1bits.RCIF=0;
        lr = RCREG;
        return;
    }  
 }

