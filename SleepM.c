/*
 * File:   SleepM.c
 * Author: Elhmadany
 *
 * Created on 09 ?????, 2019, 04:32 ?
 */


#include   "xc.h"
#include   "Main1.h"
#include   "SleepM.h"
void sEOS_Go_To_Sleep(void){
    if (T1CONbits.TCS == 1){ // External clock source
        /* nothing*/
    } else { // Internal clock course
       PMD1=0xffff;    //PERIPHERAL MODULE DISABLE CONTROL REGISTER 1&2&3
       PMD2=0xffff;
       PMD3=0xffff;  
    }
}