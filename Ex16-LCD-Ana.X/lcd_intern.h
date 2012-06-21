/*! \file lcd_intern.h
 *
 *  \brief Definitions used within LCD routines
 *
 * This file contains definitions of the various connections
 * to the LCD on the Explorer 16 board.  They are uninteresting
 * outside the LCD routines.
 */
/* 
 * File:   lcd_intern.h
 * Author: jjmcd
 *
 * Created on June 19, 2012, 12:57 PM
 */

#ifndef LCD_INTERN_H
#define	LCD_INTERN_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
   For Explorer 16 board, here are the data and control signal definitions
   RS -> RB15
   E  -> RD4
   LCD_RW -> RD5
   DATA -> RE0 - RE7
*/

// Control signal data pins
//! LCD Read/Write pin
#define  LCD_RW         LATDbits.LATD5
//! LCD Register select pin
#define  LCD_RS         LATBbits.LATB15
//! LCD Enable pin
#define  LCD_ENABLE     LATDbits.LATD4

// Control signal pin direction
//! LCD Read/Write direction register bit
#define  LCD_RW_TRIS        TRISDbits.TRISD5
//! LCD Register select direction register bit
#define  LCD_RS_TRIS        TRISBbits.TRISB15
//! LCD Enable direction register bit
#define  LCD_ENABLE_TRIS    TRISDbits.TRISD4

// Data signals and pin direction
//! LCD data port latch
#define  LCD_DATA      LATE
//! LCD data port
#define  LCD_DATAPORT  PORTE
//! LCD data port direction register
#define  LCD_DATATRIS  TRISE

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_INTERN_H */

