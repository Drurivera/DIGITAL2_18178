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
// Importacion de librerias y variables
//**************************
#include <xc.h>
#include <stdint.h>
#include "pic16f887.h"
#include "LCD.h"
#include "eusart.h"
#include "SPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*La inicializacion de la LCD se tomo de este video: https://www.youtube.com/watch?v=ve1PcD6Cegw&feature=youtu.be*/
uint8_t SSb1 = 0;
uint8_t ADC1SL1 = 0;
uint8_t SL2 = 0;
uint8_t ADC1SL3 = 0;
char PSL1 [5];
char PSL2 [5];
char PSL3 [5];

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


#define RS PORTCbits.RC0  //definicion para definir si es comando o dato.
#define RW PORTCbits.RC1   //definicion para definir si leera o escribira en la LCD.
#define EN PORTCbits.RC2   // habilita el funcionamiento de la LCD.
#define LCD PORTD          //habilita los puertos para el display.


//**************************
// Prototipos de funciones
//**************************
void setup(void);

void main(void) {

    setup();
    SPIMaster();
    UART_INIT(9600);
    inicio();
    //**************************
    // Loop principal
    //**************************
    LCD_msg("S1     S2     S3"); //despliega la primera linea para titulos.
    while (1) {


        //COMANDO PARA LECTURA DE DATO SPI
        PORTAbits.RA0 = 1; 
        PORTAbits.RA1 = 1; 
        PORTAbits.RA2 = 1; 
        if (SSb1 == 1) {
            PORTAbits.RA0 = 0;
            __delay_ms(1);
            spiWrite(1);
            ADC1SL1 = spiRead();
            ADC1SL1 = (ADC1SL1 * 500) / 255;
            PORTAbits.RA0 = 1; // Pin de Slave Select
            __delay_ms(100);
            SSb1 = 2;
            PORTB=1;
        }
        if (SSb1 == 2) {
            PORTAbits.RA1 = 0;
            __delay_ms(1);
            spiWrite(1);
            SL2 = spiRead();
            PORTAbits.RA1 = 1; // Pin de Slave Select
            __delay_ms(100);
            SSb1 = 3;
            PORTB=2;
        }
        if (SSb1 == 3) {
            PORTAbits.RA2 = 0;
            __delay_ms(1);
            spiWrite(1);
            ADC1SL3 = spiRead();
            ADC1SL3 = (ADC1SL3 * 125) / 250;
            
            PORTAbits.RA2 = 1; // Pin de Slave Select
            __delay_ms(100);
            SSb1 = 1;
        }
        LCD_cmd(0xC0);
        // BAJAR A SEGUNDA LINEA
        sprintf(PSL1, "%.3i", ADC1SL1);
         LCD_msg(PSL1);
         LCD_msg(" V ");
        sprintf(PSL2, "%.3i", SL2);
         LCD_msg(PSL2);
         LCD_msg("   ");
        sprintf(PSL3, "%.3i", ADC1SL3);
         LCD_msg(PSL3);
         LCD_msg("C ");
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
    TRISC = 0b10010000;
    TRISE = 0;
    SSb1 = 1;
    PORTA = 0b00000000;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;

    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    PIR1bits.SSPIF = 0;
    PIE1bits.SSPIE = 1;
    PIR1bits.TXIF = 0;
    SPBRGH = 0;
    SPBRG = 25; //
    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
    BAUDCTLbits.BRG16 = 0;
    OSCCONbits.IRCF = 0b110; //8Mhz
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;





}
