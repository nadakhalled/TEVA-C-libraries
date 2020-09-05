 /******************************************************************************
 *
 * Module: MicroController
 *
 * File Name: micro.h
 *
 * Description: Contains register addresses for Tm4c123GH6PM
 *
 *******************************************************************************/
 
#ifndef __MICRO__H__
#define __MICRO__H__

#include "std_types.h"
#include "common_macros.h"

/*System Control registers*/
#define GPIO_CLOCK_ENABLE      (*((volatile uint32*) 0x400FE608))
#define RCGC_TIMER             (*((volatile uint32*) 0x400FE608))

/////////////////////////////////////////////////////////////////////////////////////////////////////////                 
/*NVIC registers addresses*/
#define NVIC_EN0    0xE000E100
#define NVIC_EN1    0xE000E104
#define NVIC_EN2    0xE000E108
#define NVIC_EN3    0xE000E10C
#define NVIC_EN4    0xE000E110

#define NVIC_DIS0   0xE000E180
#define NVIC_DIS1   0xE000E184
#define NVIC_DIS2   0xE000E188
#define NVIC_DIS3   0xE000E18C
#define NVIC_DIS4   0xE000E190

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/* SysTick registers */
#define STCTRL     (*((volatile uint32*) 0xE000E010)) 
#define STRELOAD   (*((volatile uint32*) 0xE000E014))
#define STCURRENT  (*((volatile uint32*) 0xE000E018))

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Ports Base addresses */
#define PORTA		0x40004000
#define PORTB 		0x40005000
#define PORTC 		0x40006000
#define PORTD		0x40007000
#define PORTE 		0x40024000
#define PORTF 		0x40025000

/* GPIO registers offsets */
#define GPIO_DATAR_OFFSET		0x3FC
#define GPIO_LOCKR_OFFSET       0x520
#define GPIO_COMMITR_OFFSET     0x524
#define GPIO_DIRR_OFFSET		0x400
#define GPIO_DENR_OFFSET	    0x51C
#define GPIO_AMSEL_OFFSET       0x528
#define GPIO_AFSELR_OFFSET      0x420
#define GPIO_PCTLR_OFFSET       0x52C

#define GPIO_PUR_OFFSET         0x510
#define GPIO_PDR_OFFSET		    0x514
#define GPIO_ODR_OFFSET         0x50C

#define GPIO_DR2R_OFFSET        0x500
#define GPIO_DR4R_OFFSET        0x504
#define GPIO_DR8R_OFFSET        0x508

#define GPIO_ADCCTLR_OFFSET     0x530
#define GPIO_DMACTLR_OFFSET     0x534

/*Interrupt registers offsets*/ 
#define GPIO_ISR_OFFSET         0x404
#define GPIO_IBER_OFFSET        0x408
#define GPIO_IEVR_OFFSET        0x40C
#define GPIO_IMR_OFFSET         0x410

#define GPIO_RISR_OFFSET         0x414
#define GPIO_MISR_OFFSET         0x418

#define GPIO_ICR_OFFSET          0x41C

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Timers Base addresses*/
/*16/32 bit timers*/
#define TIMER0_32     0x40030000
#define TIMER1_32     0x40031000
#define TIMER2_32     0x40032000
#define TIMER3_32     0x40033000
#define TIMER4_32     0x40034000
#define TIMER5_32     0x40035000

/*Timer registers offsets*/
#define GPTM_CFG    0x000
#define GPTM_TAMR   0x004
#define GPTM_CTL    0x00C
#define GPTM_IMR    0x018
#define GPTM_RIS    0x01C
#define GPTM_ICR    0x024
#define GPTM_TAILR  0x028


#endif /*__MICRO__H__ */
