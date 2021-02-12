/*******************************************************************************
 * File:   mainTemplate.c
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Archivo template 
 * 
 * Created on February 07, 2021,
/*******************************************************************************
*/
//**************************
// Importacion de librerias
//**************************
#include <xc.h>
#include <stdint.h>
#include "adc.h"

//**************************
// Palabra de configuracion
//**************************

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
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
// Variables
//**************************

char x = 0;
char y = 0;
uint8_t arc = 0;
char tog = 0;
int leds = 0;
char AR1=0;
char AR2=0;

uint8_t seg7[] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b01110111,
    0b01111100,
    0b00111001,
    0b01011110,
    0b01111001,
    0b01110001 };

//**************************
// Prototipos de funciones
//**************************
void setup(void);
void convertor(int );
void __interrupt() ISR() ;
void toggle (void);
void pushs (void); 
//**************************
// Ciclo principal
//**************************

void main(void) {

    setup();

    //**************************
    // Loop principal
    //**************************
    while (1) {
        convertor(8);
        ADCON0bits.ADON = 1;
        __delay_ms(15);
        ADCON0bits.GO_DONE = 1;
        while (ADCON0bits.GO_DONE == 1);
        if (tog == 0) {
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 0;
            PORTD = seg7[y];
           
        }
        if (tog == 1) {
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 1;
            PORTD = seg7[x];
            
        }
        if (arc>=leds){
            PORTAbits.RA2 =1;
        }
       if  (arc<=leds){
         PORTAbits.RA2 =0;
       }
    }
}
//**************************
// Configuracion
//**************************

void setup(void) {
    INTCON  = 0b11101000; //GIE,PEIE, TMR0,RBIE ACTIVOS.
    PIE1    = 0b01000000; //ADIE ACTIVO.
    //habilita los  bits de IOC del Puerto B en RB0 y RB1 para los PushButton.
    IOCB    = 0b00000011;
    //Configuracion de Puertos y limpieza de los mismos.
        //timer 0 configuration bits
    OPTION_REG  =0b11000110;  
    ANSEL = 0;
    ANSELH = 0b00000001;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b00000111;
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
    if (PIR1bits.ADIF == 1) {
        arc = ADRESH;
        y = arc ;
        x = arc  & 0x0F;
        y = ((arc & 0xF0) >> 4);
        PIR1bits.ADIF = 0;
        return;
    }   
     if (TMR0IF == 1 ){   // interrupcion del TIMER 0 que manda a colocar el valor del contador en el puerto A 
        toggle ();       // y a multiplexar los displays 
        TMR0IF = 0;
        TMR0 = 173;
        return;
    }
    //if ()
}
void toggle (void){
    if (tog == 1){
        tog = 0;
        return;
    }
    if (tog== 0){
        tog = 1;
        return;
    }
}

void pushs (void){
    if(PORTBbits.RB0==1){
        AR1=1;
        di();
    }
    if(PORTBbits.RB0==0 && AR1==1){
        AR1=0;
        PORTC=PORTC+1;
        ei();
        return;
    }
    if(PORTBbits.RB1==1){
        AR2=1;
        di();
    }
    if(PORTBbits.RB1==0 && AR2==1){
        AR2=0;
        PORTC=PORTC-1;
        ei();
        return;
    }
}