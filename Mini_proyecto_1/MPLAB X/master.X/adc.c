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
int DC1;
int ADC1_A;
int ADC1_B;
int ADCA;
char ADCACHARA[5];
char ADCBCHARB[5];
char ADCCCHARC[5];
char POINTERA[5];
uint8_t analogic_digital_a;
float voltageb;
uint8_t analogic_digital_b;
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
        LCD_msg("S1     S2     S3"); //despliega la primera linea para titulos.
        while (1) {
            __delay_ms(1);
            ADCON0bits.CHS = 0000; //salida analogica A0.
            ADCON0bits.ADON = 1; //toma el valor analogico que sale del ADC.
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO); //espera mientras que terminar de hacer la transmision
            analogic_digital_a = ADRESH; //copiar el valor a la variable.
            voltage = (analogic_digital_a * 5.0) / 255.0; // hace el mapeo del valor del potenciometro
            DC1 = (voltage)*100; //lo multiplica por 100 para hacer el entero.
            ADC1_A = DC1 % 10; //guarda el valor en la posicion 1.
            itoa(ADCACHARA, ADC1_A, 10); //esto hace la transformacion a char.
            ADC1_B = (DC1 / 10) % 10; //guarda el valor en la posicion 2.
            itoa(ADCBCHARB, ADC1_B, 10); //esto hace la transformacion a char.
            ADCA = (DC1 / 100) % 10; //guarda el valor en la posicion 3.
            itoa(ADCCCHARC, ADCA, 10); //esto hace la transformacion a char.
            strcat(ADCBCHARB, ADCACHARA); //se empieza la concatenacion de los valores 
            strcpy(POINTERA, ".");
            strcat(POINTERA, ADCBCHARB);
            strcat(ADCCCHARC, POINTERA); //se finaliza la contanecion de los valores y lo guarda en una variable.


            __delay_us(600);
            ADCON0bits.CHS = 0001; //salida analogica A0.
            ADCON0bits.ADON = 1; //toma el valor analogico que sale del ADC.
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            analogic_digital_b = ADRESH;
            voltageb = analogic_digital_b * 5.0 / 255.0; // hace el mapeo del valor del potenciometro
            DC2 = (voltageb)*100;
            ADC2_A = DC2 % 10;
            itoa(ADCAACHARA, ADC2_A, 10); //transforma el valor int POT2A a char POT2SA
            ADC2_B = (DC2 / 10) % 10;
            itoa(ADCABCHARB, ADC2_B, 10); // transforma caracter a char
            ADCB = (DC2 / 100) % 10;
            itoa(ADCACCHARC, ADCB, 10);
            strcat(ADCABCHARB, ADCAACHARA); // concatena 
            strcpy(POINTERB, ".");
            strcat(POINTERB, ADCABCHARB);
            strcat(ADCACCHARC, POINTERB);
            sprintf(TERMINAL, "%.1i", rXc);


            LCD_cmd(0xC0); // BAJAR A SEGUNDA LINEA
            LCD_msg(ADCCCHARC); // DESPLIEGA EL CHAR
            LCD_msg("V "); // VOLTAJE Y ESPACIO PARA LA IMPRESION
            LCD_msg(ADCACCHARC); // SIGUIENTE VALOR
            LCD_msg("V "); // VOLTAJE Y ESPACIO PARA LA IMPRESION
            LCD_msg(TERMINAL); // EL OTRO VALOR

        }
    }
    return;
}