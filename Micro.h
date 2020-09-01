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


#define GPIO_CLOCK_ENABLE   (*((volatile uint32*) 0x400FE608))

                 
/*NVIC registers*/
#define NVIC_EN0    (*((volatile uint32*) 0xE000E100))
#define NVIC_EN1    (*((volatile uint32*) 0xE000E104))
#define NVIC_EN2    (*((volatile uint32*) 0xE000E108))
#define NVIC_EN3    (*((volatile uint32*) 0xE000E10C))
#define NVIC_EN4    (*((volatile uint32*) 0xE000E110))

#define NVIC_DIS0   (*((volatile uint32*) 0xE000E180))
#define NVIC_DIS1   (*((volatile uint32*) 0xE000E184))
#define NVIC_DIS2   (*((volatile uint32*) 0xE000E188))
#define NVIC_DIS3   (*((volatile uint32*) 0xE000E18C))
#define NVIC_DIS4   (*((volatile uint32*) 0xE000E190))

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Ports Base addreses */
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

#endif /*__MICRO__H__ */
