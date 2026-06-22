#include "i2c_hal.h"

/* Initialize I2C */
void I2C_HAL_Init(
    LPI2C_Type *base,
    I2C_ConfigType *config)
{
    /* Enable Master Mode */
    base->MCR = 1;

    if(config->masterMode)
    {
        base->MCFGR1 |= (1 << 0);
    }

    /* Baud Rate */
    base->MCCR0 = config->baudRate;

    for(volatile int i = 0; i < 1000; i++);
}

/* Generate START */
void I2C_HAL_Start(LPI2C_Type *base)
{
    (void)base;

    for(volatile int i = 0; i < 1000; i++);
}

/* Generate STOP */
void I2C_HAL_Stop(LPI2C_Type *base)
{
    (void)base;

    for(volatile int i = 0; i < 1000; i++);
}

/* Write one byte */
void I2C_HAL_WriteByte(
    LPI2C_Type *base,
    uint8_t data)
{
    base->MTDR = data;

    for(volatile int i = 0; i < 1000; i++);
}

/* Read one byte */
uint8_t I2C_HAL_ReadByte(
    LPI2C_Type *base)
{
    return (uint8_t)(base->MRDR);
}

/* Transfer */
uint8_t I2C_HAL_Transfer(
    LPI2C_Type *base,
    uint8_t data)
{
    I2C_HAL_WriteByte(base, data);

    return I2C_HAL_ReadByte(base);
}
