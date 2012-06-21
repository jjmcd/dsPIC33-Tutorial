/*! \file LCDcommand.c
 *
 *  \brief Send a command to the LCD
 *
 */

#if defined(__PIC24E__)
#include <p24Exxxx.h>

#elif defined (__PIC24F__)
#include <p24Fxxxx.h>

#elif defined(__PIC24H__)
#include <p24Hxxxx.h>

#elif defined(__dsPIC30F__)
#include <p30Fxxxx.h>

#elif defined (__dsPIC33E__)
#include <p33Exxxx.h>

#elif defined(__dsPIC33F__)
#include <p33Fxxxx.h>

#endif

#include "lcd.h"
#include "lcd_intern.h"
#include "delay.h"

//! Send a command to the LCD
void LCDcommand( char cmd )          // subroutiune for lcd commands
{
    LCD_DATA &= 0xFF00; // prepare RD0 - RD7
    LCD_DATA |= cmd; // command byte to lcd
    LCD_RW = 0; // ensure RW is 0
    LCD_RS = 0;
    LCD_ENABLE = 1; // toggle E line
    Nop();
    Nop();
    Nop();
    LCD_ENABLE = 0;
    Delay(Delay_5mS_Cnt); // 5ms delay
}

