# Toolchain definition
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# CPU specific flags
CPU_FLAGS = -mcpu=cortex-m7 -mthumb

# Directories
HAL_DIR = HAL/uart

# Compilation flags
# -I$(HAL_DIR) tells the compiler to look in HAL/uart for header files
CFLAGS  = $(CPU_FLAGS) -Wall -g -O0 -I$(HAL_DIR) -c
LDFLAGS = $(CPU_FLAGS) -T generic_cortex_m7.ld -nostartfiles

# Project files
TARGET = uart_hal_test
OBJS = lpuart_hal.o uart_enhanced_test.o

# Default target
all: $(TARGET).elf

# Link stage
$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	@echo "Build Successful: $@"

# Compile lpuart_hal.c from the HAL/uart directory
lpuart_hal.o: $(HAL_DIR)/lpuart_hal.c $(HAL_DIR)/lpuart_hal.h
	$(CC) $(CFLAGS) $(HAL_DIR)/lpuart_hal.c -o $@

# Compile uart_hal_test.o (main app)
uart_enhanced_test.o: uart_enhanced_test.c $(HAL_DIR)/lpuart_hal.h
	$(CC) $(CFLAGS) uart_enhanced_test.c -o $@

# Clean utility
clean:
	rm -f *.o *.elf
