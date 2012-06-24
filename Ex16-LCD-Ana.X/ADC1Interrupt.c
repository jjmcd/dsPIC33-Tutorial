/*! \file ADC1Interrupt.c
 *
 * \brief Interrupt service routine for the Analog to Digital converter
 *
 * This file provides the (very simple) ISR that is executed
 * whenever an analog conversion has completed.
 *
 * The analog value is saved and a counter is incremented to
 * advise the mainline that  a new value is available.
 * 
 */
#include <p33Fxxxx.h>

#define EXTERN extern
#include "Ex16-LCD-Ana.h"

//! ADC1 Interrupt Service Routine
/*!
 * Whenever an analog value is available, thie routine will:
 * \li Clear the interrupt flag
 * \li Grab the analog value and store it in potValue
 * \li Increment analogRead
 *
*/
void __attribute__((__interrupt__, auto_psv)) _ADC1Interrupt( void )
{
  IFS0bits.AD1IF = 0;       // Clear A/D interrupt flag
  potValue = ADC1BUF0;      // Save the potentiometer value
  analogRead++;             // Remember it has been read
}
