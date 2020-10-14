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

uint64_t cnt_freq;
uint64_t cnt_tval;
uint64_t cnt_ctl;

void timer_init()
{
	put32(CORE0_TIMER_IRQCNTL, INT_SRC_TIMER3);

	/* Get timer frequency */
	asm volatile("mrs %0, cntfrq_el0" : "=r"(cnt_freq));

	/* Calculate TimerValue */
	cnt_tval = (cnt_freq / configTICK_RATE_HZ);

	/* Set TimerValue */
	asm volatile("msr cntv_tval_el0, %0" ::"r"(cnt_tval));

	/* Enable timer */
	cnt_ctl = 0 << 1 | 1; /* IMASK=0, ENABLE=1 */
	asm volatile("msr cntv_ctl_el0, %0" ::"r"(cnt_ctl));
}

void handle_timer_irq()
{
	asm volatile("msr cntv_tval_el0, %0" ::"r"(cnt_tval));
	// asm volatile("msr cntv_ctl_el0, %0" ::"r"(cnt_ctl));

	FreeRTOS_Tick_Handler();
}
