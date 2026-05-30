	CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m7 -mthumb -Wall -g -O0 -I../uart_hal/HAL/uart
LDFLAGS = -T src/generic_cortex_m7.ld -nostartfiles

TARGET = timer_alarm

OBJS = src/timer_alarm.o lpuart_hal.o

all: $(TARGET).elf


$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
	@echo "Build Successful: $@"


src/timer_test.o: src/timer_test.c
	$(CC) $(CFLAGS) -c src/timer_test.c -o $@


lpuart_hal.o: ../uart_hal/HAL/uart/lpuart_hal.c
	$(CC) $(CFLAGS) -c ../uart_hal/HAL/uart/lpuart_hal.c -o lpuart_hal.o


clean:
	rm -f src/*.o *.o *.elf
