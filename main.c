 /******************************************************************************
 *
 * Module: Application
 *
 * File Name:main.c
 *
 * Description: application used to mainpulate leads and push buttons
 *
 *******************************************************************************/
 #include "Micro.h"
 #include "GPIO.h"
 #include "NVIC.h"
 #include "delay.h"

 #define LED			           2
 #define INTERRUPT_LED       3
 #define SWITCH	             4
 #define INTERRUPT_SWITCH    0

 static GPIO_pinConfig ledPinConfig={OUTPUT,GPIO,DIGITAL,NO_RES,OPENDRAIN_DISABLED,NO_DRIVE,NO_TRIGGER,DISABLE_INTERRUPT,{0,0}};
 static GPIO_pinConfig switchConfig={INPUT,GPIO,DIGITAL,PULLUP,OPENDRAIN_DISABLED,NO_DRIVE,NO_TRIGGER,DISABLE_INTERRUPT,{0,0}};
 static GPIO_pinConfig interruptSwitchConfig={INPUT,GPIO,DIGITAL,PULLUP,OPENDRAIN_DISABLED,NO_DRIVE,NO_TRIGGER,
		ENABLE_INTERRUPT,{EDGE_TRIGGERED,FALLING_EDGE}};
 
 void blinkLed(uint8 pin);
 void lightLedWithSwitch(uint8 led, uint8 button);
 void GPIOF_Handler(void);
 
 int main()
 {
     /*Intializing GPIO clock for all ports*/
    GPIO_enablePortClock(PORTF);
	  GPIO_intializePin(&switchConfig,PORTF,SWITCH);
    GPIO_intializePin(&interruptSwitchConfig,PORTF,INTERRUPT_SWITCH);

    GPIO_intializePin(&ledPinConfig,PORTF,LED);
    GPIO_intializePin(&ledPinConfig,PORTF,INTERRUPT_LED);

    /*Enabling global Interrupt & PortF interrupt*/
    NVIC_enableGlobalIrq();
    NVIC_enableIRQ(INT_GPIOF);


    while(1)
      blinkLed(LED);
 }

 
void GPIOF_Handler(void)
{
  for(int i=0;i<3;i++)
    blinkLed(INTERRUPT_LED);
  
  GPIO_clearInterrupt(PORTF,INTERRUPT_SWITCH);
}

 /*
 Function to Blink leds connected to PORTF
 params:
    -led: pinNumber
 */
 void blinkLed(uint8 led)
 {
	SET_BIT(ACCESS_REG(PORTF,GPIO_DATAR_OFFSET),led);
   delayMs(500);
   CLEAR_BIT(ACCESS_REG(PORTF,GPIO_DATAR_OFFSET),led);
	  delayMs(500);
 }

 /*
 Function to set led state based on switch state
 params:
   -led: pinNumber
   -button: number of switch pin
 */
void lightLedWithSwitch(uint8 led, uint8 button)
{
	uint8 buttonState=BIT_IS_CLEAR(ACCESS_REG(PORTF,GPIO_DATAR_OFFSET),button);
    if(buttonState)
        SET_BIT(ACCESS_REG(PORTF,GPIO_DATAR_OFFSET),led);
		else
			CLEAR_BIT(ACCESS_REG(PORTF,GPIO_DATAR_OFFSET),led);
}
