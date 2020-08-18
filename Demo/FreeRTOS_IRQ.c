#include "FreeRTOS.h"

#include "irq.h"
#include "timer.h"

void vSetupTickInterrupt()
{
	timer_init();
}

void vApplicationIRQHandler(uint32_t ulCORE0_INT_SRC)
{
	handle_irq();
}
