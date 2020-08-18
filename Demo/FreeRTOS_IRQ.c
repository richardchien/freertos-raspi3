/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

#include "Drivers/irq.h"
#include "Drivers/timer.h"

void vSetupTickInterrupt()
{
	uart_puts("vSetupTickInterrupt");

	timer_init();

	// 	// TODO: Configure the timer
	// 	unsigned long ulCompareMatch;

	// 	/* Calculate the match value required for our wanted tick rate. */
	// 	ulCompareMatch = 1000000 / configTICK_RATE_HZ;

	// /* Protect against divide by zero.  Using an if() statement still results
	// 	in a warning - hence the #if. */
	// #if portPRESCALE_VALUE != 0
	// 	{
	// 		ulCompareMatch /= (portPRESCALE_VALUE + 1);
	// 	}
	// #endif

	// 	irqBlock();

	// 	pRegs->CTL = 0x003E0000;
	// 	pRegs->LOD = 1000 - 1;
	// 	pRegs->RLD = 1000 - 1;
	// 	pRegs->DIV = portTIMER_PRESCALE;
	// 	pRegs->CLI = 0;
	// 	pRegs->CTL = 0x003E00A2;

	// 	irqRegister(64, vTickISR, NULL);

	// 	irqEnable(64);

	// 	irqUnblock();
}

// TODO: remove output
#include "Drivers/uart.h"

void vApplicationIRQHandler(uint32_t ulICCIAR)
{
	uart_puts("irq!!");
	// TODO: Configure the IRQHandler
	handle_irq();
}
