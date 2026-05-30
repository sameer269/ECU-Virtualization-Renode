.syntax unified
.cpu cortex-m7
.thumb

.global _start
.global Reset_Handler

.section .isr_vector,"a",%progbits

.word _stack_top
.word Reset_Handler

.section .text

Reset_Handler:
_start:

    /* Copy data/init skipped for minimal demo */

    bl main

loop:
    b loop
