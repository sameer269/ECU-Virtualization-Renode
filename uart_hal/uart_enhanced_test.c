#include <stdint.h>
#include "HAL/uart/lpuart_hal.h"

void demo_app(void);   // ✅ ADD THIS

extern uint32_t _stack_top;

void Reset_Handler(void) {
    demo_app();
    while(1);
}

__attribute__((section(".isr_vector")))
uint32_t* const vector_table[] = {
    (uint32_t*)0x20040000,
    (uint32_t*)Reset_Handler
};

void demo_app() {

    LPUART_HAL_Init(LPUART_0, 43);

    while(1) {

        const char* msg = "ENHANCED WORKING\r\n";

        for(int i = 0; msg[i] != '\0'; i++) {
            LPUART_HAL_WriteByte(LPUART_0, msg[i]);
        }

        // delay (important)
        for(volatile int i = 0; i < 500000; i++);
    }
}
