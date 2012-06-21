/*! \file lcd.h
 *
 *  \brief LCD definitions
 */

/******	LCD FUNCTION PROTOYPES ******/

//! Initialize the LCD
void LCDinit( void );		        // initialize display
//! Send a command to the LCD
void LCDcommand( char cmd );	        // write command to lcd
//! Send a character to the LCD
void LCDletter( char data );		    // write data to lcd
//! Send a counted string to the LCD
void LCDcountedstring ( unsigned char *data, unsigned char count );


/*****	LCD COMMAND FUCNTION PROTOTYPES  *****/
//! Move the LCD cursor to the right
#define LCDright()  LCDcommand( 0x14 )
//! Move the LCD cursor to the left
#define LCDleft()   LCDcommand( 0x10 )
//! Shift the LCD display
#define LCDshift() LCDcommand( 0x1C )
//! Clear the LCD display and home cursor
#define LCDclear()      LCDcommand( 0x01 )
//! Set the LCD cursor to home
#define LCDhomet()       LCDcommand( 0x02 )
//! Position the LCD cursor to the second line
#define LCDline2()        LCDcommand( 0xC0 ) // (0xC0)
//! Set the LCD cursor position
#define LCDposition(a)      LCDcommand( 0x80 + ( a & 0x7f) )
