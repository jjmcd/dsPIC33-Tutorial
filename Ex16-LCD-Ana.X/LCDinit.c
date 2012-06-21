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
    LCD_ENABLE = 1;
    Nop();
    Nop();
    Nop();
    LCD_ENABLE = 0; // toggle E signal
    Delay(Delay_5mS_Cnt); // 5ms delay

    /* 2nd LCD initialization sequence */
    LCD_DATA &= 0xFF00;
    LCD_DATA |= 0x0038;
    LCD_ENABLE = 1;
    Nop();
    Nop();
    Nop();
    LCD_ENABLE = 0; // toggle E signal
    Delay_Us(Delay200uS_count); // 200uS delay

    /* 3rd LCD initialization sequence */
    LCD_DATA &= 0xFF00;
    LCD_DATA |= 0x0038;
    LCD_ENABLE = 1;
    Nop();
    Nop();
    Nop();
    LCD_ENABLE = 0; // toggle E signal
    Delay_Us(Delay200uS_count); // 200uS delay

    LCDcommand(0x38); // function set
    LCDcommand(0x0C); // Display on/off control, cursor blink off (0x0C)
    LCDcommand(0x06); // entry mode set (0x06)
}
