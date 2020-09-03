/******************************************************************************
 *
 * Module: Nested Vector Interrupt Control
 *
 * File Name: NVIC.C
 *
 * Description: Source file for controlling NVIC
 *******************************************************************************/

 #include "NVIC.h"

typedef enum { DISABLE,ENABLE} NVIC_interruptState;

void NVIC_enableGlobalIrq()
{
    __asm(" CPSIE i");
}


void NVIC_disableGlobalIrq()
{
    __asm(" CPSID i");
}


static void NVIC_changeRegState(NVIC_interruptState state,uint32 enablePort,uint32 disablePort,uint8 pin)
{
    if(state)
        SET_BIT(enablePort,pin);
    else
        SET_BIT(disablePort,pin);

}


static void NVIC_changeInterruptState(IRQn_type IRQn,NVIC_interruptState state)
{
    uint8 pin=0;
     if(IRQn/31==0)
     {
         pin=IRQn;
         NVIC_changeRegState(state,NVIC_EN0,NVIC_DIS0,pin);
     }
     else if(IRQn/63==0)
     {
         pin=IRQn-32;
         NVIC_changeRegState(state,NVIC_EN1,NVIC_DIS1,pin);

     }
     else if(IRQn/95==0)
     {
         pin=IRQn-64;
         NVIC_changeRegState(state,NVIC_EN2,NVIC_DIS2,pin);
     }
     else if(IRQn/127==0)
     {
         pin=IRQn-95;
         NVIC_changeRegState(state,NVIC_EN3,NVIC_DIS3,pin);
     }
     else
     {
         pin=IRQn-128;
         NVIC_changeRegState(state,NVIC_EN4,NVIC_DIS4,pin);
     }
}


 void NVIC_enableIRQ(IRQn_type IRQn)
 {
     NVIC_changeInterruptState(IRQn,ENABLE);
 }

 void NVIC_disableIRQ(IRQn_type IRQn)
 {
     NVIC_changeInterruptState(IRQn,DISABLE);
 }
