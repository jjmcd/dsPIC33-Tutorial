/*! \file Ex16-LCD-Ana.h
 *
 * \brief Global declarations for  Ex16-LCD-Ana
 *
 * File:   Ex16-LCD-Ana.h
 * Author: jjmcd
 *
 * Created on June 19, 2012, 9:28 AM
 */

#ifndef EX16_LCD_ANA_H
#define	EX16_LCD_ANA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>

//! Dirty flag - if non-zero display is updated
EXTERN int dirty;
//! Current message number to display
EXTERN int message;
//! Value from the A/D converter
EXTERN unsigned int potValue;
//! Remember whether analog value has been read
EXTERN unsigned int analogRead;
//! Indicate whether to display text message
EXTERN bool doText;
//! Temp counter for proto board LEDs
EXTERN int auxLEDs;

// Macros for various devices
//! Leftmost LED latch
#define LED8 LATAbits.LATA7
//! Next to left LED latch
#define LED7 LATAbits.LATA6
//! Leftmost pushbutton
#define PB3 PORTDbits.RD6


//! Initialization for Ex16-LCD-Ana
void Initialize( void );


#ifdef	__cplusplus
}
#endif

#endif	/* EX16_LCD_ANA_H */

