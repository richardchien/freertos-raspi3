#pragma once

void uart_init(void);
unsigned int uart_recv(void);
void uart_send(unsigned int c);
void uart_send_string(char *str);
void uart_putc(char c);
