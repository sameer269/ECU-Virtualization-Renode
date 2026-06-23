#ifndef TIMER_HAL_H
#define TIMER_HAL_H

#include <stdint.h>

typedef struct
{
    volatile uint32_t MCR;
    volatile uint32_t RESERVED0[55];
    volatile uint32_t LDVAL;
    volatile uint32_t CVAL;
    volatile uint32_t TCTRL;
    volatile uint32_t TFLG;
} PIT_Type;

/* PIT Base Addresses */
#define PIT0_BASE_ADDR   0x400B0000UL
#define PIT1_BASE_ADDR   0x400B4000UL
#define PIT2_BASE_ADDR   0x402FC000UL
#define PIT3_BASE_ADDR   0x40300000UL


PIT_Type* TIMER_HAL_GetInstance(uint8_t instance);

void TIMER_HAL_Init(uint8_t instance,
                    uint32_t loadValue);

void TIMER_HAL_Start(uint8_t instance);

void TIMER_HAL_Stop(uint8_t instance);

uint8_t TIMER_HAL_IsExpired(uint8_t instance);

#endif
