#include <stdint.h>
#include "../../uart_hal/HAL/uart/lpuart_hal.h"

extern uint32_t _stack_top;

void demo_app(void);

// Reset Handler
void Reset_Handler(void) {
    demo_app();
    while(1);
}

// Vector Table
__attribute__((section(".isr_vector")))
uint32_t* const vector_table[] = {
    (uint32_t*)0x20040000,
    (uint32_t*)Reset_Handler
};

// Send string using HAL
void send_string(const char* msg) {
    for(int i = 0; msg[i] != '\0'; i++) {
        LPUART_HAL_WriteByte(LPUART_0, msg[i]);
    }
}

// MAIN APPLICATION
void demo_app() {

    LPUART_HAL_Init(LPUART_0, 43);

    int counter = 0;
    int alarm_triggered = 0;   // 🔥 flag

    while(1) {

        counter++;

        // delay (time simulation)
        for(volatile int i = 0; i < 500000; i++);

        // trigger ONLY ONCE
        if(counter == 55 && alarm_triggered == 0) {

            send_string("ALARM TRIGGERED\r\n");

            alarm_triggered = 1;   // 🔥 block further triggers
        }
    }
}
