#include <stdint.h>

#include "i2c_hal.h"
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

    send_string("I2C Demo Started\r\n");

    I2C_HAL_Init(LPI2C0);

    while(1)
    {
        I2C_HAL_Start(LPI2C0);
        send_string("I2C START\r\n");

        I2C_HAL_WriteByte(LPI2C0, 0x55);
        send_string("I2C Write: 0x55\r\n");

        I2C_HAL_WriteByte(LPI2C0, 0xAA);
        send_string("I2C Write: 0xAA\r\n");

        I2C_HAL_Stop(LPI2C0);
        send_string("I2C STOP\r\n");

        for(volatile int i = 0; i < 5000000; i++);
    }
}
