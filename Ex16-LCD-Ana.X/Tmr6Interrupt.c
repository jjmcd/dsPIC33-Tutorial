/*! \file Tmr6Interrupt.c
 *
 * \brief Timer 6 interrupt service routine
 *
 * Whenever Timer 6 expires, this routine toggles the rightmost
 * 2 LEDs.  After 6 interrupts, it sets the dirty flag causing
 * the mainline to display a new message on the LCD.
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

#define EXTERN extern
#include "Ex16-LCD-Ana.h"

//! Counter used to delay toggling dirty flag
int delayCount;

//! Timer 6 Interrupt Service Routine
/*! Gets executed whenever Timer 6 expires
 * 
 * Pseudocode:
 * \code
 *     Clear timer interrupt flag
 *     Toggle right 2 LEDs (XOR LATA with 3)
 *     increment delayCount
 *     if  delayCount > 5
 *         Set dirty flag
 *         Reset delay count
 * \endcode
 */
void __attribute__((__interrupt__, auto_psv)) _T6Interrupt( void )
{
    IFS2bits.T6IF = 0;      // Clear timer interrupt flag
                            // This is always the first order of
                            // business in an interrupt routine

    LATA ^= 0x0003;         // Toggle right 2 LEDs
    delayCount++;           // Increment delayCount
    if ( delayCount > 5 )   // Only update display every 5
    {                       // toggles of LEDs
        dirty = 1;          // Set the dirty flag
        delayCount = 0;     // Reset the delayCount
    }
    //auxLEDs++;
    //auxLEDs &= 0x0007;
    //LATD = (LATD & 0xfffd) | auxLEDs;
//    LATD ^= 0x0046;
}
