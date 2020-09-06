 /******************************************************************************
 *
 * Module: General Purpose Timers
 *
 * File Name:GPTM.h
 *
 * Description: header file for General Purpose Timers control
 *
 *******************************************************************************/

 #ifndef __GPTM__
 #define __GPTM__

 #include "Micro.h"

/*Enum that states the mode of the timer*/
typedef enum{ONE_SHOT_MODE=1,PERIODIC_MODE=2,CAPTURE_MODE=3} GPTM_timerMode;

/*Enum that states the count direction of the timer*/
typedef enum{DOWN_COUNTER,UP_COUNTER} GPTM_countDirection;

/*Enum that stateswhether the timer waits for a trigger to operate or not*/
typedef enum{TRIGGER_DISABLED,WAIT_TRIGGER} GPTM_trigger;

/*Enum that states whether the timer match is enabled or not*/
typedef enum{TIMER_MATCH_DISABLED,TIMER_MATCH_ENABLED} GPTM_timerMatchEnable;

/*Enum that states the possible interrupts for the timer*/
typedef enum{NO_INTERRUPT=-1,TIMERA_TIMEOUT=0,TIMERA_CAPTURE_MODE_MATCH=1,TIMERA_CAPTURE_MODE_EVENT=2,
            RTC_RAW=3,TIMERA_MATCH_RAW=4,TIMERB_TIMEOUT=8,TIMERB_CAPTURE_MODE_MATCH=9,
            TIMERB_CAPTURE_MODE_EVENT=10,TIMERB_MATCH=11} GPTM_interruptType;

/*Enum that states necessary configurations for periodic mode*/
typedef struct {
    GPTM_countDirection countDirection;
    GPTM_trigger trigger;
    GPTM_timerMatchEnable timerMatchEnable;
    GPTM_interruptType interruptType;
    uint32 intervalLoad;
} GPTM_periodicTimerConfig;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Functions decleration*/

/*Function that enables the required timer bit in the system registers
params:
    -timer: address of required timer.
*/
void GPTM_enableTimerClock(uint32 timer);


/*Function that enables the periodic mode timer of timerA
params:
    -timer: address of required timer.
    -configuration: necessary configuartion for the periodic timer.
*/
void GPTM_enableTimerAPeriodicMode(uint32 timer,GPTM_periodicTimerConfig* configuration);


/*Function clears the interrupt bitin GPTMICR
params:
    -timer: address of required timer.
    -interrupt: interrupt to be cleared.
*/
void GPTM_clearTimerInterrupt(uint32 timer,GPTM_interruptType interrupt);

 #endif /*__GPTM__ */