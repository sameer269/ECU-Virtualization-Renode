#include <stdint.h>

// --- Register Definitions ---
#define SIUL2_BASE       0x40290000
#define SIUL2_MSCR_44    (SIUL2_BASE + 0x240 + (44 * 4)) // PTC12 (TX)
#define SIUL2_MSCR_45    (SIUL2_BASE + 0x240 + (45 * 4)) // PTC13 (RX)

#define LPUART0_BASE     0x40328000
#define LPUART_BAUD      (*(volatile uint32_t*)(LPUART0_BASE + 0x10))
#define LPUART_STAT      (*(volatile uint32_t*)(LPUART0_BASE + 0x14))
#define LPUART_CTRL      (*(volatile uint32_t*)(LPUART0_BASE + 0x18))
#define LPUART_DATA      (*(volatile uint32_t*)(LPUART0_BASE + 0x1C))

// --- Prototypes ---
void Reset_Handler(void);
int main(void);
extern uint32_t _stack_top;

__attribute__((section(".isr_vector")))
uint32_t* const vtor_table[] = {
    (uint32_t*)&_stack_top,
    (uint32_t*)Reset_Handler
};

void uart_init() {
    // 1. Mux Pins: PTC12 (TX) and PTC13 (RX)
    *(volatile uint32_t*)SIUL2_MSCR_44 = (1 << 21) | 1; // Output Buffer Enable + Mux
    *(volatile uint32_t*)SIUL2_MSCR_45 = (1 << 19) | 1; // Input Buffer Enable + Mux
    
    // 2. Configure Baud Rate (115200 @ 80MHz)
    LPUART_BAUD = 43; 

    // 3. Enable Transmitter (TE) and Receiver (RE)
    LPUART_CTRL |= (1 << 19) | (1 << 18); 
}

void uart_putc(char c) {
    // Wait until Transmit Data Register is empty (TDRE - Bit 23)
    while (!(LPUART_STAT & (1 << 23)));
    LPUART_DATA = c;
}

char uart_getc() {
    // Wait until Receive Data Register is full (RDRF - Bit 21)
    while (!(LPUART_STAT & (1 << 21)));
    return (char)(LPUART_DATA & 0xFF);
}

void uart_puts(const char* s) {
    while (*s) uart_putc(*s++);
}

void Reset_Handler(void) {
    main();
    while(1);
}

int main() {
    uart_init();
    uart_puts("S32K388 Echo Demo. Type something!\r\n");

    while (1) {
        // Echo: Receive a character and immediately send it back
        char c = uart_getc();
        
        // Optional: Convert lowercase to uppercase to prove processing
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        
        uart_putc(c);
    }
    return 0;
}
