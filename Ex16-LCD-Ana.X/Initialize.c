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

//! Initialization for Ex16-LCD-Ana
/*! Initializes the ports and then initializes timer 6
 */
void Initialize( void )
{

    TRISA = 0;              // All PORTA pins outputs
    LATA = 0x0001;          // Right LED on

    // Set timer 6 for right LED
    // Explanation ...
    //   Timer 6 will increment every 128 instruction cycles
    //   Once the count reaches 30000, the timer 6 interrupt will fire
    //   and the count will be reset
    PR6 = 50000;             // Timer 6 counter to 30000
    TMR6 = 0;               // Clear timer 6
    T6CON = 0x8030;         // 1:128 prescale, timer on, Clock Fcy
    IEC2bits.T6IE = 1;      // Enable Timer 6 interrupt

}
