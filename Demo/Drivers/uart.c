#include "machine.h"
#include "tools.h"

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
	ra = get32(BCM2835_GPIO_GPFSEL1);
	ra &= ~(7 << 12); //gpio14
	ra |= 2 << 12; //alt5
	ra &= ~(7 << 15); //gpio15
	ra |= 2 << 15; //alt5
	put32(BCM2835_GPIO_GPFSEL1, ra);
	put32(BCM2835_GPIO_GPPUD, 0);
	delay(150);
	put32(BCM2835_GPIO_GPPUDCLK0, (1 << 14) | (1 << 15));
	delay(150);
	put32(BCM2835_GPIO_GPPUDCLK0, 0);
	put32(AUX_MU_CNTL_REG, 3);
}

static unsigned int uart_lsr(void)
{
	return get32(AUX_MU_LSR_REG);
}

unsigned int uart_recv(void)
{
	while (1) {
		if (uart_lsr() & 0x01)
			break;
	}
	return get32(AUX_MU_IO_REG) & 0xFF;
}

void uart_send(unsigned int c)
{
	while (1) {
		if (uart_lsr() & 0x20)
			break;
	}
	put32(AUX_MU_IO_REG, c);
}

void uart_send_string(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		uart_send((char)str[i]);
}

void uart_putc(char c)
{
	uart_send(c);
}
