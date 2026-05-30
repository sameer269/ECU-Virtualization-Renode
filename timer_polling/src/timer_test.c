#include <stdint.h>
#include "../../uart_hal/HAL/uart/lpuart_hal.h"
#define TIMER_BASE 0x40010000

// Simulated timer register
#define TIMER_VALUE (*(volatile uint32_t*)(TIMER_BASE + 0x00))

extern uint32_t _stack_top;

void demo_app(void);

// Reset handler
void Reset_Handler(void) {
    demo_app();
    while(1);
}

// Vector table
__attribute__((section(".isr_vector")))
uint32_t* const vector_table[] = {
    (uint32_t*)0x20040000,
    (uint32_t*)Reset_Handler
};

// Simple delay loop
void delay() {
    for(volatile int i = 0; i < 500000; i++);
}


void send_string(const char* msg) {
    for(int i = 0; msg[i] != '\0'; i++) {
        LPUART_HAL_WriteByte(LPUART_0, msg[i]);   
    }
}


// MAIN APP
void demo_app() {

    // Initialize UART (IMPORTANT)
    LPUART_HAL_Init(LPUART_0, 43);

    while(1) {

        const char* msg = "TIMER TICK\r\n";

        for(int i = 0; msg[i] != '\0'; i++) {
            LPUART_HAL_WriteByte(LPUART_0, msg[i]);
        }

        // delay
        for(volatile int i = 0; i < 500000; i++);
    }
}
