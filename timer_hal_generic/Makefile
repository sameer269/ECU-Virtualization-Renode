CC=arm-none-eabi-gcc

CFLAGS=-mcpu=cortex-m7 \
-mthumb \
-Wall \
-g \
-O0 \
-IHAL/timer \
-IHAL/uart

LDFLAGS=-T generic_cortex_m7.ld \
-nostartfiles

OBJ=HAL/timer/timer_hal.o \
HAL/uart/lpuart_hal.o \
src/timer_test.o


all: timer_test.elf
	@echo "Build Successful"

timer_test.elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f HAL/timer/*.o HAL/uart/*.o src/*.o *.elf
