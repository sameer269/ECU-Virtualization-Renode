#include "i2c_hal.h"

/* Initialize I2C */
void I2C_HAL_Init(LPI2C_Type *base)
{
    /* Enable Master Mode (simplified for Renode) */
    base->MCR = 1;

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
void I2C_HAL_WriteByte(LPI2C_Type *base, uint8_t data)
{
    base->MTDR = data;

    for(volatile int i = 0; i < 1000; i++);
}

/* Read one byte */
uint8_t I2C_HAL_ReadByte(LPI2C_Type *base)
{
    return (uint8_t)(base->MRDR);
}
