#include "FreeRTOS.h"
#include "task.h"

#include "irq.h"
#include "uart.h"
#include "printf.h"

void task1(void *arg)
{
	while (1) {
		printf("task 1\n");
		vTaskDelay(100);
	}
}

void task2(void *arg)
{
	while (1) {
		printf("task 2\n");
		vTaskDelay(300);
	}
}

/**
 *	This is the systems main entry, some call it a boot thread.
 *
 *	-- Absolutely nothing wrong with this being called main(), just it doesn't have
 *	-- the same prototype as you'd see in a linux program.
 **/
void main(void)
{
	uart_init();
	printf("hello\n");

	xTaskCreate(task1, "TASK_0", 128, NULL, 0, NULL);
	xTaskCreate(task2, "TASK_1", 128, NULL, 0, NULL);

	vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while (1) {
		;
	}
}
