/*! \file main.c
 *
 * \brief Mainline for Ex16-LCD-Ana
 *
 * This application is intended to show use of the timer
 * and the LCD.  A flag is passed from the ISR to the mainline
 * to indicate time to update the display.
 *
 * A second line of the display contains the message number,
 * to demonstrate LCD cursor positioning.
 *
 * File:   main.c
 * Author: jjmcd
 *
 * Created on June 19, 2012, 9:27 AM
 */

/******************************************************************************
 * Software License Agreement
 *
 * GPLV2+
 *
 *****************************************************************************/


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

/*  This is cheating
 *
 * This is sort of a trick.  Global variables must be defined once,
 * but anyplace they are used, they must be referenced as extern.  To
 * simplify keeping track, globals are declared in the header file
 * as EXTERN.  In the mainline, EXTERN is defined as nothing before
 * the header is included.  In all other files, EXTERN is declared
 * as extern.  This way all globals are created in the mainline but
 * are visible to all the other routines.
 */
#define EXTERN
#include "Ex16-LCD-Ana.h"
// Notice that the LCD header file is provided by the LCD library project
#include "../LCDlib-Ex16.X/lcd.h"

// Configuration fuses
//
//! Primary Oscillator (XT, HS, EC) w/ PLL,  Start up with user-selected oscillator
_FOSCSEL( FNOSC_PRIPLL & IESO_OFF );
//! XT Oscillator Mode, Clock switching is enabled, Fail-Safe Clock Monitor is disabled
_FOSC( POSCMD_XT & FCKSM_CSECMD );
//! Watchdog timer enabled/disabled by user software
_FWDT( FWDTEN_OFF );
//! Power-on reset timer 64 ms
_FPOR( FPWRT_PWR64 );
//! Communicate on PGC1/EMUC1 and PGD1/EMUD1, JTAG is Disabled
_FICD( ICS_PGD1 & JTAGEN_OFF );

//! Table of messages to be displayed
char szMessage[4][17] =
{
    "Message One     ",
    "msg num 2       ",
    "Number three    ",
    "I am number four"
};

//! Mainline for Ex16-LCD-Ana
/*! Blink two LEDs and display a number of messages on the LCD
 *
 * Pseudocode:
 * \code
 *   Initialize()
 *   Clear the LCD display
 *   Delay one dirty flag cycle
 *   Display a welcome message
 *   do forever
 *     if the dirty flag is set
 *       clear the dirty flag
 *       clear the display
 *       display the current message
 *       increment the message number
 *       display the message number
 *       if we are at the end of messages
 *         point to the first message
 * \endcode
 */
int main(void)
{
    // Initialize ports and variables
    Initialize();

    // Clear the screen
    LCDclear();

    // Wait a while to pretend like we are thinking hard
    dirty = 0;
    while ( !dirty )
        ;
    dirty = 0;

    // Display a friendly welcome mesage
    LCDputs("In Principio    erat Verbum ");

    while (1)
    {
        // If the message needs to be updated
        if ( dirty )
        {
            // Remember we did it
            dirty = 0;
            // Clear the display
            LCDclear();
            // Display the current message
            LCDputs(szMessage[message]);
            // Point to the next message
            message++;
            // Position cursor to the middle of line 2
            LCDposition( 0x40+5);
            // Display the message number
            LCDletter(0x30+message );
            // If we are at the end of the messages
            if ( message > 3 )
                // point back to the firest message
                message = 0;
        }
        
    }
}
