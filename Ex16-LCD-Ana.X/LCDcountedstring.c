/*! \file LCDcountedstring.c
 *
 *  \brief Send a specific number of characters to the LCD
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


//! Send a counted string to the LCD
void LCDcountedstring( unsigned char *data, unsigned char count)
{
    while (count)
    {
        LCDletter(*data++);
        count--;
    }
}
