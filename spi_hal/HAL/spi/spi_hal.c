#include "spi_hal.h"

/* Initialize SPI */
void SPI_HAL_Init(LPSPI_Type *base)
{
    /* Enable SPI (simplified for Renode) */
    base->CR = 1;

    for(volatile int i = 0; i < 1000; i++);
}

/* Transmit one byte */
void SPI_HAL_Transmit(LPSPI_Type *base, uint8_t data)
{
    base->TDR = data;

    for(volatile int i = 0; i < 1000; i++);
}

/* Receive one byte */
uint8_t SPI_HAL_Receive(LPSPI_Type *base)
{
    return (uint8_t)(base->RDR);
}

/* Full Duplex Transfer */
uint8_t SPI_HAL_Transfer(LPSPI_Type *base, uint8_t data)
{
    base->TDR = data;

    for(volatile int i = 0; i < 1000; i++);

    return (uint8_t)(base->RDR);
}
