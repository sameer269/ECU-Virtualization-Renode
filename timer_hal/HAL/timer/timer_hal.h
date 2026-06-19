#ifndef TIMER_HAL_H
#define TIMER_HAL_H

#include <stdint.h>

#define PIT0_BASE_ADDR 0x400B0000U


#define PIT_MCR     (*(volatile uint32_t *)(PIT0_BASE_ADDR + 0x00))

#define PIT_LDVAL0  (*(volatile uint32_t *)(PIT0_BASE_ADDR + 0x100))
#define PIT_CVAL0   (*(volatile uint32_t *)(PIT0_BASE_ADDR + 0x104))
#define PIT_TCTRL0  (*(volatile uint32_t *)(PIT0_BASE_ADDR + 0x108))
#define PIT_TFLG0   (*(volatile uint32_t *)(PIT0_BASE_ADDR + 0x10C))


void TIMER_HAL_Init(uint32_t value);
void TIMER_HAL_Start(void);
void TIMER_HAL_Stop(void);
uint8_t TIMER_HAL_IsExpired(void);


#endif
