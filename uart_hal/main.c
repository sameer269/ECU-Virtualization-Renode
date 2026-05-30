#include <stdint.h>

// --- Register Definitions ---
#define SIUL2_BASE       0x40290000
#define SIUL2_MSCR_44    (SIUL2_BASE + 0x240 + (44 * 4)) 

#define LPUART0_BASE     0x40328000
#define LPUART_BAUD      (*(volatile uint32_t*)(LPUART0_BASE + 0x10))
#define LPUART_STAT      (*(volatile uint32_t*)(LPUART0_BASE + 0x14))
#define LPUART_CTRL      (*(volatile uint32_t*)(LPUART0_BASE + 0x18))
#define LPUART_DATA      (*(volatile uint32_t*)(LPUART0_BASE + 0x1C))

// --- Prototypes ---
void Reset_Handler(void);
int main(void);
extern uint32_t _stack_top; // Defined in your linker script

// --- Minimal Vector Table ---
// This must be placed at the very start of FLASH (0x00400000)
__attribute__((section(".isr_vector")))
uint32_t* const vtor_table[] = {
    (uint32_t*)&_stack_top, // 0: Initial Stack Pointer
    (uint32_t*)Reset_Handler // 1: Reset Vector
};

void uart_init() {
    // S32K388 LPUART0 Initialization
    *(volatile uint32_t*)SIUL2_MSCR_44 = (1 << 21) | 1; 
    LPUART_BAUD = 43; // 115200 at 80MHz
    LPUART_CTRL |= (1 << 19) | (1 << 18); 
}

void uart_puts(const char* s) {
    while (*s) {
        while (!(LPUART_STAT & (1 << 23))); // Wait for TDRE
        LPUART_DATA = *s++;
    }
}

// --- The Boot Sequence ---
void Reset_Handler(void) {
    // In a real app, we'd copy .data from FLASH to SRAM here.
    // For this demo, we jump straight to main.
    main();
    while(1); 
}

int main() {
    uart_init();
    while(1) {
        uart_puts("S32K388 UART Demo running in Renode...\r\n");
        // Simple delay loop
        for(volatile int i=0; i<1000000; i++);
    }
    return 0;
}
