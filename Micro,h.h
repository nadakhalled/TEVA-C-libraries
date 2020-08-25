 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name:GPIO.h
 *
 * Description: Data types redefining.
 *
 *******************************************************************************/

#ifndef MICRO__H__
#define MICRO__H__

#define input		0
#define output	1

#define PORTA_DATA	(*((volatile uint32*) 0x400043FC))
#define PORTA_DIR		(*((volatile uint32*) 0x40004400))
	

#define PORTB_DATA 	(*((volatile uint32*) 0x400053FC))
#define PORTB_DIR		(*((volatile uint32*) 0x40005400))


#define PORTC_DATA 	(*((volatile uint32*) 0x400063FC))
#define PORTC_DIR		(*((volatile uint32*) 0x40006400))

#define PORTD_DATA 	(*((volatile uint32*) 0x400073FC))
#define PORTD_DIR		(*((volatile uint32*) 0x40007400))
	

#define PORTE_DATA 	(*((volatile uint32*) 0x400243FC))
#define PORTE_DIR		(*((volatile uint32*) 0x40024400))
	
#define PORTF_DATA 	(*((volatile uint32*) 0x400253FC))
#define PORTF_DIR		(*((volatile uint32*) 0x40025400))
	

#endif /*MICRO__H__*/