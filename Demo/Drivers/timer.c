/*
 * Copyright (c) 2020 Institute of Parallel And Distributed Systems (IPADS),
 * Shanghai Jiao Tong University (SJTU) OS-Lab-2020 (i.e., ChCore) is licensed
 * under the Mulan PSL v1. You can use this software according to the terms and
 * conditions of the Mulan PSL v1. You may obtain a copy of Mulan PSL v1 at:
 *   http://license.coscl.org.cn/MulanPSL
 *   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE. See the
 * Mulan PSL v1 for more details.
 */

#include "FreeRTOS.h"
#include "machine.h"
#include "tools.h"

uint64_t cntv_tval;

/* Per core IRQ SOURCE MMIO address */
uint64_t core_timer_irqcntl[PLAT_CPU_NUM] = { CORE0_TIMER_IRQCNTL,
					      CORE1_TIMER_IRQCNTL,
					      CORE2_TIMER_IRQCNTL,
					      CORE3_TIMER_IRQCNTL };

void timer_init(void)
{
	uint64_t cur_freq = 0;
	uint64_t cur_cnt = 0;
	uint64_t count_down = 0;
	uint64_t timer_ctl = 0;
	uint32_t cpuid = 0; // TODO: only use core 0 currenly

	/* Since QEMU only emulate the generic timer, we use the generic timer
	 * here */
	asm volatile("mrs %0, cntpct_el0" : "=r"(cur_cnt));
	asm volatile("mrs %0, cntfrq_el0" : "=r"(cur_freq));

	/* Calculate the tv */
	cntv_tval = (cur_freq / configTICK_RATE_HZ);

	/* set the timervalue here */
	asm volatile("msr cntv_tval_el0, %0" ::"r"(cntv_tval));
	asm volatile("mrs %0, cntv_tval_el0" : "=r"(count_down));

	put32(core_timer_irqcntl[cpuid], INT_SRC_TIMER3);

	/* Set the control register */
	timer_ctl = 0 << 1 | 1; /* IMASK = 0 ENABLE = 1 */
	asm volatile("msr cntv_ctl_el0, %0" ::"r"(timer_ctl));
	asm volatile("mrs %0, cntv_ctl_el0" : "=r"(timer_ctl));
	/* enable interrupt controller */
	return;
}

void plat_handle_timer_irq(void)
{
	asm volatile("msr cntv_tval_el0, %0" ::"r"(cntv_tval));
}

void plat_disable_timer(void)
{
	uint64_t timer_ctl = 0x0;
	asm volatile("msr cntv_ctl_el0, %0" ::"r"(timer_ctl));
}

void plat_enable_timer(void)
{
	uint64_t timer_ctl = 0x1;
	asm volatile("msr cntv_tval_el0, %0" ::"r"(cntv_tval));
	asm volatile("msr cntv_ctl_el0, %0" ::"r"(timer_ctl));
}

void handle_timer_irq(void)
{
	plat_handle_timer_irq();
	FreeRTOS_Tick_Handler();
}
