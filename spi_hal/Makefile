CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m7 -mthumb -Wall -g -O0 -IHAL/spi -IHAL/uart

LDFLAGS = -mcpu=cortex-m7 -mthumb -T generic_cortex_m7.ld -nostartfiles

TARGET = spi_test

OBJS = HAL/spi/spi_hal.o \
       HAL/uart/lpuart_hal.o \
       src/spi_test.o

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	@echo "Build Successful"

HAL/spi/spi_hal.o: HAL/spi/spi_hal.c
	$(CC) $(CFLAGS) -c $< -o $@

HAL/uart/lpuart_hal.o: HAL/uart/lpuart_hal.c
	$(CC) $(CFLAGS) -c $< -o $@

src/spi_test.o: src/spi_test.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f HAL/spi/*.o HAL/uart/*.o src/*.o *.elf
