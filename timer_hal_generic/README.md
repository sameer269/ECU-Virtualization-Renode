# Week 3 - Generic PIT HAL Implementation

## Objective
Convert the timer HAL from a fixed PIT0 implementation to a generic PIT driver supporting all PIT instances available in S32K388.

## Supported Instances

- PIT0
- PIT1
- PIT2
- PIT3

## Base Addresses

| Instance | Base Address |
|-----------|-------------|
| PIT0 | 0x400B0000 |
| PIT1 | 0x400B4000 |
| PIT2 | 0x402FC000 |
| PIT3 | 0x40300000 |

## HAL APIs

```c
TIMER_HAL_Init(instance, loadValue);
TIMER_HAL_Start(instance);
TIMER_HAL_Stop(instance);
TIMER_HAL_IsExpired(instance);
