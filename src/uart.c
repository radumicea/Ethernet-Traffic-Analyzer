/*****************************************************************************
 * uart.c
 *****************************************************************************/

#include "uart.h"

void initUart(void)
{
	*pUART0_GCTL = UCEN;
	*pUART0_LCR = DLAB;
	*pUART0_DLL = DIVISOR & 0xFF;
	*pUART0_DLH = (DIVISOR >> 8) & 0xFF;

	*pUART0_LCR = 0x03;
}

void uartWriteByte(byte_t b)
{
	while (!(*pUART0_LSR & THRE));
	*pUART0_THR = b;
}

byte_t uartReadByte(void)
{
	while (!(*pUART0_LSR & DR));
	byte_t b = *pUART0_RBR;
	return b;
}
