 /******************************************************************************
 *
 * Module: General Purpose Timers
 *
 * File Name:GPTM.c
 *
 * Description: source file for General Purpose Timers control
 *
 *******************************************************************************/

 void GPTM_enableTimerClock(uint32 timer)
 {
     switch(timer):
     {
         case TIMER0:
         {
             SET_BIT(RCGC_TIMER,0);
             break;
         }
         case TIMER1:
         {
             SET_BIT(RCGC_TIMER,1);
             break;
         }
         case TIMER2:
         {
             SET_BIT(RCGC_TIMER,2);
             break;
         }
         case TIMER3:
         {
             SET_BIT(RCGC_TIMER,3);
             break;
         }
         case TIMER4:
         {
             SET_BIT(RCGC_TIMER,4);
             break;
         }
         case TIMER5:
         {
             SET_BIT(RCGC_TIMER,5);
             break;
         }
     }
 }


 void GPTM_enableTimerAPeriodicMode(uint32 timer,GPTM_periodicTimerConfig* configuration)
 {
     /*Disabling TimerA before config*/
     CLEAR_BIT(ACCESS_REG(timer,GPTM_CTL),0);

     /*16 bit timer configuration*/
     WRITE_TO_REG(timer,GPTM_CFG,0x4);

     /*TimerA config*/
     WRITE_TO_REG(timer,GPTM_TAMR,PERIODIC_MODE);
     if(configuration->timerMatchEnable)
        SET_BIT(ACCESS_REG(timer,GPTM_TAMR),5);
    
    if(configuration->countDirection==UP_COUNTER)
        SET_BIT(ACCESS_REG(timer,GPTM_TAMR),4);

    WRITE_TO_REG(timer,GPTM_TAILR,configuration->intervalLoad);

    if(configuration->interruptType!=NO_INTERRUPT)
        SET_BIT(ACCESS_REG(timer,GPTM_IMR),configuration->interruptType);
    
     SET_BIT(ACCESS_REG(timer,GPTM_CTL),0);
 }

 void GPTM_clearTimerInterrupt(uint32 timer,GPTM_interruptType interrupt)
 {
     CLEAR_BIT(ACCESS_REG(timer,GPTM_ICR),interruptType);
 }