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
/*!  This routine simple sends a data byte to the LCD.  The
 *   register select pin is set to 0 notifying the LCD that the
 *   byte is to be interpreted as a command.
 *
 * \param cmd char - Command byte to send to LCD
 * \returns none
 * 
 *   \todo This routine delays 400us after sending the byte.  Instead
 *   the LCD busy flag should be checked before sending the byte.
 *   All routines using delays, however, must follow this protocol
 */
void LCDcommand( char cmd )
{
    LCD_DATA &= 0xFF00; // prepare RD0 - RD7
    LCD_DATA |= cmd; // command byte to lcd
    LCD_RW = 0; // ensure RW is 0
    LCD_RS = 0;
    LCDpulseEnableBit();
    Delay(Delay_5mS_Cnt); // 5ms delay
}

