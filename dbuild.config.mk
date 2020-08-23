#ASFLAGS += -mcpu=cortex-a8
ASFLAGS += -march=armv8-a
#CFLAGS += -mcpu=cortex-a8 -g -Wall -w
CFLAGS += -march=armv8-a -g -Wall -w -nostdlib -nostartfiles -ffreestanding
#-Wextra

CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/ARM_CA53_64_RASPI3/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -I $(BASE)Demo/Drivers/
CFLAGS += -I $(BASE)Demo/

TOOLCHAIN=aarch64-linux-gnu-
#TOOLCHAIN=arm-none-eabi-
