#include "adc.h"
#include <pic16f887.h>

/* 
 * Author: Mariandree Rivera 18178
 * 
 * Libreria para ADC
 * 
 * Created on 2021
 */
//**************************
// Palabra de configuracion
//**************************
#define _XTAL_FREQ 4000000
#include <stdio.h>
#include <stdlib.h>
#include <pic16f887.h>

#include <xc.h>
#include "LCD.h"
#include "adc.h"
#include "eusart.h"
#include <stdint.h>
#include <string.h>
#define _XTAL_FREQ 4000000

//**************************
// Variables
//**************************
float voltage;
uint8_t ADC1SL1 = 0;
uint8_t SL2 = 0;
uint8_t ADC1SL3 = 0;
int DC1;
char POT_A;
char POT_B;
char POT_C;
char POTADC_A[5];
char POTADC_B[5];
char POTADC_C[5];
char PUN[5];
int DC1;
int ADC1_A;

int ADCA;
char ADCACHARA[5];
char ADCBCHARB[5];
char ADCCCHARC[5];
char POINTERA[5];
uint8_t analogic_digital_a;
float voltageb;
int DC2;
int ADC2_A;
int ADC2_B;
int ADCB;
char ADCAACHARA[5];
char ADCABCHARB[5];
char ADCACCHARC[5];
char POINTERB[5];
int PI;
int plc;
char TERMINAL[5];
int rX;
int rXc;
//**************************
// Funciones
//**************************

void PC(int n) {
    plc = n;
    PI = (plc)*1;
    itoa(TERMINAL, PI, 10); //transformacion a volverlo char.
}

void __interrupt() ISR(void) {
    if (PIR1bits.RCIF == 1) {
        PORTAbits.RA5;
        rX = RCREG;
        if (rX == '+') {
            rXc = rXc + 1;
            return;
        }
        if (rX == '-') {
            rXc = rXc - 1;
            return;
        }
        PIR1bits.RCIF = 0;
        return;
    }


}

void ADC(void) {
    PIE1bits.RCIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    PIR1bits.RCIF = 0;
    PIR1bits.TXIF = 0;
    rXc = 0;
    while (1) {
        ADCON0bits.ADCS = 01;
        ADCON0bits.ADON = 1; // adc on
        ADCON1bits.ADFM = 0;
        ADCON1bits.VCFG0 = 0;
        ADCON1bits.VCFG1 = 0;
        SPBRGH = 0;
        SPBRG = 25; //
        TXSTA = 0b00100100;
        RCSTA = 0b10010000;
        LCD_msg("SL1    SL2    SL3"); //despliega la primera linea para titulos.
        while (1) {
            __delay_ms(1);
            ADCON0bits.CHS = 0000; //salida analogica A0.
            ADCON0bits.ADON = 1; //toma el valor analogico que sale del ADC.
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO); //espera mientras que terminar de hacer la transmision
            ADC1SL1 = ADRESH; //copiar el valor a la variable.
            voltage = (ADC1SL1 * 5.0) / 255.0; // hace el mapeo del valor del potenciometro
            DC1 = (voltage)*100; //lo multiplica por 100 para hacer el entero.
            POT_A = DC1 % 10; //guarda el valor en la posicion 1.
            itoa(ADCACHARA, POT_A, 10); //esto hace la transformacion a char.
            POT_B = (DC1 / 10) % 10; //guarda el valor en la posicion 2.
            itoa(ADCBCHARB, POT_B, 10); //esto hace la transformacion a char.
            POT_C = (DC1 / 100) % 10; //guarda el valor en la posicion 3.
            itoa(ADCCCHARC, POT_C, 10); //esto hace la transformacion a char.
            strcat(ADCBCHARB, ADCACHARA); //se empieza la concatenacion de los valores 
            strcpy(POINTERA, ".");
            strcat(POINTERA, ADCBCHARB);
            strcat(ADCCCHARC, POINTERA); //se finaliza la contanecion de los valores y lo guarda en una variable.

            LCD_cmd(0xC0); // BAJAR A SEGUNDA LINEA
            LCD_msg( ); // potencimetro del SL1.
            LCD_msg("V "); // VOLTAJE Y ESPACIO PARA LA IMPRESION
            LCD_msg(SL2); // Contador del SL2.
            LCD_msg(" "); //
            LCD_msg(ADC1SL3); // Temperatura del SL3.
            LCD_msg("C ");  // CELCIUS Y ESPACIO PARA LA IMPRESION


        }
    }
    return;
}