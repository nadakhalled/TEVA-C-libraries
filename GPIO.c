 /******************************************************************************
 *
 * Module: General Purpose Input Output
 *
 * File Name:GPIO.c
 *
 * Description: source file for GPIO control
 *
 *******************************************************************************/

#include "GPIO.h"

void GPIO_enablePortClock(uint32 port)
{
	switch(port)
	{
		case PORTA:
		{
			SET_BIT(GPIO_CLOCK_ENABLE,0);
			break;
		}
		case PORTB:
		{
			SET_BIT(GPIO_CLOCK_ENABLE,1);
			break;
		}
		case PORTC:
		{
			SET_BIT(GPIO_CLOCK_ENABLE,2);
			break;
		}
		case PORTD:
		{
			SET_BIT(GPIO_CLOCK_ENABLE,3);
			break;
		}
		case PORTE:
		{
			SET_BIT(GPIO_CLOCK_ENABLE,4);
			break;
		}
		case PORTF:
		{
			SET_BIT(GPIO_CLOCK_ENABLE,5);
			break;
		}
	}
	
}


void GPIO_intializePin(GPIO_pinConfig* configuration,uint32 port,uint8 pin)
{
	/*Setting pin direction*/
	/*Output pin*/
	if(configuration->direction)
	{
		SET_BIT(ACCESS_REG(port,GPIO_DIRR_OFFSET), pin);

		if(configuration->outputConfig==OPENDRAIN_ENABLED)
			SET_BIT(ACCESS_REG(port,GPIO_ODR_OFFSET),pin);
	}
	/*Input pin*/
	else
	{
		CLEAR_BIT(ACCESS_REG(port,GPIO_DIRR_OFFSET), pin);
		/*setting pull up register status*/
		if(configuration->internalResistance==PULLUP)
			SET_BIT(ACCESS_REG(port,GPIO_PUR_OFFSET),pin);
		else if(configuration->internalResistance==PULLDOWN)
			SET_BIT(ACCESS_REG(port,GPIO_PDR_OFFSET),pin);
	}
	
	/*Digital enable*/
	if(configuration->digitalEnable)
		SET_BIT(ACCESS_REG(port,GPIO_DENR_OFFSET), pin);
}
/*
void GPIO_configureInterruptPin(,uint32 port,uint8 pin)
{
1-Mask IM bit
2- set IBE
3- set IS
4-set
	CLEAR_BIT(ACCESS_REG(port,INTERRUP_MASK_REG_OFFSET),pin);
	
}
*/
