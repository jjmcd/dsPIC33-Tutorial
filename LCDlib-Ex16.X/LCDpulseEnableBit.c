/*! \file LCDpulseEnableBit.c
 *
 *  \brief Pulse the LCD enable bit for long enough
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

#include "lcd_intern.h"

//! Toggle the LCD enable bit
/*! Each LCD command is strobed into the device by raising the
 * enable bit for at least 40 microseconds.  This routine
 * provides this function to the other functions in the
 * library.
 */
void LCDpulseEnableBit( void )
{
    LCD_ENABLE = 1;
    Nop();
    Nop();
    Nop();
    LCD_ENABLE = 0; // toggle E signal

}
