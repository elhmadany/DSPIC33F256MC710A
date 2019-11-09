/*
 * File:   Timer.c
 * Author: Elhmadany
 *
 * Created on 08 ?????, 2019, 06:55 ?
 */


#include "xc.h"
#include "Main1.h"
#include "Timer.h"



void TIM1_Init(void)
{
 TIMR1_Stop();
 TMR1_SET_PRESCALER_256;
 TMR_ENABLE_INTERRUPT;
 GLOBAL_INTERRUPT_ENABLE;
 TMR1_InternalClk;
 TMR1_CLEAR_FLAG;
 TMR1=0;
 PR1=14451;                  //PeriodRegister1to 1Second as-> (1/((7370000/2)/256))*14451
}
void TIMR1_Start(void){
 TMR1_Start;
}
void TIMR1_Stop(void){
 TMR1_Stop;
}
/*
 void  TMIR1_Delay_Wait_MS( tWord DELAY_MS){
     //internal clock(FRC)=7.37 MHZ
     TMR1=0;
     tWord Limit= ((65535/Ipers)*1000)*2 ;     //~=4.13 Sec
    // Add your code here!
    if ((DELAY_MS>= 0) && (DELAY_MS <= Limit)){ 
        // Set initial value of timer 
        TMR1 = 65536 - Ipers *( DELAY_MS/1000);
        // Start TMR1  
        TIMR1_Start(); 
        while(!(Timer1InterruptFlag==1)){};
    }
}
*/

//used for set the Number of OverFlow (Used for SW )

/*extern void TMR1_Set_TOV_timeinSecTime(tByte u8Val)
{
	TOV_Number_Sec = u8Val;

}*/
 
/* tByte TMR1_Get_TOV_timeSec(void)
{  
	return TOV_Number_Sec; 
}*/


