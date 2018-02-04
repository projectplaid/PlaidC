#ifndef __UART_H
#define __UART_H

#include "soc.h"

void uart_init(int baud, int bits);
void uart_write(char c);

#endif // __UART_H