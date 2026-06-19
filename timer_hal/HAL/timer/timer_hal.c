#include "timer_hal.h"


void TIMER_HAL_Init(uint32_t value)
{
    // Enable PIT clock
    PIT_MCR = 0x00;


    // load timer value
    PIT_LDVAL0 = value;


    // clear interrupt flag
    PIT_TFLG0 = 1;
}

void TIMER_HAL_Start(void)
{
    /*
     bit0 TEN = Timer Enable
     bit1 TIE = Timer Interrupt Enable
    */

    PIT_TCTRL0 = 0x3;
}

void TIMER_HAL_Stop(void)
{
    PIT_TCTRL0 = 0;
}


uint8_t TIMER_HAL_IsExpired(void)
{
    if(PIT_TFLG0 & 1)
    {
        PIT_TFLG0 = 1;
        return 1;
    }

    return 0;
}
