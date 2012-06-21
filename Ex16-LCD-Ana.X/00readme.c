/*! \file 00readme.c
 *
 * \brief Introduction
 *
 * This project toggles the LEDs on the timer and displays multiple
 * messages on the LCD.
 *
 * Unlike the earlier incarnation, the LCD routines are no longer included
 * in the project but instead are in a separate library.  In this way those
 * routines may be used by other projects by simply referencing the
 * library and header file in the new project.
 *
 * The application first sets the processor speed.  In main.c, there are
 * a number of configuration fuses set.  By default, these work reasonably
 * well on the Explorer 16, but it is preferable to be explicit about
 * what they are doing.
 *
 * The first configuration line:
 * \code
 * _FOSCSEL( FNOSC_PRIPLL & IESO_OFF );
 * \endcode
 * says to use the primary oscillator (i.e. the cystal), with the PLL
 * system, and to start up with the user selected oscillator.  An alternative
 * is to start with a default internal RC oscillator, and then switch to
 * the primary oscillator under program control.
 *
 * The next line:
 * \code
 * _FOSC( POSCMD_XT & FCKSM_CSECMD );
 * \endcode
 * tells the dsPIC that the primary oscillator is an XT crystal.  This
 * basically affects the amount of power delivered to the crystal.  EC is
 * for very low power crystals, typically watch crystals, XT is for "normal"
 * crystals, and HS for high speed, typically >10MHz, crystals.  It also
 * says that it is permissible to switch clocks under program control, but
 * should the selected oscillator fail, do not automatically switch to
 * the fallback oscillator.
 *
 * The third configuration line
 * \code
 * _FWDT( FWDTEN_OFF );
 * \endcode
 * disables the watchdog timer.  If this were not done, the program would
 * periodically reset, unless the program constantly resets the watchdog
 * timer.
 *
 * The next:
 * \code
 * _FPOR( FPWRT_PWR64 );
 * \endcode
 * holds off processor reset for 64 milliseconds after power has been
 * applied.  The idea is to give external circuitry an opportunity to
 * stabilize before the program starts.
 *
 * The final configuration line
 * \code
 * _FICD( ICS_PGD1 & JTAGEN_OFF );
 * \endcode
 * turns off the JTAG interface, and establishes PGD1/PGC1 as the pins for
 * debug communication.  There are three sets of programming pins on the
 * dsPIC33FJ256GP701, so the developer may select a pair of pins that does
 * not interfere with peripheral use for the selected circuit.
 *
 * In Initialize(), two registers are set which determine how the PLL
 * is configured.  The \c CLKDIV register sets the pre- and post- PLL
 * dividers which divide the clock before and after the PLL clock
 * multiplier.  \c PLLFBD sets the PLL feedback divisor which has the
 * effect of multiplying the clock.
 *
 * \c CLKDIV has a number of fields which allow the peripheral clock to be
 * set slower than the instruction clock in some situations.  These fields
 * are not used, and are set to zero which essentially disables this feature.
 *
 * \dot
 * digraph mainflo
 * {
 *    size="2.0,2.0";
 *    label="Mainline flow chart"
 *    fontname="Helvetica-Bold";
 *
 *    node [style="filled" fillcolor="lightcyan" fontname="Helvetica"];
 *    Initialize [shape="record" style="filled" fillcolor="wheat"
 *             fontname="Helvetica"];
 *    "if (dirty)" [shape="diamond"];
 *    "if(message>3)" [shape="diamond"];
 *    "while(1)" [shape="trapezium"];
 *     Initialize->"Clear LCD";
 *     "Clear LCD"->"Wait";
 *     "Wait"->"Welcome Message";
 *     "Welcome Message"->"while(1)";
 *     "while(1)"->"if (dirty)";
 *       "if (dirty)"->"while(1)" [label="no"];
 *       "if (dirty)"->"clear dirty" [label="yes"];
 *         "clear dirty"->"show message";
 *         "show message"->"next message";
 *         "next message"->"if(message>3)";
 *         "if(message>3)"->"message=0" [label="yes"];
 *         "if(message>3)"->"while(1)" [label="no"];
 *           "message=0"->"while(1)";
 * }
 * \enddot
 *
 */
