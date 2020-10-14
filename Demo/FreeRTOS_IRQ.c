#include "FreeRTOS.h"

#include "irq.h"
#include "timer.h"

void vSetupTickInterrupt()
{
	timer_init();
}

void vApplicationIRQHandler(uint32_t irq_src)
{
	handle_irq(irq_src);
}
