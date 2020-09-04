/******************************************************************************
 *
 * Module: System Timer
 *
 * File Name: SysTick.h
 *
 * Description: Header file for System timer
 *******************************************************************************/

#ifndef __SYSTICK__
#define __SYSTICK__

#include "Micro.h"

 /*CTRL register pins*/
 #define ENABLE         0
 #define INT_EN         1
 #define CLK_SRC        2
 #define COUNT_FLAG     16

/*Enum stating whether the interrupt is enabled or not*/
 typedef enum{INTERRUPT_DISBALED,INTERRUPT_ENABLED} SYSTICK_interruptEnable;

 /*Enum stating the clock source of the systick timer*/
 typedef enum{PIOSC,SYSTEM_CLOCK} SYSTICK_clkSource;

typedef struct{
    SYSTICK_clkSource clockSource;
    SYSTICK_interruptEnable interruptEnable;
}   SYSTICK_config;

/*
    Function that intializes the system clock
    parameters:
        -configuration: struct containging the clock source of the sysTick timer and whether the interrupt is enabled or not
*/
 void SYSTICK_intialize(SYSTICK_config * configuration);

/*
    Function that checks whether the SysTick timer reached zero or not
    Return:
        -returns true if the timer reached zero
*/
bool SYSTICK_checkUnderflow();

/*
    Function that loads the start value of the timer
    Params:
        -reloadValue: the value to be loaded
*/
void SYSTICK_setReloadValue(uint32 reloadValue);

 #endif /*__SYSTICK__*/
 