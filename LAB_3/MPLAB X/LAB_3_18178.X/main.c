/*******************************************************************************
 * File:   mainTemplate.c
 * Author: Mariandree Rivera
 * Carnet: 18178
 * Archivo template 
 * 
 * Created on February 08, 2021,
/*******************************************************************************
*/
//**************************
// Importacion de librerias
//**************************
#include <xc.h>
#include <stdint.h>
#include "LCD.h"

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
#define RS PORTAbits.RA0
#define RW PORTAbits.RA1
#define EN PORTAbits.RA2
#define D0 PORTDbits.RD0
#define D1 PORTDbits.RD1
#define D2 PORTDbits.RD2
#define D3 PORTDbits.RD3
#define D4 PORTDbits.RD4
#define D5 PORTDbits.RD5
#define D6 PORTDbits.RD6
#define D7 PORTDbits.RD7

//**************************
// Variables
//**************************

char counter = 0;

//**********
// Interrupciones
//**********

void __interrupt() ISR()
{
 //esto se activara si la interrupcion viene del receptor en el UART
    if (PIR1bits.RCIF == 1)
    {
        //esto nos limpiara la interrupcion
        PIR1bits.RCIF = 0;
        TXREG = (RCREG + 1);
        while (TXSTAbits.TRMT == 0);
        
    }
}
//**************************
// Prototipos de funciones
//**************************
void setup(void);
void UART_Init(void);
void __interrupt() ISR();

//**************************
// Ciclo principal
//**************************

void main(void) {
    unsigned int a;
    setup();
    void Lcd_Init(void);
    UART_Init();
    //**************************
    // Loop principal
    //**************************
    while (1) {

        Lcd_Clear();
        //        if (PORTCbits.RC7 == 0) {
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String("Hola Mundo");
        //        }
        //        if (PORTCbits.RC7 == 0) {
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_String("Adios Mundo");
        __delay_ms(2000);
        Lcd_Clear();
        //        }
        //        if (PORTCbits.RC7 == 0) {
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String("Developed By");
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_String("electroSome");
        __delay_ms(2000);
        Lcd_Clear();
        //        }


        //        Lcd_Set_Cursor(1, 1);
        //        Lcd_Write_String("www.electroSome.com");

        for (a = 0; a < 15; a++) {
            __delay_ms(300);
            Lcd_Shift_Left();
        }

        for (a = 0; a < 15; a++) {
            __delay_ms(300);
            Lcd_Shift_Right();
        }

        Lcd_Clear();
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_Char('M');
        Lcd_Write_Char('S');
        __delay_ms(2000);
    }
}

//**************************
// Configuracion
//**************************

void setup(void) {
    
    ANSEL = 0;
    ANSELH = 0b00000001;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b00000111;
    PORTB = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
    
}

//**************************
// Funciones
//**************************
void UART_Init()
{
    //Seleccionara los 8bits para la transmisicion de los datos.
    TXSTAbits.TX9 = 0;
    //habilitar la transmision
    TXSTAbits.TXEN = 1;
    //habilitacion del modo asincrono
    TXSTAbits.SYNC = 0;
    //operacion en velocidad lenta
    TXSTAbits.BRGH = 0;
    //  habilita el puerto serial
    RCSTAbits.SPEN = 1;
    // habilita que constantemente se reciban datos
    RCSTAbits.CREN = 1;
    
    //Baudrate 10417
    SPBRG = 11;
    
    //activacion de las interrupciones
    INTCONbits.GIE =  1;
    // habilitacion de las interrupciones perifericas, ver diagrama.
    INTCONbits.PEIE = 1;
    
    //habilita las interrupciones del receptor.
    PIE1bits.RCIE = 1;
    // limpia el flag de la interrupcion
    PIR1bits.RCIF = 0;
}
