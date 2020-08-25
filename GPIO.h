 /******************************************************************************
 *
 * Module: General Purpose Input Output
 *
 * File Name:GPIO.h
 *
 * Description: Header file for GPIO control
 *
 *******************************************************************************/
#include "std_types.h"


typedef struct 
{
	uint8 inputOutput;
	uint8 digitalEnable;
	
}GPIO_ConfigType;

void GPIO_intializePin(GPIO_ConfigType configuration);