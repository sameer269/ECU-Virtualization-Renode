#include "lpuart_hal.h"

LPUART_Type* UART_HAL_GetInstance(uint8_t instance)
{
    switch(instance)
    {
        case 0: return (LPUART_Type*)LPUART0_BASE_ADDR;
        case 1: return (LPUART_Type*)LPUART1_BASE_ADDR;
        case 2: return (LPUART_Type*)LPUART2_BASE_ADDR;
        case 3: return (LPUART_Type*)LPUART3_BASE_ADDR;
        case 4: return (LPUART_Type*)LPUART4_BASE_ADDR;
        case 5: return (LPUART_Type*)LPUART5_BASE_ADDR;
        case 6: return (LPUART_Type*)LPUART6_BASE_ADDR;
        case 7: return (LPUART_Type*)LPUART7_BASE_ADDR;
        case 8: return (LPUART_Type*)LPUART8_BASE_ADDR;
        case 9: return (LPUART_Type*)LPUART9_BASE_ADDR;
        case 10: return (LPUART_Type*)LPUART10_BASE_ADDR;
        case 11: return (LPUART_Type*)LPUART11_BASE_ADDR;
        case 12: return (LPUART_Type*)LPUART12_BASE_ADDR;
        case 13: return (LPUART_Type*)LPUART13_BASE_ADDR;
        case 14: return (LPUART_Type*)LPUART14_BASE_ADDR;
        case 15: return (LPUART_Type*)LPUART15_BASE_ADDR;

        default:
            return (LPUART_Type*)LPUART0_BASE_ADDR;
    }
}

void UART_HAL_Init(uint8_t instance, uint32_t sbr)
{
    LPUART_Type *uart = UART_HAL_GetInstance(instance);

    (void)sbr;

    uart->BAUD = 0x0F;

    uart->CTRL =
        LPUART_CTRL_TE_MASK |
        LPUART_CTRL_RE_MASK;

    for(volatile int i = 0; i < 10000; i++);
}

bool UART_HAL_IsTransmitReady(uint8_t instance)
{
    (void)instance;
    return true;
}

bool UART_HAL_IsReceiveReady(uint8_t instance)
{
    (void)instance;
    return false;
}

void UART_HAL_WriteByte(uint8_t instance, uint8_t data)
{
    LPUART_Type *uart = UART_HAL_GetInstance(instance);

    uart->DATA = data;

}

uint8_t UART_HAL_ReadByte(uint8_t instance)
{
    (void)instance;
    return 0;
}
