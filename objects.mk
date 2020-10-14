#
#	FreeRTOS portable layer for RASPI3
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/GCC/RASPI3/port.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/GCC/RASPI3/portASM.o

#
#	FreeRTOS Core
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/croutine.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/event_groups.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/list.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/queue.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/stream_buffer.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/tasks.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/timers.o

#
#	Interrupt Manager & GPIO Drivers
#
OBJECTS += $(BUILD_DIR)Demo/Drivers/irq_asm.o
OBJECTS += $(BUILD_DIR)Demo/Drivers/irq.o
OBJECTS += $(BUILD_DIR)Demo/Drivers/timer.o
OBJECTS += $(BUILD_DIR)Demo/Drivers/tools.o
OBJECTS += $(BUILD_DIR)Demo/Drivers/uart.o

#
#	Useful Libraries
#
OBJECTS += $(BUILD_DIR)Demo/Libs/memory.o
OBJECTS += $(BUILD_DIR)Demo/Libs/printf.o

#
#	Selected HEAP implementation for FreeRTOS.
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/MemMang/heap_1.o

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
