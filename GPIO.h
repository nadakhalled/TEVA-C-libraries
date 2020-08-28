 /******************************************************************************
 *
 * Module: General Purpose Input Output
 *
 * File Name:GPIO.h
 *
 * Description: Header file for GPIO control
 *
 *******************************************************************************/
#include "Micro.h"

/*Enum that describes direction of the pin */
typedef enum{INPUT,OUTPUT} GPIO_pinDirection;

/*Enum that describes whether pin is digital or analog */
typedef enum{ANALOG, DIGITAL} GPIO_pinDigitalEnable;

/*Enum that describes the status of the internal resistance of the pin*/
typedef enum{PULLUP,PULLDOWN} GPIO_pinInternalResistance;

/*Enum that describes the output configuration of the pin*/
typedef enum{ OPENDRAIN_DISABLED,OPENDRAIN_ENABLED} GPIO_outputConfig;


typedef enum{EDGE_TRIGGERED,LEVEL_TRIGGER} GPIO_interruptSense;

typedef enum {ONE_EDGE,BOTH_EDGES} GPIO_interruptBothEdges;

typedef enum {FALLING_EDGE,RISING_EDGE} GPIO_interruptTrigger;


/*Struct that describes the configuration of a GPIO pin */
typedef struct 
{
	GPIO_pinDirection direction;
	GPIO_pinDigitalEnable digitalEnable;
	GPIO_pinInternalResistance internalResistance;
	GPIO_outputConfig outputConfig;

}GPIO_pinConfig;


/*Struct that describes the configuration of an interrupt pin */
typedef struct{
	GPIO_interruptSense interruptSense;
	GPIO_interruptBothEdges interruptBothEdges;
	GPIO_interruptTrigger interruptTrigger;
} GPIO_interruptPinConfig;


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

