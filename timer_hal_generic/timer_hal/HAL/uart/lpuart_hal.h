#ifndef LPUART_HAL_H
#define LPUART_HAL_H

#include <stdint.h>
#include <stdbool.h>

// LPUART Register Map Structure
typedef struct {
    volatile const uint32_t VERID;    // Version ID
    volatile const uint32_t PARAM;    // Parameter
    volatile uint32_t GLOBAL;         // Global
    volatile uint32_t PINCFG;         // Pin Configuration
    volatile uint32_t BAUD;           // Baud Rate
    volatile uint32_t STAT;           // Status
    volatile uint32_t CTRL;           // Control
    volatile uint32_t DATA;           // Data
    volatile uint32_t MATCH;          // Match Address
    volatile uint32_t MODIR;          // Modem IrDA
    volatile uint32_t FIFO;           // FIFO
    volatile uint32_t WATER;          // Watermark
} LPUART_Type;

// Instance Base Addresses for S32K388
#define LPUART_0 ((LPUART_Type*)0x40328000)
#define LPUART_1 ((LPUART_Type*)0x4032C000)

// Status Bit Masks
#define LPUART_STAT_TDRE_MASK (1U << 23) // Transmit Data Register Empty
#define LPUART_STAT_RDRF_MASK (1U << 21) // Receive Data Register Full
#define LPUART_CTRL_TE_MASK   (1U << 19) // Transmitter Enable
#define LPUART_CTRL_RE_MASK   (1U << 18) // Receiver Enable

// HAL Function Prototypes
void LPUART_HAL_Init(LPUART_Type* base, uint32_t sbr);
void LPUART_HAL_WriteByte(LPUART_Type* base, uint8_t data);
uint8_t LPUART_HAL_ReadByte(LPUART_Type* base);
bool LPUART_HAL_IsTransmitReady(LPUART_Type* base);
bool LPUART_HAL_IsReceiveReady(LPUART_Type* base);

#endif
