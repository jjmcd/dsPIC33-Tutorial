/*! \file LCDputs.c
 *
 *  \brief Put a string to the LCD
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


//! Send a string to the LCD
/*! Sends a null-terminated string to the LCD
 * \param p char * - pointer to string to be displayed
 * \returns none
 */
void LCDputs( char *p )
{
    while (*p)
    {
        LCDletter(*p);
        p++;
    }
}
