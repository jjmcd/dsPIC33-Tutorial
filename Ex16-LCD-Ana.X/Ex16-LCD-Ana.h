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

//! Dirty flag - if non-zero display is updated
EXTERN int dirty;
//! Current message number to display
EXTERN int message;

//! Initialization for Ex16-LCD-Ana
void Initialize( void );


#ifdef	__cplusplus
}
#endif

#endif	/* EX16_LCD_ANA_H */

