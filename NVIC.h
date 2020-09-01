/******************************************************************************
 *
 * Module: Nested Vector Interrupt Control
 *
 * File Name: NVIC.h
 *
 * Description: Header file for controlling NVIC
 *******************************************************************************/


#ifndef     __NVIC__H
#define     __NVIC__H

#include "Micro.h"

/*Type Delerations*/
/*Enum storing the INT numbers of peripherals*/
typedef enum
{
    INT_GPIOA= 16          // GPIO Port A
    ,INT_GPIOB= 17          // GPIO Port B
    ,INT_GPIOC= 18          // GPIO Port C
    ,INT_GPIOD= 19          // GPIO Port D
    ,INT_GPIOE= 20          // GPIO Port E
    ,INT_UART0= 21          // UART0
    ,INT_UART1= 22          // UART1
    ,INT_SSI0=  23          // SSI0
    ,INT_I2C0=  24          // I2C0
    ,INT_PWM0_FAULT=25          // PWM0 Fault
    ,INT_PWM0_0=26          // PWM0 Generator 0
    ,INT_PWM0_1=27          // PWM0 Generator 1
    ,INT_PWM0_2=28          // PWM0 Generator 2
    ,INT_QEI0=  29          // QEI0
    ,INT_ADC0SS0=30          // ADC0 Sequence 0
    ,INT_ADC0SS1=31          // ADC0 Sequence 1
    ,INT_ADC0SS2=32          // ADC0 Sequence 2
    ,INT_ADC0SS3=33          // ADC0 Sequence 3
    ,INT_WATCHDOG=34          // Watchdog Timers 0 and 1
    ,INT_TIMER0A=35          // 16/32-Bit Timer 0A
    ,INT_TIMER0B=36          // 16/32-Bit Timer 0B
    ,INT_TIMER1A=37          // 16/32-Bit Timer 1A
    ,INT_TIMER1B=38          // 16/32-Bit Timer 1B
    ,INT_TIMER2A=39          // 16/32-Bit Timer 2A
    ,INT_TIMER2B=40          // 16/32-Bit Timer 2B
    ,INT_COMP0= 41          // Analog Comparator 0
    ,INT_COMP1= 42          // Analog Comparator 1
    ,INT_SYSCTL=44          // System Control
    ,INT_FLASH= 45          // Flash Memory Control and EEPROM// Control
    ,INT_GPIOF= 46          // GPIO Port F
    ,INT_UART2= 49          // UART2
    ,INT_SSI1=  50          // SSI1
    ,INT_TIMER3A=51          // Timer 3A
    ,INT_TIMER3B=52          // Timer 3B
    ,INT_I2C1= 53          // I2C1
    ,INT_QEI1=54          // QEI1
    ,INT_CAN0=55          // CAN0
    ,INT_CAN1=56          // CAN1
    ,INT_HIBERNATE=59          // Hibernation Module
    ,INT_USB0= 60          // USB
    ,INT_PWM0_3=61          // PWM Generator 3
    ,INT_UDMA=62          // uDMA Software
    ,INT_UDMAERR=63          // uDMA Error
    ,INT_ADC1SS0=64          // ADC1 Sequence 0
    ,INT_ADC1SS1=65          // ADC1 Sequence 1
    ,INT_ADC1SS2=66          // ADC1 Sequence 2
    ,INT_ADC1SS3=67          // ADC1 Sequence 3
    ,INT_SSI2= 73          // SSI2
    ,INT_SSI3= 74          // SSI3
    ,INT_UART3=75          // UART3
    ,INT_UART4=76          // UART4
    ,INT_UART5=77          // UART5
    ,INT_UART6=78          // UART6
    ,INT_UART7=79          // UART7
    ,INT_I2C2= 84          // I2C2
    ,INT_I2C3=85          // I2C3
    ,INT_TIMER4A=86          // 16/32-Bit Timer 4A
    ,INT_TIMER4B=87          // 16/32-Bit Timer 4B
    ,INT_TIMER5A=108         // 16/32-Bit Timer 5A
    ,INT_TIMER5B=109         // 16/32-Bit Timer 5B
    ,INT_WTIMER0A=110         // 32/64-Bit Timer 0A
    ,INT_WTIMER0B=111         // 32/64-Bit Timer 0B
    ,INT_WTIMER1A=112         // 32/64-Bit Timer 1A
    ,INT_WTIMER1B=113         // 32/64-Bit Timer 1B
    ,INT_WTIMER2A=114         // 32/64-Bit Timer 2A
    ,INT_WTIMER2B=115         // 32/64-Bit Timer 2B
    ,INT_WTIMER3A=116         // 32/64-Bit Timer 3A
    ,INT_WTIMER3B=117         // 32/64-Bit Timer 3B
    ,INT_WTIMER4A=118         // 32/64-Bit Timer 4A
    ,INT_WTIMER4B=119         // 32/64-Bit Timer 4B
    ,INT_WTIMER5A=120         // 32/64-Bit Timer 5A
    ,INT_WTIMER5B=121         // 32/64-Bit Timer 5B
    ,INT_SYSEXC=122         // System Exception (imprecise)
    ,INT_PWM1_0=150         // PWM1 Generator 0
    ,INT_PWM1_1=151         // PWM1 Generator 1
    ,INT_PWM1_2=152         // PWM1 Generator 2
    ,INT_PWM1_3=153         // PWM1 Generator 3
    ,INT_PWM1_FAULT=154         // PWM1 Fault
} IRQn_type;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Function declerations*/

/*Function that enables the global interrupt through CMSIS*/
void NVIC_enableGlobalIrq();

/*Function that disables the global interrupt through CMSIS*/
void NVIC_disableGlobalIrq();

/*Functions that enables one of the interrupts
params:
    -IRQn: number of interrupt to be enabled
*/
void NVIC_enableIRQ(IRQn_type IRQn);

/*Functions that disables one of the interrupts
params:
    -IRQn: number of interrupt to be disabled
*/
void NVIC_disableIRQ(IRQn_type IRQn);


#endif /*__NVIC__H */