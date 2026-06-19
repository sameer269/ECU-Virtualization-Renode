#include <stdint.h>
#include "timer_hal.h"
#include "lpuart_hal.h"

extern uint32_t _stack_top;

void Reset_Handler(void);

void send_string(const char *str)
{
    while(*str)
    {
        LPUART_HAL_WriteByte(LPUART_0, *str++);
    }
}

__attribute__((section(".isr_vector")))
uint32_t * const vector_table[] =
{
    (uint32_t *)&_stack_top,
    (uint32_t *)Reset_Handler
};

void Reset_Handler(void)
{
    LPUART_HAL_Init(LPUART_0, 43);

    send_string("Timer HAL Demo Started\r\n");

    TIMER_HAL_Init(50000);

    TIMER_HAL_Start();

    while(1)
    {
        if(TIMER_HAL_IsExpired())
        {
            send_string("Timer Expired\r\n");
        }
    }
}
