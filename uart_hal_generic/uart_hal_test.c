#include "HAL/uart/lpuart_hal.h"

extern uint32_t _stack_top;

void Reset_Handler(void);
void send_string(uint8_t instance, const char *str);

__attribute__((section(".isr_vector")))
uint32_t * const vector_table[] =
{
    (uint32_t *)&_stack_top,
    (uint32_t *)Reset_Handler
};

void send_string(uint8_t instance, const char *str)
{
    while(*str)
    {
        UART_HAL_WriteByte(instance, *str++);
    }
}

void Reset_Handler(void)
{
    /* Test LPUART0 */
    UART_HAL_Init(0, 43);

    send_string(0, "Generic UART HAL Demo Started\r\n");
    send_string(0, "Using LPUART0\r\n");

    while(1)
    {
        send_string(0, "Hello from LPUART0\r\n");

        for(volatile uint32_t i = 0; i < 500000; i++);
    }
}
