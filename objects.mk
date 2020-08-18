#
#	FreeRTOS portable layer for RaspberryPi
#
OBJECTS += $(BUILD_DIR)Source/portable/GCC/ARM_CA53_64_RASPI3/port.o
OBJECTS += $(BUILD_DIR)Source/portable/GCC/ARM_CA53_64_RASPI3/portASM.o

#
#	FreeRTOS Core
#
OBJECTS += $(BUILD_DIR)Source/list.o
OBJECTS += $(BUILD_DIR)Source/queue.o
OBJECTS += $(BUILD_DIR)Source/tasks.o
OBJECTS += $(BUILD_DIR)Source/timers.o

#
#	Interrupt Manager & GPIO Drivers
#
OBJECTS += $(BUILD_DIR)Demo/Drivers/irq.o
OBJECTS += $(BUILD_DIR)Demo/Drivers/gpio.o
OBJECTS += $(BUILD_DIR)Demo/Drivers/uart.o

$(BUILD_DIR)Source/portable/GCC/RaspberryPi/port.o: CFLAGS += -I $(BASE)Demo/

#
#	Selected HEAP implementation for FreeRTOS.
#
OBJECTS += $(BUILD_DIR)Source/portable/MemMang/heap_1.o

#
#	Startup and platform initialisation code.
#
OBJECTS += $(BUILD_DIR)Demo/boot.o
OBJECTS += $(BUILD_DIR)Demo/exception.o
OBJECTS += $(BUILD_DIR)Demo/FreeRTOS_IRQ.o

#
#	Main Test Program
#
OBJECTS += $(BUILD_DIR)Demo/main.o
