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
#include <stdint.h>
#include <string.h>
#define _XTAL_FREQ 4000000

//**************************
// Variables
//**************************
float voltage;
int DC1;
int ADC_1_A;
int ADC_1_B;
int ADC_A;
char ADCA_CHARA[5];
char ADCB_CHARB[5];
char ADCC_CHARC[5];
char POINTERA[5];
uint8_t analogic_digital_a;
float voltageb;
uint8_t analogic_digital_b;
int DC2;
int ADC_2_A;
int ADC_2_B;
int ADC_B;
char ADCAA_CHARA[5];
char ADCAB_CHARB[5];
char ADCAC_CHARC[5];
char POINTERB[5];
int PI;
int plc;
char ARDUINO[5];
//**************************
// Funciones
//**************************
void PC(int  n){
    plc = n;
    PI = (plc)*1;
     itoa(ARDUINO,PI,10);
}

void ADC(void){
    while(1){
    ADCON0bits.ADCS = 01;
    ADCON0bits.ADON = 1;   // adc on
    ADCON1bits.ADFM = 0;
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG1 = 0;
    LCD_msg("S1     S2     S3");
    while(1){
        __delay_ms(1);
        ADCON0bits.CHS = 0000;
        ADCON0bits.ADON = 1;
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        analogic_digital_a = ADRESH;
        voltage = (analogic_digital_a*5.0)/255.0;
        DC1 = (voltage)*100;
        ADC_1_A = DC1%10;
        itoa(ADCA_CHARA,ADC_1_A,10);
        ADC_1_B = (DC1/10)%10;
        itoa(ADCB_CHARB,ADC_1_B,10);
        ADC_A = (DC1/100)%10;
        itoa(ADCC_CHARC,ADC_A,10);
        strcat(ADCB_CHARB,ADCA_CHARA);
        strcpy(POINTERA,".");
        strcat(POINTERA,ADCB_CHARB);
        strcat(ADCC_CHARC,POINTERA);
        
        
        __delay_us(600);
        ADCON0bits.CHS = 0001;
        ADCON0bits.ADON = 1;   // adc on
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        analogic_digital_b = ADRESH;
        voltageb = analogic_digital_b*5.0/255.0;
        DC2 = (voltageb)*100; 
        ADC_2_A = DC2%10;
        itoa(ADCAA_CHARA,ADC_2_A,10);       //transforma el valor int POT2A a char POT2SA
        ADC_2_B = (DC2/10)%10;          
        itoa(ADCAB_CHARB,ADC_2_B,10);
        ADC_B = (DC2/100)%10;
        itoa(ADCAC_CHARC,ADC_B,10);
        strcat(ADCAB_CHARB,ADCAA_CHARA);       // concatena 
        strcpy(POINTERB,".");         // transforma caracter a char
        strcat(POINTERB,ADCAB_CHARB);
        strcat(ADCAC_CHARC,POINTERB);
        
        
        LCD_cmd(0xC0);                  // BAJAR A SEGUNDA LINEA
        LCD_msg(ADCC_CHARC);             // DESPLIEGA EL CHAR
        LCD_msg("V ");                  // ESPACIO
        LCD_msg(ADCAC_CHARC);          // SIGUIENTE VALOR
        LCD_msg("V ");
        LCD_msg(ARDUINO);             // EL OTRO VALOR
       
    }
    }
    return;
}