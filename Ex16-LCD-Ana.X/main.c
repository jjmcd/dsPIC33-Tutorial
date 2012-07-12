/*! \file main.c
 *
 * \brief Mainline for Ex16-LCD-Ana
 *
 * This application is intended to show use of the timer
 * and the LCD.  A flag is passed from the ISR to the mainline
 * to indicate time to update the display.
 *
 * A second line of the display shows the potentiometer position, in
 * both voltage and percentage.  The second display line is updated
 * far faster than the top line, providing the value changes.
 *
 * Pressing S3 toggles the first line of the display on and off.
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

#include <stdio.h>


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
char szMessage[9][17] =
{
    " Twas brillig,  ",
    " and the slithy ",
    "toves, did gyre ",
    " and gimble in  ",
    "   the wabe:    ",
    " All mimsy were ",
    " the borogoves, ",
    "  And the mome  ",
    "raths outgrabe. "
};

//! Mainline for Ex16-LCD-Ana
/*! Display a selected message and analog value on the LCD
 *
 * Pseudocode:
 * \code
 *   Initialize()
 *   Clear the LCD display
 *   Delay one dirty flag cycle
 *   Display a welcome message
 *   Wait until ready to clear display
 *   do forever
 *     if the dirty flag is set
 *       clear the dirty flag
 *       clear the display
 *       if doText is true
 *         display the current message
 *         increment the message number
 *         if we are at the end of messages
 *           point to the first message
 *       Set oldValue to impossible value
 *     if a new analog value is available
 *       remember we read the value
 *       if the value has changed enough to matter
 *         Set oldValue to potValue
 *         Create a string containing voltage and percentage
 *         display the string on the second line
 * \endcode
 */
int main(void)
{
    //! Remember previous analog value
    int oldValue;

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
    LCDputs(" To disable top  ");
    LCDposition( 0x41 );
    LCDputs("line press S3 ");

    //Hold off initial analog display until ready to clear welcome message
    while ( !dirty )
        ;

    while (1)
    {
        // If the message needs to be updated
        if ( dirty )
        {
            // Remember we did it
            dirty = 0;
            // Clear the display
            LCDclear();
            if ( doText )
            {
                // Display the current message
                LCDputs(szMessage[message]);
                // Point to the next message
                message++;
                // If we are at the end of the messages
                if ( message > 8 )
                    // point back to the firest message
                    message = 0;
            }
            // Force display of analog
            oldValue = 10000;
        }
        if ( analogRead )
        {
            // Work string for display
            char szValue[16];

            // Remember we read the analog
            analogRead = 0;
            
            // Check enough difference to display
            // (to prevent jitter in the last digit)
            if ( abs( oldValue-potValue ) > 10 )
            {
                // Remember current value
                oldValue = potValue;
                // Place the voltage and percentage into the string
                sprintf(szValue,"%5.3fV  %5.2f%%",
                        3.3*(float)potValue/4095.0,
                        100.0*(float)potValue/4095.0 );
                // Position to the second line and write string to LCD
                LCDposition( 0x40+1 );
                LCDputs(szValue);
            }
        }
        
    }
}
