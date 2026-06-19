#include "spi_hal.h"

/* SPI Initialization */
void SPI_HAL_Init(
    LPSPI_Type *base,
    SPI_ConfigType *config)
{
    /* Enable SPI */
    base->CR = 1;

    /* Master Mode */
    if(config->masterMode)
    {
        base->CFGR1 |= (1 << 0);
    }

    /* Clock Polarity (CPOL) */
    if(config->clockPolarity)
    {
        base->TCR |= (1 << 31);
    }

    /* Clock Phase (CPHA) */
    if(config->clockPhase)
    {
        base->TCR |= (1 << 30);
    }

    /* Frame Size */
    base->TCR |= ((config->dataBits - 1) & 0xFFF);

    /* Baud Rate */
    base->CCR = config->baudRate;

    for(volatile int i = 0; i < 1000; i++);
}

/* Transmit one byte */
void SPI_HAL_Transmit(
    LPSPI_Type *base,
    uint8_t data)
{
    base->TDR = data;

    for(volatile int i = 0; i < 1000; i++);
}

/* Receive one byte */
uint8_t SPI_HAL_Receive(
    LPSPI_Type *base)
{
    return (uint8_t)(base->RDR);
}

/* Full Duplex Transfer */
uint8_t SPI_HAL_Transfer(
    LPSPI_Type *base,
    uint8_t data)
{
    SPI_HAL_Transmit(base, data);

    return SPI_HAL_Receive(base);
}
