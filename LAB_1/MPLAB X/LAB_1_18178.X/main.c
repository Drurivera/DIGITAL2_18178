/*******************************************************************************
 * File:   mainTemplate.c
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Archivo template 
 * 
 * Created on January 25, 2021,
 /*******************************************************************************
*/
 //*******************************************************************************
// Importación de librerías
 //*******************************************************************************

#include <xc.h>

//*******************************************************************************
// Palabra de configuración
//*******************************************************************************

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

#define LED_r PORTEbits.RE0
#define LED_a PORTEbits.RE1
#define LED_v PORTEbits.RE2

//*******************************************************************************
// Variables
//*******************************************************************************

char counter_J1 = 0;
char counter_J2 = 0;

//*******************************************************************************
// Prototipos de funciones
//*******************************************************************************
void setup(void);
void semaforo(void);

//*******************************************************************************
// Ciclo principal
//*******************************************************************************

void main(void) {

    setup();

//*******************************************************************************
    // Loop principal
//*******************************************************************************

    while (1) {
        if (PORTBbits.RB0 == 0)
            semaforo();

    }
}

//*******************************************************************************
// Configuración
//*******************************************************************************

void setup(void) {
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0;
    PORTA= 0;
    TRISB = 0b00000111;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
}

//*******************************************************************************
// Funciones
//*******************************************************************************

void semaforo(void) {
    LED_r = 1;
    __delay_ms(700);
    LED_r = 0;
    LED_a = 1;
    __delay_ms(750);
    LED_a = 0;
    LED_v = 1;
    __delay_ms(600);
    LED_v = 0;
}