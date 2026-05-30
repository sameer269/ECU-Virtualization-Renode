#include "HAL/uart/lpuart_hal.h"
void demo_app();
// Add this to the top of uart_hal_test.c
extern uint32_t _stack_top;
void Reset_Handler(void) {
    demo_app(); // Call your HAL demo
    while(1);
}

__attribute__((section(".isr_vector")))
uint32_t* const vtor_table[] = {
    (uint32_t*)&_stack_top,
    (uint32_t*)Reset_Handler
};

void demo_app() {
    // Initialize LPUART0 with calculated SBR for 115200
    LPUART_HAL_Init(LPUART_0, 43);

    const char* msg = "HAL Demo Started\r\n";
    
    // Send string via HAL
    for(int i = 0; msg[i] != '\0'; i++) {
        LPUART_HAL_WriteByte(LPUART_0, msg[i]);
    }

	while(1) {
    const char* msg = "HAL Demo Started\r\n";

    for(int i = 0; msg[i] != '\0'; i++) {
        LPUART_HAL_WriteByte(LPUART_0, msg[i]);
    }

    for(volatile int i = 0; i < 500000; i++); // delay
}
}
