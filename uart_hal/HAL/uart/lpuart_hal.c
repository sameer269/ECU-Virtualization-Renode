#include "lpuart_hal.h"

void LPUART_HAL_Init(LPUART_Type* base, uint32_t sbr) {

    // Skip real hardware config (Renode workaround)

    // Force-enable transmitter manually
    *(volatile uint32_t*)((uint32_t)base + 0x08) = 0x1;

    // Small delay
    for(volatile int i = 0; i < 1000; i++);
}

// --- Modified for Renode ---
bool LPUART_HAL_IsTransmitReady(LPUART_Type* base) {
    // In Renode, always assume ready
    return true;
}

// --- Modified for Renode ---
bool LPUART_HAL_IsReceiveReady(LPUART_Type* base) {
    // No real RX hardware → always false
    return false;
}

// --- CRITICAL FIX ---
void LPUART_HAL_WriteByte(LPUART_Type* base, uint8_t data) {
    // Removed blocking wait
        *(volatile uint32_t*)((uint32_t)base + 0x00) = data;

    // Small delay to simulate hardware timing
    for(volatile int i = 0; i < 1000; i++);
}

// --- Optional (safe version) ---
uint8_t LPUART_HAL_ReadByte(LPUART_Type* base) {
    // No real RX → return dummy value
    return 0;
}
