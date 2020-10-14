ASFLAGS += -march=armv8-a+nofp
CFLAGS += -march=armv8-a+nofp -g -Wall -w -nostdlib -nostartfiles -ffreestanding -Werror

CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/RASPI3/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -I $(BASE)Demo/Drivers/
CFLAGS += -I $(BASE)Demo/Libs/
CFLAGS += -I $(BASE)Demo/

TOOLCHAIN=aarch64-linux-gnu-
