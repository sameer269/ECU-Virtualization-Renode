ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x400000, LENGTH = 2M
    RAM (rwx)  : ORIGIN = 0x20400000, LENGTH = 256K
}

_stack_top = ORIGIN(RAM) + LENGTH(RAM);

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
    } > RAM

    .bss :
    {
        *(.bss*)
        *(COMMON)
    } > RAM
}
