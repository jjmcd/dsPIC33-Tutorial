/*! \file LCDinit.c
 *
 *  \brief Initialize the LCD
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

//! Initialize the LCD
/*!  LCDinit() first delays 15ms to allow the LCD internals to finish
 *   responding to power on.  This is not always necessary, but typically
 *   only happens once in a program.  The LCD initialization sequence is
 *   then sent, setting the LCD to  bit data.
 *
 *   LCD options are then sent, LCD 2 line, 5x7 font,  entry mode to
 *   not shift, display on, cursor off.
 */
void LCDinit( void) {
    // 15mS delay after Vdd reaches nnVdc before proceeding with LCD initialization
    // not always required and is based on system Vdd rise rate
    Delay(Delay_15mS_Cnt); // 15ms delay

    /* set initial states for the data and control pins */
    LCD_DATA &= 0xFF00;
    LCD_RW = 0; // R/W state set low
    LCD_RS = 0; // RS state set low
    LCD_ENABLE = 0; // E state set low

    /* set data and control pins to outputs */
    LCD_DATATRIS &= 0xFF00;
    LCD_RW_TRIS = 0; // RW pin set as output
    LCD_RS_TRIS = 0; // RS pin set as output
    LCD_ENABLE_TRIS = 0; // E pin set as output

    /* 1st LCD initialization sequence */
    LCD_DATA &= 0xFF00;
    LCD_DATA |= 0x0038;
    LCDpulseEnableBit();
    Delay(Delay_5mS_Cnt); // 5ms delay

    /* 2nd LCD initialization sequence */
    LCD_DATA &= 0xFF00;
    LCD_DATA |= 0x0038;
    LCDpulseEnableBit();
    Delay_Us(Delay200uS_count); // 200uS delay

    /* 3rd LCD initialization sequence */
    LCD_DATA &= 0xFF00;
    LCD_DATA |= 0x0038;
    LCDpulseEnableBit();
    Delay_Us(Delay200uS_count); // 200uS delay

    // Establish the LCD options
    // LCD_FUN_SET | DL_8 | 2_LINE _ 5x7_FONT
    LCDcommand(0x38); // function set
    // LCD_DISPLAY | DISP_ON | CURS_OFF | BLINK_OFF
    LCDcommand(0x0C); // Display on/off control, cursor blink off (0x0C)
    // LCD_ENTRY_MODE | DIC_INCR | NO_SHIFT
    LCDcommand(0x06); // entry mode set (0x06)
}
