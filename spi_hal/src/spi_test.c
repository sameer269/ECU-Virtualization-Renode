#include <stdint.h>
#include "spi_hal.h"
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
uint32_t* const vector_table[] =
{
    (uint32_t*)&_stack_top,
    (uint32_t*)Reset_Handler
};

void Reset_Handler(void)
{
    LPUART_HAL_Init(LPUART_0, 43);

    send_string("SPI Demo Started\r\n");

    SPI_HAL_Init(LPSPI0);

    while(1)
    {
        SPI_HAL_Transmit(LPSPI0, 0x55);
        send_string("SPI Sent: 0x55\r\n");

        for(volatile int i = 0; i < 50000000; i++);

        SPI_HAL_Transmit(LPSPI0, 0xAA);
        send_string("SPI Sent: 0xAA\r\n");

        for(volatile int i = 0; i < 50000000; i++);
    }
}
