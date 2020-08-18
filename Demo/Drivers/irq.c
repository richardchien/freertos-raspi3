/*
 * Copyright (c) 2020 Institute of Parallel And Distributed Systems (IPADS), Shanghai Jiao Tong University (SJTU)
 * OS-Lab-2020 (i.e., ChCore) is licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *   http://license.coscl.org.cn/MulanPSL
 *   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 *   PURPOSE.
 *   See the Mulan PSL v1 for more details.
 */

#include "FreeRTOS.h"
#include "uart.h"
#include "machine.h"
#include "tools.h"
#include "timer.h"

/* Per core IRQ SOURCE MMIO address */
uint64_t core_irq_source[PLAT_CPU_NUM] = { CORE0_IRQ_SOURCE, CORE1_IRQ_SOURCE,
					   CORE2_IRQ_SOURCE, CORE3_IRQ_SOURCE };

void handle_irq(void)
{
	plat_handle_irq();

#if configUSE_PREEMPTION == 1
	vTaskSwitchContext();
#endif
}

static inline int ctzl(unsigned long x)
{
	return x == 0 ? sizeof(x) : __builtin_ctzl(x);
}

void plat_handle_irq(void)
{
	uint32_t cpuid = 0;
	unsigned int irq_src, irq;

	irq_src = get32(core_irq_source[cpuid]);
	irq = 1 << ctzl(irq_src);
	switch (irq) {
	case INT_SRC_TIMER3:
		handle_timer_irq();
		break;
	default:
		uart_puts("Unsupported IRQ");
	}
	return;
}
