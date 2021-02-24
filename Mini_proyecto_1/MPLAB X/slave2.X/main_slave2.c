/*******************************************************************************
 * File:   mainTemplate.c
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Archivo template 
 * 
 * Created on February 15, 2021
/*******************************************************************************
*/
//**************************
// Importacion de librerias
//**************************
// IMPORTACION DE LIBRERIAS PROPIAS DE MPLABX.
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// IMPORTACION DE LIBRERIAS PROPIAS DE FUNCIONES.
#include "pic16f887.h"
#include "adc.h"

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


char SL2 = 0;
char AUM=0;
char DEC=0;

//**************************
// Prototipos de funciones
//**************************
void setup(void);
void ADCInicio(int );
void __interrupt() ISR() ;
void pushs (void);

//**************************
// Ciclo principal
//**************************

void main(void){

    setup ();
    //**************************
    // Loop principal
    //**************************
    while (1) {
        PORTD = SL2;
}
}
//**************************
// Configuracion
//**************************

void setup(void) {
    INTCON  = 0b11101000; //GIE,PEIE, TMR0,RBIE ACTIVOS.
    PIE1    = 0b01000000; //ADIE ACTIVO.
    //habilita los  bits de IOC del Puerto B en RB0 y RB1 para los PushButton.
    IOCB    = 0b00000011; //Configuracion de Puertos y limpieza de los mismos.
        //timer 0 configuration bits
   
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b00000011;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
    
}
//**********
// Interrupciones
//**********

void __interrupt() ISR() {

    if (INTCONbits.RBIF == 1){
        INTCONbits.RBIF = 0;
        di();
        pushs();
        return;
    }
}
void pushs (void){
    if(PORTBbits.RB0==1){
        AUM=1;
        di();
    }
    if(PORTBbits.RB0==0 && AUM==1){
        AUM=0;
        SL2=SL2+1;
        ei();
        return;
    }
    if(PORTBbits.RB1==1){
        DEC=1;
        di();
    }
    if(PORTBbits.RB1==0 && DEC==1){
        DEC=0;
        SL2=SL2-1;
        ei();
        return;
    }
}