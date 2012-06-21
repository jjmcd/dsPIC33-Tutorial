/*! \file LCDletter.c
 *
 *  \brief Send a character to the LCD
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


//! Send a character to the LCD
void LCDletter( char data )        // subroutine for lcd data
{
    LCD_RW = 0; // ensure RW is 0
    LCD_RS = 1; // assert register select to 1
    LCD_DATA &= 0xFF00; // prepare RD0 - RD7
    LCD_DATA |= data; // data byte to lcd
    LCD_ENABLE = 1;
    Nop();
    Nop();
    Nop();
    LCD_ENABLE = 0; // toggle E signal
    LCD_RS = 0; // negate register select to 0
    Delay_Us(Delay200uS_count); // 200uS delay
    Delay_Us(Delay200uS_count); // 200uS delay
}
