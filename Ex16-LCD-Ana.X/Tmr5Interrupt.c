/*! \file Tmr5Interrupt.c
 *
 * \brief Timer 5 interrupt service routine
 *
 * Whenever Timer 5 expires, this routine illuminates LED8 to
 * follow the state of PB3.  If PB3 has been pressed for a while,
 * the state of doText is toggled.  LED7 is illuminated it
 * the doText flag is false.
 *
 * The mainline uses doText to determine whether to display the
 * top line of the LCD.  LED7 is illuminated if the text is NOT
 * displayed.  Pressing and releasing PB3 changes the state.
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

//! Number of interrupts PB3 has been pressed
int onCount;
//! Number of interrupts PB3 has been released
int offCount;
//! Counter used to delay toggling dirty flag
int last;

//! Timer 5 Interrupt Service Routine
/*! Gets executed whenever Timer 5 expires.
 * 
 * Causes LED8 to track PB3.  If PB3 is released for a while,
 * and it had previously been pressed for a while, the state
 * of doText is toggled.  If doText is true, LED7 is illuminated.
 *
 * Pseudocode
 * \code
 * Clear interrupt flag
 * Set LED8 to be complement of PB3
 * if PB3 is pressed
 *   Increment onCount
 *   Clear offCount
 * otherwise
 *   Increment offCount
 *   if PB3 has been released for a while
 *     if PB3 had been pressed for a while
 *       Complement doText
 *       Clear onCount
 * Set LED7 to complement of doText
 * \endcode
 * 
 */
void __attribute__((__interrupt__, auto_psv)) _T5Interrupt( void )
{
    IFS1bits.T5IF = 0;              // Clear timer interrupt flag
                                    // This is always the first order of
                                    // business in an interrupt routine

    LED8 = !PB3;                    // LED8 follows PB3

    if ( !PB3 )                     // PB3 depressed
    {
        onCount++;                  // Count up time pressed
        offCount = 0;               // and reset un-pressed count
    }
    else                            // PB3 released
    {
        offCount++;                 // Increment released count
        if ( offCount > 5 )         // Released for a while
            if ( onCount > 5 )      // Was it actually pressed?
            {
                doText = !doText;   // Toggle text display
                onCount = 0;        // Reset pressed count
            }
    }
    LED7 = !doText;                 // LED7 follows text display state
}
