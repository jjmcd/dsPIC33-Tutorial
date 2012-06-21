/*! \file main.c
 *
 * \brief Mainline for Ex16-LCD-Ana
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

#include "Ex16-LCD-Ana.h"

//! Mainline for Ex16-LCD-Ana
/*! Calls Initialize() and then hangs around waiting for the
 * ISR to do its thing.
 */
int main(void)
{
    Initialize();
    while (1)
    {
        
    }
}
