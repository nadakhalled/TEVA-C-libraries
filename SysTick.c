/******************************************************************************
 *
 * Module: System Timer
 *
 * File Name: SysTick.c
 *
 * Description: source file for System timer
 *******************************************************************************/

#include "SysTick.h"

 void SYSTICK_intialize(SYSTICK_config * configuration)
 {
     SET_BIT(STCTRL,ENABLE);

     if(configuration->interruptEnable)
        SET_BIT(STCTRL,INT_EN);

     if(configuration->clockSource==SYSTEM_CLOCK)
        SET_BIT(STCTRL,CLK_SRC);
 }


 bool SYSTICK_checkUnderflow()
 {
     return BIT_IS_SET(STCTRL,COUNT_FLAG);
 }


 void SYSTICK_setReloadValue(uint32 reloadValue)
 {
     STRELOAD=reloadValue;
 }
 