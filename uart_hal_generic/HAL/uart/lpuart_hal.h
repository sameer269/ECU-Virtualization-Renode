#ifndef LPUART_HAL_H
#define LPUART_HAL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    volatile const uint32_t VERID;
    volatile const uint32_t PARAM;
    volatile uint32_t GLOBAL;
    volatile uint32_t PINCFG;
    volatile uint32_t BAUD;
    volatile uint32_t STAT;
    volatile uint32_t CTRL;
    volatile uint32_t DATA;
    volatile uint32_t MATCH;
    volatile uint32_t MODIR;
    volatile uint32_t FIFO;
    volatile uint32_t WATER;
} LPUART_Type;

#define LPUART0_BASE_ADDR   0x40328000UL
#define LPUART1_BASE_ADDR   0x4032C000UL
#define LPUART2_BASE_ADDR   0x40330000UL
#define LPUART3_BASE_ADDR   0x40334000UL
#define LPUART4_BASE_ADDR   0x40338000UL
#define LPUART5_BASE_ADDR   0x4033C000UL
#define LPUART6_BASE_ADDR   0x40340000UL
#define LPUART7_BASE_ADDR   0x40344000UL
#define LPUART8_BASE_ADDR   0x4048C000UL
#define LPUART9_BASE_ADDR   0x40490000UL
#define LPUART10_BASE_ADDR  0x40494000UL
#define LPUART11_BASE_ADDR  0x40498000UL
#define LPUART12_BASE_ADDR  0x4049C000UL
#define LPUART13_BASE_ADDR  0x404A0000UL
#define LPUART14_BASE_ADDR  0x404A4000UL
#define LPUART15_BASE_ADDR  0x404A8000UL

#define LPUART_STAT_TDRE_MASK   (1U << 23)
#define LPUART_STAT_RDRF_MASK   (1U << 21)

/* Control Register Bit Masks */
#define LPUART_CTRL_TE_MASK     (1U << 19)
#define LPUART_CTRL_RE_MASK     (1U << 18)



LPUART_Type* UART_HAL_GetInstance(uint8_t instance);

void UART_HAL_Init(uint8_t instance, uint32_t sbr);
void UART_HAL_WriteByte(uint8_t instance, uint8_t data);
uint8_t UART_HAL_ReadByte(uint8_t instance);

bool UART_HAL_IsTransmitReady(uint8_t instance);
bool UART_HAL_IsReceiveReady(uint8_t instance);

#endif
