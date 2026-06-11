#ifndef I2C_HAL_H
#define I2C_HAL_H

#include <stdint.h>

typedef struct
{
    volatile uint32_t MCR;
    volatile uint32_t MSR;
    volatile uint32_t MIER;
    volatile uint32_t MDER;
    volatile uint32_t MCFGR0;
    volatile uint32_t MCFGR1;
    volatile uint32_t MCFGR2;
    volatile uint32_t MCFGR3;
    volatile uint32_t MDMR;
    volatile uint32_t MCCR0;
    volatile uint32_t MCCR1;
    volatile uint32_t MFCR;
    volatile uint32_t MFSR;
    volatile uint32_t MTDR;
    volatile uint32_t MRDR;
} LPI2C_Type;

/* S32K388 LPI2C0 Base Address */
#define LPI2C0 ((LPI2C_Type *)0x40350000)

/* HAL APIs */
void I2C_HAL_Init(LPI2C_Type *base);
void I2C_HAL_Start(LPI2C_Type *base);
void I2C_HAL_Stop(LPI2C_Type *base);
void I2C_HAL_WriteByte(LPI2C_Type *base, uint8_t data);
uint8_t I2C_HAL_ReadByte(LPI2C_Type *base);

#endif
