/*! \file Initialize.c
 *
 * \brief Initialization for Ex16-LCD-Ana
 *
 * */

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

#define EXTERN extern
#include "Ex16-LCD-Ana.h"

#include "../LCDlib-Ex16.X/lcd.h"

//! Initialization for Ex16-LCD-Ana
/*!
 * \li Sets the processor clock to 40 MHz
 * \li Initializes the ports
 * \li Initializes timer 6
 * \li Initializes the dirty flag and message number
 */
void Initialize( void )
{
    // Set the instruction clock speed
    //
    // Fcy 40 MIPS
    // DOZE = Fcy/8 = 011
    // DOZEN = 1
    // PLLPRE 2 = 00000
    // PLLDIV 40 = .38 = 0x26 = 0 0010 0110
    // PLLPOST 2 00
    //ROI   DOZE  DOZEN FRCDIV PLLPOST X   PLLPRE
    // 15 14 13 12  11  10 9 8   7 6   5  4 3 2 1 0
    //  0  0  0  0   0   0 0 0   0 0   0  0 0 0 0 0

    CLKDIV = 0x0000;
    PLLFBD = 0x0026;

    // Fcy 20 MIPS
    // PLLPRE 2 = 00000
    // PLLDIV 40 = .38 = 0x26 = 0 0010 0110
    // PLLPOST 4 01
    //ROI   DOZE  DOZEN FRCDIV PLLPOST X   PLLPRE
    // 15 14 13 12  11  10 9 8   7 6   5  4 3 2 1 0
    //  0  0  0  0   0   0 0 0   0 1   0  0 0 0 0 0
/*
    CLKDIV = 0x0008;
    PLLFBD = 0x0026;
*/

    TRISA = 0;              // All PORTA pins outputs
    LATA = 0x0001;          // Right LED on

    // Set timer 6 for right LED
    // Explanation ...
    //   Timer 6 will increment every 128 instruction cycles
    //   Once the count reaches 50,000, the timer 6 interrupt will fire
    //   and the count will be reset
    PR6 = 50000;             // Timer 6 counter to 50,000
    TMR6 = 0;               // Clear timer 6
    T6CON = 0x8030;         // 1:256 prescale, timer on, Clock Fcy
    IEC2bits.T6IE = 1;      // Enable Timer 6 interrupt

    // Initialize the LCD
    LCDinit();

    // Initialize global variables
    dirty = 0;              // Message dirty flag
    message = 0;            // Current message number

}
