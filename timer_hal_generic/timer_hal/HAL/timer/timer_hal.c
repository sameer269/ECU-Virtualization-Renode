#include "timer_hal.h"

PIT_Type* TIMER_HAL_GetInstance(uint8_t instance)
{
    switch(instance)
    {
        case 0:
            return (PIT_Type*)PIT0_BASE_ADDR;

        case 1:
            return (PIT_Type*)PIT1_BASE_ADDR;

        case 2:
            return (PIT_Type*)PIT2_BASE_ADDR;

        case 3:
            return (PIT_Type*)PIT3_BASE_ADDR;

        default:
            return (PIT_Type*)PIT0_BASE_ADDR;
    }
}

void TIMER_HAL_Init(uint8_t instance,
                    uint32_t loadValue)
{
    PIT_Type *pit = TIMER_HAL_GetInstance(instance);

    pit->MCR = 0x0;

    pit->LDVAL = loadValue;

    pit->TFLG = 0x1;
}

void TIMER_HAL_Start(uint8_t instance)
{
    PIT_Type *pit = TIMER_HAL_GetInstance(instance);

    pit->TCTRL = 0x3;
}

void TIMER_HAL_Stop(uint8_t instance)
{
    PIT_Type *pit = TIMER_HAL_GetInstance(instance);

    pit->TCTRL = 0x0;
}

uint8_t TIMER_HAL_IsExpired(uint8_t instance)
{
    PIT_Type *pit = TIMER_HAL_GetInstance(instance);

    if(pit->TFLG & 0x1)
    {
        pit->TFLG = 0x1;
        return 1;
    }

    return 0;
}
