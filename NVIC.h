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
         INT_GPIOA=0          // GPIO Port A
        ,INT_GPIOB=1          // GPIO Port B
        ,INT_GPIOC=2          // GPIO Port C
        ,INT_GPIOD=3        // GPIO Port D
        ,INT_GPIOE=4        // GPIO Port E
        ,INT_UART0=5        // UART0
        ,INT_UART1=6          // UART1
        ,INT_SSI0=7          // SSI0
        ,INT_I2C0=8          // I2C0
        ,INT_PWM0_FAULT=9          // PWM0 Fault
        ,INT_PWM0_0=10          // PWM0 Generator 0
        ,INT_PWM0_1=11          // PWM0 Generator 1
        ,INT_PWM0_2=12          // PWM0 Generator 2
        ,INT_QEI09=13          // QEI0
        ,INT_ADC0SS0=14          // ADC0 Sequence 0
        ,INT_ADC0SS1=15          // ADC0 Sequence 1
        ,INT_ADC0SS2=16          // ADC0 Sequence 2
        ,INT_ADC0SS3=17          // ADC0 Sequence 3
        ,INT_WATCHDOG=18          // Watchdog Timers 0 and 1
        ,INT_TIMER0A=19          // 16/32-Bit Timer 0A
        ,INT_TIMER0B=20          // 16/32-Bit Timer 0B
        ,INT_TIMER1A=21          // 16/32-Bit Timer 1A
        ,INT_TIMER1B=22          // 16/32-Bit Timer 1B
        ,INT_TIMER2A=23          // 16/32-Bit Timer 2A
        ,INT_TIMER2B=24          // 16/32-Bit Timer 2B
        ,INT_COMP01=25          // Analog Comparator 0
        ,INT_COMP12=26          // Analog Comparator 1
        ,INT_SYSCTL=28          // System Control
        ,INT_FLASH5=29          // Flash Memory Control and EEPROM// Control
        ,INT_GPIOF=30          // GPIO Port F
        ,INT_UART2=33          // UART2
        ,INT_SSI1=34          // SSI1
        ,INT_TIMER3A=35          // Timer 3A
        ,INT_TIMER3B=36          // Timer 3B
        ,INT_I2C13=37          // I2C1
        ,INT_QEI1=38          // QEI1
        ,INT_CAN0=39          // CAN0
        ,INT_CAN1=40          // CAN1
        ,INT_HIBERNATE=43          // Hibernation Module
        ,INT_USB00=44         // USB
        ,INT_PWM0_3=45        // PWM Generator 3
        ,INT_UDMA=46          // uDMA Software
        ,INT_UDMAERR=47          // uDMA Error
        ,INT_ADC1SS0=48          // ADC1 Sequence 0
        ,INT_ADC1SS1=49          // ADC1 Sequence 1
        ,INT_ADC1SS2=50          // ADC1 Sequence 2
        ,INT_ADC1SS3=51       // ADC1 Sequence 3
        ,INT_SSI2=57          // SSI2
        ,INT_SSI3=58          // SSI3
        ,INT_UART3=59          // UART3
        ,INT_UART4=60          // UART4
        ,INT_UART5=61          // UART5
        ,INT_UART6=62          // UART6
        ,INT_UART7=63          // UART7
        ,INT_I2C2=68          // I2C2
        ,INT_I2C3=69          // I2C3
        ,INT_TIMER4A=70          // 16/32-Bit Timer 4A
        ,INT_TIMER4B=71          // 16/32-Bit Timer 4B
        ,INT_TIMER5A=92         // 16/32-Bit Timer 5A
        ,INT_TIMER5B=93         // 16/32-Bit Timer 5B
        ,INT_WTIMER0A=94         // 32/64-Bit Timer 0A
        ,INT_WTIMER0B=95         // 32/64-Bit Timer 0B
        ,INT_WTIMER1A=96         // 32/64-Bit Timer 1A
        ,INT_WTIMER1B=97         // 32/64-Bit Timer 1B
        ,INT_WTIMER2A=98         // 32/64-Bit Timer 2A
        ,INT_WTIMER2B=99         // 32/64-Bit Timer 2B
        ,INT_WTIMER3A=100         // 32/64-Bit Timer 3A
        ,INT_WTIMER3B=101         // 32/64-Bit Timer 3B
        ,INT_WTIMER4A=102         // 32/64-Bit Timer 4A
        ,INT_WTIMER4B=103         // 32/64-Bit Timer 4B
        ,INT_WTIMER5A=104         // 32/64-Bit Timer 5A
        ,INT_WTIMER5B=105         // 32/64-Bit Timer 5B
        ,INT_SYSEXC=106        // System Exception (imprecise)
        ,INT_PWM1_0=134         // PWM1 Generator 0
        ,INT_PWM1_1=135      // PWM1 Generator 1
        ,INT_PWM1_2=136        // PWM1 Generator 2
        ,INT_PWM1_3=137        // PWM1 Generator 3
        ,INT_PWM1_FAULT=138        // PWM1 Fault
} IRQn_type;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Function declerations*/

/*Function that enables the global interrupt using inline assembly*/
void NVIC_enableGlobalIrq();

/*Function that disables the global interrupt using inline assembly*/
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
