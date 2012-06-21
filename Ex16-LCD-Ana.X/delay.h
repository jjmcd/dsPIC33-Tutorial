/*! \file delay.h
 *
 *   \brief Declarations for LCD delay routines
 */
//#define Fcy  14754600
//! Instruction clock Hz
#define Fcy  16000000

//! Delay for a specific count
void Delay( unsigned int delay_count );
//! Delay for a specified number of microseconds
void Delay_Us( unsigned int delayUs_count );

//! Counts for a 200 us delay
#define Delay200uS_count  (Fcy * 0.0002) / 1080
//! Counts for a 1 ms delay
#define Delay_1mS_Cnt	  (Fcy * 0.001) / 2950
//! Counts for a 2 ms delay
#define Delay_2mS_Cnt	  (Fcy * 0.002) / 2950
//! Counts for a 5 ms delay
#define Delay_5mS_Cnt	  (Fcy * 0.005) / 2950
//! Counts for a 15 ms delay
#define Delay_15mS_Cnt 	  (Fcy * 0.015) / 2950
//! Counts for a 1 second delay
#define Delay_1S_Cnt	  (Fcy * 1) / 2950 

