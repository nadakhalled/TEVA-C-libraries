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
	
/* Ports Base addreses */
#define PORTA		0x40004000
#define PORTB 		0x40005000
#define PORTC 		0x40006000
#define PORTD			0x40007000
#define PORTE 		0x40024000
#define PORTF 		0x40025000

/* Ports registers offsets */
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


/*					
#define AMSEL_REG_OFFSET
#define INTERRUPT_SENSE_REG_OFFSET	0x404
#define INTERRUPT_BOTH_EDGES_REG_OFFSET	
#define INTERRUP_MASK_REG_OFFSET		
*/


#endif /*__MICRO__H__ */
