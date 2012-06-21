/*! \file delay.c
 *
 *  \brief Routines used to provide delays for the LCD routines
 */
#include "delay.h"

unsigned int temp_count;

//! Delay for a specific count
void Delay( unsigned int delay_count ) 
{
	temp_count = delay_count +1;
	asm volatile("outer: dec _temp_count");	
	asm volatile("cp0 _temp_count");
	asm volatile("bra z, done");
	asm volatile("do #3200, inner" );	
	asm volatile("nop");
	asm volatile("inner: nop");
	asm volatile("bra outer");
	asm volatile("done:");
}
	
//! Delay for a specified number of microseconds
void Delay_Us( unsigned int delayUs_count )
{
	temp_count = delayUs_count +1;
	asm volatile("outer1: dec _temp_count");	
	asm volatile("cp0 _temp_count");
	asm volatile("bra z, done1");
	asm volatile("do #1500, inner1" );	
	asm volatile("nop");
	asm volatile("inner1: nop");
	asm volatile("bra outer1");
	asm volatile("done1:");
}		

