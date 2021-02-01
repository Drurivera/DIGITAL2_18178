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
#define LED_G1 PORTAbits.RA0 
#define LED_G2 PORTAbits.RA1

//*******************************************************************************
// Variables
//*******************************************************************************
unsigned char counter_J1 = 0;
unsigned char counter_J2 = 0;
unsigned char antirebote_J1 = 0;
unsigned char antirebote_J2 = 0;
unsigned char debounce = 0;
unsigned char counter = 0;
unsigned char led_d = 0;
unsigned char led_g = 0;
unsigned char res = 0;

//*******************************************************************************
// Prototipos de funciones
//*******************************************************************************
void setup(void);
void semaforo(void);
void Contador_1(void);
void LED(void) ;

//*******************************************************************************
// Ciclo principal
//*******************************************************************************

void main(void) {

    setup();

    //*******************************************************************************
    // Loop principal
    //*******************************************************************************
    while (1) {

        if (PORTBbits.RB0 == 0) {
            while (PORTBbits.RB0 == 0) {
                LED_r = 1;
            }
            if (PORTBbits.RB0 == 1) {
                semaforo();
            }
        }
    }
}

//*******************************************************************************
// Configuración
//*******************************************************************************

void setup(void) {
    ANSEL = 0;
    ANSELH = 0;
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

//*******************************************************************************
// Funciones
//*******************************************************************************

void semaforo(void) {
    LED_r = 1;
    PORTA = 0;
    __delay_ms(700);
    LED_r = 0;
    LED_a = 1;
    __delay_ms(600);
    LED_a = 0;
    LED_v = 1;
    __delay_ms(500);
    LED_v = 0;
    res=0;
    Contador_1();
}

void Contador_1(void) {
    while (res==0) {
        if (PORTBbits.RB1 == 0) {
            while (PORTBbits.RB1 == 0) {
                debounce = 0;
            }

            if (PORTBbits.RB1 == 1) {
                counter_J1 = counter_J1 + 1;
                counter = counter_J1;
                LED();
                PORTC = led_d;
                if(led_g==1){
                    LED_G1=1;
                    res=1;
                    counter_J1=0;
                    counter_J2=0;
                    led_g =0;
                }
            }
        }
        if (PORTBbits.RB2 == 0) {
            while (PORTBbits.RB2 == 0) {
                debounce = 0;
            }

            if (PORTBbits.RB2 == 1) {
                counter_J2 = counter_J2 + 1;
                counter = counter_J2;
                LED();
                PORTD = led_d;
                if(led_g==1){
                    LED_G2=1;
                    res=1;
                    counter_J2=0;
                    counter_J1=0;
                    led_g =0;
                }
            }
        }
    }
        PORTD = 0;
        PORTC = 0;
}

void LED(void) {
    if (counter == 0) {
        led_d = 0b00000000;
    }
    if (counter == 1) {
        led_d = 0b00000001;
    }
    if (counter == 2) {
        led_d = 0b00000010;
    }
    if (counter == 3) {
        led_d = 0b00000100;
    }
    if (counter == 4) {
        led_d = 0b00001000;
    }
    if (counter == 5) {
        led_d = 0b00010000;
    }
    if (counter == 6) {
        led_d = 0b00100000;
    }
    if (counter == 7) {
        led_d = 0b01000000;
    }
    if (counter == 8) {
        led_d = 0b10000000;
    }
    if (counter == 9) {
        led_d = 0b00000000;
        led_g = 1;
    }

}