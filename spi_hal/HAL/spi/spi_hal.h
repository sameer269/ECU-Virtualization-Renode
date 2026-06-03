#ifndef SPI_HAL_H
#define SPI_HAL_H

#include <stdint.h>
#include <stdbool.h>

/* Simplified LPSPI Register Map */
typedef struct
{
    volatile uint32_t VERID;
    volatile uint32_t PARAM;
    volatile uint32_t CR;
    volatile uint32_t SR;
    volatile uint32_t IER;
    volatile uint32_t DER;
    volatile uint32_t CFGR0;
    volatile uint32_t CFGR1;
    volatile uint32_t DMR0;
    volatile uint32_t DMR1;
    volatile uint32_t CCR;
    volatile uint32_t FCR;
    volatile uint32_t FSR;
    volatile uint32_t TCR;
    volatile uint32_t TDR;
    volatile uint32_t RSR;
    volatile uint32_t RDR;
} LPSPI_Type;

/* S32K388 LPSPI0 Base Address */
#define LPSPI0 ((LPSPI_Type*)0x40358000)

/* HAL APIs */
void SPI_HAL_Init(LPSPI_Type *base);

void SPI_HAL_Transmit(
    LPSPI_Type *base,
    uint8_t data);

uint8_t SPI_HAL_Receive(
    LPSPI_Type *base);

uint8_t SPI_HAL_Transfer(
    LPSPI_Type *base,
    uint8_t data);

#endif
