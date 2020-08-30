 /******************************************************************************
 *
 * Module: General Purpose Input Output
 *
 * File Name:GPIO.h
 *
 * Description: Header file for GPIO control
 *
 *******************************************************************************/

 #ifndef __GPIO__H
 #define __GPIO__H

#include "Micro.h"

#define GPIO_UNLOCK		0x4C4F434B

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Type declerations */
/*Enum that describes direction of the pin */
typedef enum{INPUT,OUTPUT} GPIO_pinDirection;

/*Enum that describes whether pin is digital or analog */
typedef enum{ANALOG, DIGITAL} GPIO_pinDigitalEnable;

/*Enum that describes the status of the internal resistance of the pin*/
typedef enum{NO_RES,PULLUP,PULLDOWN} GPIO_pinInternalResistance;

/*Enum that describes the output configuration of the pin*/
typedef enum{ OPENDRAIN_DISABLED,OPENDRAIN_ENABLED} GPIO_outputConfig;

/*Enum that desscribes the functionality of a pin*/
typedef enum {GPIO,PERIPHERAL} GPIO_pinFunction;

/*enum that describes the output current drive */
typedef enum {NO_DRIVE=0,DRIVE_2mA=1, DRIVE_4mA=2,DRIVE_8mA=3} GPIO_pinCurrentDrive;

/*Enum that states if a pin is used as dma of adc trigger*/
typedef enum {NO_TRIGGER,ADC,uDMA} GPIO_pinTrigger;

/*Interrupt */
/*Enum that states if the interrupt of a pin is enabled*/
typedef enum {DISABLE_INTERRUPT,ENABLE_INTERRUPT} GPIO_interruptEnable;

/*Enum that describes interrupt sense */
typedef enum{EDGE_TRIGGERED,LEVEL_TRIGGER} GPIO_interruptSense;

/*Enum that describes the trigger of the interrupt pin*/
typedef enum {BOTH_EDGES,FALLING_EDGE,RISING_EDGE} GPIO_interruptTrigger;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Struct describing the configuration of the enum*/
typedef struct 
{
	GPIO_interruptSense sense;
	GPIO_interruptTrigger trigger;

} GPIO_interruptConfig;

/*Struct that describes the configuration of a GPIO pin */
typedef struct 
{
	GPIO_pinDirection direction;
	GPIO_pinFunction pinFunction;
	GPIO_pinDigitalEnable digitalEnable;
	GPIO_pinInternalResistance internalResistance;
	GPIO_outputConfig outputConfig;
	GPIO_pinCurrentDrive currentDrive;
	GPIO_pinTrigger pinTrigger;
	GPIO_interruptEnable interruptEnable;
	GPIO_interruptConfig interruptConfig;

}GPIO_pinConfig;


/*Struct that describes the configuration of an interrupt pin */
typedef struct{
	GPIO_interruptSense interruptSense;
	GPIO_interruptTrigger interruptTrigger;
} GPIO_interruptPinConfig;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*FUNCTION DECLERATION*/
/*
Function that enables GPIO port clock so that pins can be used
params:
	-port: port address
*/ 
void GPIO_enablePortClock(uint32 port);

/* Function that intializes a GPIO pin
params:
	-configuration: the configuration of the pin
	-port:	port to be configrued
	-pin: number of pin ro be configured
*/
void GPIO_intializePin(GPIO_pinConfig *configuration,uint32 port,uint8 pin);

/* Function that clears the interrupt Mask interrupt status and raw interrupt status by setting ICR bit
params:
	-port: port of the interrupt pin
	-pin: the interrupt pin
*/
void GPIO_clearInterrupt(uint32 port,uint8 pin);
#endif /*__GPIO__H*/