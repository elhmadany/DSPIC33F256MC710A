/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __MAIN_H
#define __MAIN_H
#include <p33fj256mc710a.h>

/* GPIO definitions */
/* GPIO Pins */
#define GPIO_PIN_0              (0)
#define GPIO_PIN_1              (1)
#define GPIO_PIN_2              (2)
#define GPIO_PIN_3              (3)
#define GPIO_PIN_4              (4)
#define GPIO_PIN_5              (5)
#define GPIO_PIN_6              (6)
#define GPIO_PIN_7              (7)
#define GPIO_PIN_8              (0)
#define GPIO_PIN_9              (1)
#define GPIO_PIN_10              (2)
#define GPIO_PIN_11              (3)
#define GPIO_PIN_12              (4)
#define GPIO_PIN_13              (5)
#define GPIO_PIN_14              (6)
#define GPIO_PIN_15              (7)
/* GPIO Port Registers redefinition */
#define GPIO_PORTA_DATA         (PORTA)
#define GPIO_PORTA_DIRECTION    (TRISA)

#define GPIO_PORTB_DATA         (PORTB)
#define GPIO_PORTB_DIRECTION    (TRISB)

#define GPIO_PORTC_DATA         (PORTC)
#define GPIO_PORTC_DIRECTION    (TRISC)

#define GPIO_PORTD_DATA         (PORTD)
#define GPIO_PORTD_DIRECTION    (TRISD)

#define GPIO_PORTE_DATA         (PORTE)
#define GPIO_PORTE_DIRECTION    (TRISE)
#define GPIO_PORTG_DATA         (PORTG)
#define GPIO_PORTG_DIRECTION    (TRISG)

/* GPIO direction setting */
#define GPIO_OUT                (0)
#define GPIO_IN                 (1)

/* GPIO port operations */
#define GPIO_InitPort(CONTROL, DIRECTION)   ((CONTROL) = (DIRECTION)?(~GPIO_OUT):(GPIO_OUT))
#define GPIO_WritePort(PORT, DATA)          ((PORT) = (DATA))
#define GPIO_ReadPort(PORT)                 (PORT)

/* GPIO port pin operations */
#define GPIO_InitPortPin(CONTROL, PIN, DIRECTION)   ((CONTROL) = (CONTROL & (~(1 << PIN)))|(DIRECTION << PIN))
#define GPIO_WritePortPin(PORT, PIN, DATA)          ((PORT) = (PORT & (~(1 << PIN)))|(DATA << PIN))
#define GPIO_ReadPortPin(PORT, PIN)                 (((PORT) & (1 << PIN)) >> (PIN))


/* Timer 1 macros */
#define TMR1_SET_PRESCALER_256	 T1CONbits.TCKPS0 = 1;\
								 T1CONbits.TCKPS1 = 1

								

#define TMR1_GET_FLAG			(IFS0bits.T1IF)
#define TMR1_CLEAR_FLAG			(IFS0bits.T1IF = 0)
#define   Ipers               (7370000UL/256)   /* Select Prescalar = 1/256 */
//#define TMR_UPDATE_REGISTER_MS(DELAY_MS)		(TMR1 = 65536 - Ipers *( DELAY_MS/1000);

#define TMR_ENABLE_INTERRUPT	(IEC0bits.T1IE=1)
#define GLOBAL_INTERRUPT_ENABLE	(INTCON2bits.INT0EP=1)

#define TMR1_Start		      (T1CONbits.TON = 1)
#define TMR1_Stop		        (T1CONbits.TON = 0)
#define TMR1_InternalClk         (T1CONbits.TCS = 0)
#define Timer1InterruptFlag        (IFS0bits.T1IF)
/*Switchs Confige*/

/* Standard data types */
typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tlong;
#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif // __MAIN_H

