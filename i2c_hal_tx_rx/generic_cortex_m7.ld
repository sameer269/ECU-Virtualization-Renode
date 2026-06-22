ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00400000, LENGTH = 8M
    SRAM  (rwx) : ORIGIN = 0x20400000, LENGTH = 0xC0000
}

_stack_top = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
    } > FLASH

    .data :
    {
        *(.data*)
    } > SRAM AT > FLASH

    .bss :
    {
        *(.bss*)
        *(COMMON)
    } > SRAM
}
