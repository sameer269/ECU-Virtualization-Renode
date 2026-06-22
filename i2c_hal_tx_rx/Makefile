CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m7 -mthumb -Wall -g -O0 -IHAL/i2c -IHAL/uart

LDFLAGS = -mcpu=cortex-m7 -mthumb -T generic_cortex_m7.ld -nostartfiles

TARGET = i2c_test

OBJS = HAL/i2c/i2c_hal.o \
       HAL/uart/lpuart_hal.o \
       src/i2c_test.o

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	@echo "Build Successful"

HAL/i2c/i2c_hal.o:
	$(CC) $(CFLAGS) -c HAL/i2c/i2c_hal.c -o HAL/i2c/i2c_hal.o

HAL/uart/lpuart_hal.o:
	$(CC) $(CFLAGS) -c HAL/uart/lpuart_hal.c -o HAL/uart/lpuart_hal.o

src/i2c_test.o:
	$(CC) $(CFLAGS) -c src/i2c_test.c -o src/i2c_test.o

clean:
	rm -f HAL/i2c/*.o HAL/uart/*.o src/*.o *.elf
