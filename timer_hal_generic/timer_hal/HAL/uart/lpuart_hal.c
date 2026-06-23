#include "lpuart_hal.h"

void LPUART_HAL_Init(LPUART_Type* base, uint32_t sbr)
{
    (void)sbr;

    base->BAUD = 0x0F;

    base->CTRL =
        LPUART_CTRL_TE_MASK |
        LPUART_CTRL_RE_MASK;

    for(volatile int i = 0; i < 10000; i++);
}

bool LPUART_HAL_IsTransmitReady(LPUART_Type* base)
{
    (void)base;
    return true;
}

bool LPUART_HAL_IsReceiveReady(LPUART_Type* base)
{
    (void)base;
    return false;
}

void LPUART_HAL_WriteByte(LPUART_Type* base, uint8_t data)
{
    base->DATA = data;
}

uint8_t LPUART_HAL_ReadByte(LPUART_Type* base)
{
    (void)base;
    return 0;
}
