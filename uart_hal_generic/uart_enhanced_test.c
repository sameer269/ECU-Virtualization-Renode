#include <stdint.h>
#include "HAL/uart/lpuart_hal.h"

extern uint32_t _stack_top;

void Reset_Handler(void);
void demo_app(void);

__attribute__((section(".isr_vector")))
uint32_t * const vector_table[] =
{
    (uint32_t *)&_stack_top,
    (uint32_t *)Reset_Handler
};

void Reset_Handler(void)
{
    demo_app();

    while(1);
}

void send_string(uint8_t instance, const char *str)
{
    while(*str)
    {
        UART_HAL_WriteByte(instance, *str++);
    }
}

void demo_app(void)
{
    UART_HAL_Init(0, 43);

    send_string(0, "Generic UART HAL Started\r\n");

    while(1)
    {
        send_string(0, "FROM UART0\r\n");

        for(volatile uint32_t i = 0; i < 5000000; i++);
    }
}
