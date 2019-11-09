/*
 * File:   SW.c
 * Author: Elhmadany
 *
 * Created on 08 ?????, 2019, 02:11 ?
 */


#include "xc.h"
#include "SW.h"
#include "Main1.h"
//#include "SleepMode.h"

//tByte SWITCH_Samples[N_SAMPLES] = {SWITCH_NOT_PRESSED, SWITCH_NOT_PRESSED, SWITCH_NOT_PRESSED};

#define Swich1            0
#define Swich2            9
#define Swich3            2
volatile tByte *Switch_pin= &PORTB;
volatile tByte *Switch_pin1= &PORTG;
// volatile  tByte Switch_pin [N_SAMPLES] = {Swich1 ,Swich2,Swich3 };

static tSWITCH_State SWITCH_state = SW_NOTPREDSED;

extern void SWITCH_Init(void){
 //input on  RB0 RB9 RG2
 GPIO_PORTB_DIRECTION|=1<<GPIO_PIN_0;
 GPIO_PORTB_DIRECTION|=1<<GPIO_PIN_9;
 GPIO_PORTG_DIRECTION|=1<<GPIO_PIN_2;
}

extern void SWITCH_Update(void)
   {
    tWord State_SW = *Switch_pin&=1<<Swich1|1<<Swich2;
    tWord State_SW1 = *Switch_pin1&=1<<Swich3;
    if (((State_SW!=8)&&(State_SW!=2048)&&(State_SW1!=4)==0)){SWITCH_state = SW_NOTPREDSED;}
    else if(State_SW==8){SWITCH_state = SW1_PRESSED;}
    else if(State_SW==2048){SWITCH_state = SW2_PRESSED;}
    else if(State_SW1==4){SWITCH_state = SW3_PRESSED;}
    }
    // End of your code! 

tSWITCH_State SWITCH_GetState(void){
    return SWITCH_state;
}

