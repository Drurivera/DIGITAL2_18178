/* 
 * File:   Template Digital 2
 * Author: Mariandree Rivera
 * Carne t: 18178
 * 
 */
#ifndef __RTC_H
#define	__RTC_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <pic16f887.h>
#include <stdint.h>
#include "I2C.h"

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif
#ifndef uint8_t  i, second, minute, hour, m_day, month, year;
#define uint8_t  i, second, minute, hour, m_day, month, year;
#endif 
//Declaramos prototipos de Funciones

uint8_t bcd_to_decimal(uint8_t number);
uint8_t decimal_to_bcd(uint8_t number);
uint8_t S_RTC(uint8_t second, uint8_t minute , uint8_t hour, uint8_t m_day, uint8_t month, uint8_t year);
uint8_t R_RTC();



#endif	/* __I2C_H */

