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
/*! In C, strings are always terminated with a null character, so
 *  there is no need to count characters.  However, it is possible
 *  to send something else to the LCD, thinking it is a string when
 *  in fact, it is not terminated.  Therefore, in embedded
 *  applications, it is safer to count characters so the string
 *  display is guaranteed to complete no matter what the data.
 *
 * \param data unsigned char * - pointing to the string to be displayed
 * \param count int - count of number of characters to send to LCD
 * \returns none
*/
void LCDcountedstring( unsigned char *data, unsigned char count)
{
    while (count)
    {
        LCDletter(*data++);
        count--;
    }
}
