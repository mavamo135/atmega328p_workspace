/******************************************************************************
* Title                 :   NXTIOT board configuration header file  
* Filename              :   nxtiot_board.h
* Author                :   Maximiliano Valencia
* Origin Date           :   28/03/2019
* Version               :   1.0.0
* Compiler              :   avr-gcc
* Target                :   AVR
* Notes                 :   None
******************************************************************************/
/** @file board.h
 *  @brief Defines the configuration of the board.
 * 
 *  This is the header file for the configuration of the pins used by the 
 *  board.
 * 
 */

#ifndef _BOARD_H
#define _BOARD_H

/******************************************************************************
* Includes
******************************************************************************/
#include <avr/io.h>

/******************************************************************************
* Preprocessor Constants
******************************************************************************/


/******************************************************************************
* Configuration Constants
******************************************************************************/

/**** Digital IO Pins Definitions ********************************************/

/*! On board LED port register */
#define LED_PORT        PORTB
/*! On board LED direction register */
#define LED_DDR         DDRB
/*! On board LED pin number */
#define LED_PIN         PORTB0

/*! On board push button port register */
#define SW_PORT         PORTD
/*! On board push button direction register */
#define SW_DDR          DDRD
/*! On board push button pin register */
#define SW_PINR         PIND
/*! On board push button pin number */
#define SW_PIN          PORTD6

/*! PD2 port address */
#define D2_PORT         PORTD
/*! PD2 pin number */
#define D2_PIN          PD2

/*! PD3 port address */
#define D3_PORT         PORTD
/*! PD3 pin number */
#define D3_PIN          PD3

/*! PD4 port address */
#define D4_PORT         PORTD
/*! PD4 pin number */
#define D4_PIN          PD4

/*! PD5 port address */
#define D5_PORT         PORTD
/*! PD5 pin number */
#define D5_PIN          PD5

/*! PB1 port address */
#define B1_PORT         PORTB
/*! PB1 pin number */
#define B1_PIN          PB1

/*! PD2 port address */
#define C2_PORT         PORTC
/*! PD2 pin number */
#define C2_PIN          PC2

/**** ADC Pins Definitions ***************************************************/

/*! ADC0 port address */
#define ADC0_PORT       PORTC
/*! ADC0 pin number */
#define ADC0_PIN        PC0

/*! ADC1 port address */
#define ADC1_PORT       PORTC
/*! ADC1 pin number */
#define ADC1_PIN        PC1

/*! ADC2 port address */
#define ADC2_PORT       PORTC
/*! ADC2 pin number */
#define ADC2_PIN        PC2

/*! ADC3 port address */
#define ADC3_PORT       PORTC
/*! ADC3 pin number */
#define ADC3_PIN        PC3

/*! ADC4 port address */
#define ADC4_PORT       PORTC
/*! ADC4 pin number */
#define ADC4_PIN        PC4

/*! ADC5 port address */
#define ADC5_PORT       PORTC
/*! ADC5 pin number */
#define ADC5_PIN        PC5

/**** Sigfox Wisol Pins Definitions ******************************************/

/*! Wisol TX port address */
#define WISOL_TX_PORT   PORTD
/*! Wisol TX pin number */
#define WISOL_TX_PIN    PD1

/*! Wisol RX port address */
#define WISOL_RX_PORT   PORTD
/*! Wisol RX pin number */
#define WISOL_RX_PIN    PD0

/*! Wisol EN port address */
#define WISOL_EN_PORT   PORTD
/*! Wisol EN pin number */
#define WISOL_EN_PIN    PD7

/******************************************************************************
* Macros
******************************************************************************/

/******************************************************************************
* Typedefs
******************************************************************************/

/******************************************************************************
* Variables
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/

#endif /* _BOARD_H */
