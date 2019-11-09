/*
 * File:   main.c
 * Author: Elhmadany
 *
 * Created on 08 ?????, 2019, 03:56 ?
 */
#include "xc.h"
#include "Config.h"
#include "Timer.h"
#include "Main1.h"
#include "SleepM.h"
#include "SW.h"
static tByte TOV_Number_Sec =0;
void main(void) {
    TIM1_Init();
    SWITCH_Init();
    while(1)
    {
       SWITCH_Update();
       while(SWITCH_GetState() == SW1_PRESSED){
           TIMR1_Start();
           if(TOV_Number_Sec==5){
           GPIO_WritePortPin(GPIO_PORTD_DATA,GPIO_PIN_4,GPIO_OUT);
           TOV_Number_Sec=0;
          
           }}
       while(SWITCH_GetState() == SW2_PRESSED){
           TIMR1_Start();
           if(TOV_Number_Sec==7){
           GPIO_WritePortPin(GPIO_PORTD_DATA,GPIO_PIN_12,GPIO_OUT);
           TOV_Number_Sec=0;
           }}
       while(SWITCH_GetState() == SW3_PRESSED){
           TIMR1_Start();
           if(TOV_Number_Sec==9){
           GPIO_WritePortPin(GPIO_PORTD_DATA,GPIO_PIN_13,GPIO_OUT);
           TOV_Number_Sec=0;
           }}
        if(SWITCH_GetState() == SW_NOTPREDSED){
           TIMR1_Start();
           if(TOV_Number_Sec==300){
           /*sleep mode code here*/
               sEOS_Go_To_Sleep();
           }}
       
    }
   
}
void __attribute__((interrupt(no_auto_psv)))_T1Interrupt(void)
{
    if(TMR1_GET_FLAG==1){
    TOV_Number_Sec++;
    TMR1_CLEAR_FLAG;
    }
}
