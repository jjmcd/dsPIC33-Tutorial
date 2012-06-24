/*! \file Initialize.c
 *
 * \brief Initialization for Ex16-LCD-Ana
 *
 * First initializes the ports, then the timers, then the PWM port,
 * then the A/D converter and finally the global variables.
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
 * \li Initializes timer 5
 * \li Initializes timer 3
 * \li Sets OC3 to PWM using timer 3
 * \li Initialize the A/D converter
 * \li Initializes the dirty flag and message number
 * \li Initializes analogRead and doText
 * \li Ensures the left two LEDs are off
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
    TRISD &= 0xfffb;        // POTD:1,2 outputs

    // Set timer 6 for right LED
    // Explanation ...
    //   Timer 6 will increment every 128 instruction cycles
    //   Once the count reaches 50,000, the timer 6 interrupt will fire
    //   and the count will be reset
    PR6 = 50000;            // Timer 6 counter to 50,000
    TMR6 = 0;               // Clear timer 6
    T6CON = 0x8030;         // 1:256 prescale, timer on, Clock Fcy
    IEC2bits.T6IE = 1;      // Enable Timer 6 interrupt

    // Set timer 5 for pushbutton monitor
    PR5 = 500;              // Timer 5 counter to 500
    TMR5 = 0;               // Clear timer 5
    T5CON = 0x8030;         // 1:256 prescale, timer on, Clock Fcy
    IEC1bits.T5IE = 1;      // Enable Timer 6 interrupt

    // Set up PWM on OC3 (RD2)
    TMR3 = 0;               // Clear timer 3
    PR3 = 1000;             // Timer 3 counter to 1000
    OC3RS = 1024;           // PWM 3 duty cycle
    OC3R = 0;               //
    OC3CON = 0xe;           // Set OC3 to PWM mode, timer 3
    T3CON = 0x8010;         // Fosc/4, 1:4 prescale, start TMR3

  // Initialize the LCD
    LCDinit();

    // Initialize ADC
    /* set port configuration here */
    AD1PCFGLbits.PCFG4 = 0;         // ensure AN4/RB4 is analog (Temp Sensor)
    AD1PCFGLbits.PCFG5 = 0;         // ensure AN5/RB5 is analog (Analog Pot)
    /* set channel scanning here, auto sampling and convert,
       with default read-format mode */
    AD1CON1 = 0x00E4;
    /* select 12-bit, 1 channel ADC operation */
    AD1CON1bits.AD12B = 1;
    /* No channel scan for CH0+, Use MUX A,
       SMPI = 1 per interrupt, Vref = AVdd/AVss */
    AD1CON2 = 0x0000;
    /* Set Samples and bit conversion time */
    AD1CON3 = 0x032F;
    /* set channel scanning here for AN4 and AN5 */
    AD1CSSL = 0x0000;
    /* channel select AN5/RB5 */
    AD1CHS0 = 0x0005;
    /* reset ADC interrupt flag */
    IFS0bits.AD1IF = 0;
    /* enable ADC interrupts */
    IEC0bits.AD1IE = 1;
     /* turn on ADC module */
    AD1CON1bits.ADON = 1;

    // Initialize global variables
    dirty = 0;              // Message dirty flag
    message = 0;            // Current message number
    analogRead = 0;         // Set to A/D not read
    doText = true;          // Start with text display
    auxLEDs = 0;            // LED counter zero
    LED8 = LED7 = 0;

}
