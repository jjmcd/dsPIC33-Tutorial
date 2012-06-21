/*! \file ADC1Interrupt.c

 \brief Interrupt service routine for the Analog to Digital converter

 This file provides the (very simple) ISR that is executed
 whenever an analog conversion has completed.
*/
#include <p33Fxxxx.h>

#define EXTERN extern
#include "Ex16-LCD-Ana.h"

//! ADC1 Interrupt Service Routine
/*!
  Pseudocode:
  \code
    Clear the interrupt flag
    Grab the analog value and store it in potValue
    increment analogRead
  \endcode
*/
void __attribute__((__interrupt__, auto_psv)) _ADC1Interrupt( void )
{
  IFS0bits.AD1IF = 0;       // Clear A/D interrupt flag
  potValue = ADC1BUF0;      // Save the potentiometer value
  analogRead++;             // Remember it has been read
}
