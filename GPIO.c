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


static void GPIO_setPinDrive(uint32 port, uint8 pin,GPIO_pinCurrentDrive drive)
{
	switch (drive)
	{
		case DRIVE_2mA:
		{
			SET_BIT(ACCESS_REG(port,GPIO_DR2R_OFFSET),pin);
			break;
		}
		case DRIVE_4mA:
		{
			SET_BIT(ACCESS_REG(port,GPIO_DR4R_OFFSET),pin);
			break;
		}
		case DRIVE_8mA:
		{
			SET_BIT(ACCESS_REG(port,GPIO_DR8R_OFFSET),pin);
			break;
		}
	}
}

static void unlockPort(uint32 port,uint8 pin)
{
	WRITE_TO_REG(port,GPIO_LOCKR_OFFSET,GPIO_UNLOCK);
	SET_BIT(ACCESS_REG(port,GPIO_COMMITR_OFFSET), pin);
}


static void lockPort(uint32 port,uint8 pin)
{
	CLEAR_BIT(ACCESS_REG(port,GPIO_COMMITR_OFFSET), pin);
	WRITE_TO_REG(port,GPIO_LOCKR_OFFSET,0);
}


static void configureInputPin(uint32 port,uint8 pin,GPIO_pinConfig* configuration)
{
	/*setting pull up register status*/
	if(configuration->internalResistance==PULLUP)
		SET_BIT(ACCESS_REG(port,GPIO_PUR_OFFSET),pin);
	else if(configuration->internalResistance==PULLDOWN)
		SET_BIT(ACCESS_REG(port,GPIO_PDR_OFFSET),pin);

	/*Checking if pin trigger ADC or uDMA*/
	if(configuration->pinTrigger==ADC)
		SET_BIT(ACCESS_REG(port,GPIO_ADCCTLR_OFFSET),pin);
	else if(configuration->pinTrigger==uDMA)
		SET_BIT(ACCESS_REG(port,GPIO_DMACTLR_OFFSET),pin);
}


static void configureOutputPin(uint32 port, uint8 pin,GPIO_pinConfig* configuration)
{
	/*Check if outputdrain is enabled*/
	if(configuration->outputConfig==OPENDRAIN_ENABLED)
		SET_BIT(ACCESS_REG(port,GPIO_ODR_OFFSET),pin);

	/*Output Drive */
	if(configuration->currentDrive)
		GPIO_setPinDrive(port,pin,configuration->currentDrive);
}

static void GPIO_configureInterruptPin(GPIO_interruptConfig* interruptConfig,uint32 port,uint8 pin)
{	
	//masking interrupt bit to prevent false interrupts
	CLEAR_BIT(ACCESS_REG(port,GPIO_IMR_OFFSET),pin);

	if(interruptConfig->sense==LEVEL_TRIGGER)
		SET_BIT(ACCESS_REG(port,GPIO_ISR_OFFSET),pin);
	
	/*Setting interrupt trigger*/
	if(interruptConfig->trigger==BOTH_EDGES)
		SET_BIT(ACCESS_REG(port,GPIO_IBER_OFFSET),pin);
	else if(interruptConfig->trigger==RISING_EDGE)
		SET_BIT(ACCESS_REG(port,GPIO_IEVR_OFFSET),pin);
	else
		CLEAR_BIT(ACCESS_REG(port,GPIO_IEVR_OFFSET),pin);

	
	//unmasking interrupt bit after finishing the config
	SET_BIT(ACCESS_REG(port,GPIO_IMR_OFFSET),pin);
}


void GPIO_intializePin(GPIO_pinConfig* configuration,uint32 port,uint8 pin)
{
	/*Unlocking Port register*/
	unlockPort(port,pin);

	/*Setting pin direction*/
	/*Output pin*/
	if(configuration->direction)
	{
		SET_BIT(ACCESS_REG(port,GPIO_DIRR_OFFSET), pin);
		configureOutputPin(port,pin,configuration);
	}

	/*Input pin*/
	else
	{
		CLEAR_BIT(ACCESS_REG(port,GPIO_DIRR_OFFSET), pin);
		configureInputPin(port,pin,configuration);
	}
	
	/*Alternate function select*/
	if(configuration->pinFunction==PERIPHERAL)
		SET_BIT(ACCESS_REG(port,GPIO_AFSELR_OFFSET),pin);

	/*Digital enable*/
	if(configuration->digitalEnable)
		SET_BIT(ACCESS_REG(port,GPIO_DENR_OFFSET), pin);
	else
		SET_BIT(ACCESS_REG(port,GPIO_AMSEL_OFFSET), pin);

	/*interrup configuration*/
	if(configuration->interruptEnable)
		GPIO_configureInterruptPin(&(configuration->interruptConfig),port,pin);

	lockPort(port,pin);
}


void GPIO_clearInterrupt(uint32 port,uint8 pin)
{
	SET_BIT(ACCESS_REG(port,GPIO_ICR_OFFSET),pin);
}
