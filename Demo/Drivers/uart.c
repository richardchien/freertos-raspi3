#include "regs.h"
#include "tools.h"

static void dummy(unsigned int value)
{
	(void)value;
	return;
}

static void uart_send(unsigned int c)
{
	//int i;
	while (1) {
		if (get32(AUX_MU_LSR_REG) & 0x20)
			break;
	}
	//for(i=0;i<0x7FF;i++);
	put32(AUX_MU_IO_REG, c);
}

void uart_init(void)
{
	unsigned int ra;

	put32(AUX_ENABLES, 1);
	put32(AUX_MU_IER_REG, 0);
	put32(AUX_MU_CNTL_REG, 0);
	put32(AUX_MU_LCR_REG, 3);
	put32(AUX_MU_MCR_REG, 0);
	put32(AUX_MU_IER_REG, 0);
	put32(AUX_MU_IIR_REG, 0xC6);
	put32(AUX_MU_BAUD_REG, 270);
	ra = get32(GPFSEL1);
	ra &= ~(7 << 12); //gpio14
	ra |= 2 << 12; //alt5
	ra &= ~(7 << 15); //gpio15
	ra |= 2 << 15; //alt5
	put32(GPFSEL1, ra);
	put32(GPPUD, 0);
	for (ra = 0; ra < 150; ra++)
		dummy(ra);
	put32(GPPUDCLK0, (1 << 14) | (1 << 15));
	for (ra = 0; ra < 150; ra++)
		dummy(ra);
	put32(GPPUDCLK0, 0);
	put32(AUX_MU_CNTL_REG, 3);
}

void uart_puts(char *s)
{
	while (*s != 0) {
		uart_send((unsigned int)*s);
		s++;
	}
	uart_send(0x0D);
	uart_send(0x0A);
}
