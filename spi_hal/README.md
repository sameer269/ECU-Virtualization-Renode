# SPI HAL Implementation on S32K388 using Renode

## Overview

This project demonstrates SPI (Serial Peripheral Interface) communication on the NXP S32K388 platform using Renode simulation.

A simple SPI HAL (Hardware Abstraction Layer) was developed and validated through UART debug messages. The application periodically transmits SPI data and displays the transmission status through the UART analyzer.

---

## Features

- SPI HAL implementation
- UART HAL implementation
- SPI data transmission
- UART-based debugging
- Renode simulation support
- S32K388 platform support

---

## Project Structure

spi_hal/

├── HAL/

│ ├── spi/

│ │ ├── spi_hal.c

│ │ └── spi_hal.h

│ └── uart/

│ ├── lpuart_hal.c

│ └── lpuart_hal.h

├── src/

│ └── spi_test.c

├── renode/

│ └── run.resc

├── generic_cortex_m7.ld

├── Makefile

└── README.md

---

## Tested Environment

- Renode v1.16.1
- NXP S32K388
- ARM GCC Toolchain

---

## Build Instructions

```bash
make clean
make
