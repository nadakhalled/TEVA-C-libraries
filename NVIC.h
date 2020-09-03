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
     INT_GPIOA          // GPIO Port A
    ,INT_GPIOB          // GPIO Port B
    ,INT_GPIOC          // GPIO Port C
    ,INT_GPIOD          // GPIO Port D
    ,INT_GPIOE          // GPIO Port E
    ,INT_UART0          // UART0
    ,INT_UART1          // UART1
    ,INT_SSI0          // SSI0
    ,INT_I2C0          // I2C0
    ,INT_PWM0_FAULT          // PWM0 Fault
    ,INT_PWM0_0          // PWM0 Generator 0
    ,INT_PWM0_1          // PWM0 Generator 1
    ,INT_PWM0_2          // PWM0 Generator 2
    ,INT_QEI09          // QEI0
    ,INT_ADC0SS0          // ADC0 Sequence 0
    ,INT_ADC0SS1          // ADC0 Sequence 1
    ,INT_ADC0SS2          // ADC0 Sequence 2
    ,INT_ADC0SS3          // ADC0 Sequence 3
    ,INT_WATCHDOG          // Watchdog Timers 0 and 1
    ,INT_TIMER0A          // 16/32-Bit Timer 0A
    ,INT_TIMER0B          // 16/32-Bit Timer 0B
    ,INT_TIMER1A          // 16/32-Bit Timer 1A
    ,INT_TIMER1B          // 16/32-Bit Timer 1B
    ,INT_TIMER2A          // 16/32-Bit Timer 2A
    ,INT_TIMER2B          // 16/32-Bit Timer 2B
    ,INT_COMP01          // Analog Comparator 0
    ,INT_COMP12          // Analog Comparator 1
    ,INT_SYSCTL          // System Control
    ,INT_FLASH5          // Flash Memory Control and EEPROM// Control
    ,INT_GPIOF          // GPIO Port F
    ,INT_UART2          // UART2
    ,INT_SSI1          // SSI1
    ,INT_TIMER3A          // Timer 3A
    ,INT_TIMER3B          // Timer 3B
    ,INT_I2C13          // I2C1
    ,INT_QEI1          // QEI1
    ,INT_CAN0          // CAN0
    ,INT_CAN1          // CAN1
    ,INT_HIBERNATE          // Hibernation Module
    ,INT_USB00          // USB
    ,INT_PWM0_3          // PWM Generator 3
    ,INT_UDMA          // uDMA Software
    ,INT_UDMAERR          // uDMA Error
    ,INT_ADC1SS0          // ADC1 Sequence 0
    ,INT_ADC1SS1          // ADC1 Sequence 1
    ,INT_ADC1SS2          // ADC1 Sequence 2
    ,INT_ADC1SS3          // ADC1 Sequence 3
    ,INT_SSI2          // SSI2
    ,INT_SSI3          // SSI3
    ,INT_UART3          // UART3
    ,INT_UART4          // UART4
    ,INT_UART5          // UART5
    ,INT_UART6          // UART6
    ,INT_UART7          // UART7
    ,INT_I2C2          // I2C2
    ,INT_I2C3          // I2C3
    ,INT_TIMER4A          // 16/32-Bit Timer 4A
    ,INT_TIMER4B          // 16/32-Bit Timer 4B
    ,INT_TIMER5A         // 16/32-Bit Timer 5A
    ,INT_TIMER5B         // 16/32-Bit Timer 5B
    ,INT_WTIMER0A         // 32/64-Bit Timer 0A
    ,INT_WTIMER0B         // 32/64-Bit Timer 0B
    ,INT_WTIMER1A         // 32/64-Bit Timer 1A
    ,INT_WTIMER1B         // 32/64-Bit Timer 1B
    ,INT_WTIMER2A         // 32/64-Bit Timer 2A
    ,INT_WTIMER2B         // 32/64-Bit Timer 2B
    ,INT_WTIMER3A         // 32/64-Bit Timer 3A
    ,INT_WTIMER3B         // 32/64-Bit Timer 3B
    ,INT_WTIMER4A         // 32/64-Bit Timer 4A
    ,INT_WTIMER4B         // 32/64-Bit Timer 4B
    ,INT_WTIMER5A         // 32/64-Bit Timer 5A
    ,INT_WTIMER5B         // 32/64-Bit Timer 5B
    ,INT_SYSEXC        // System Exception (imprecise)
    ,INT_PWM1_0         // PWM1 Generator 0
    ,INT_PWM1_1      // PWM1 Generator 1
    ,INT_PWM1_2        // PWM1 Generator 2
    ,INT_PWM1_3        // PWM1 Generator 3
    ,INT_PWM1_FAULT        // PWM1 Fault
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