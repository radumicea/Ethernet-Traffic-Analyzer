/*****************************************************************************
 * uart.h
 *****************************************************************************/

#ifndef __UART_H__
#define __UART_H__

#include "shared.h"

// SCLK is 50 MHz by default
// Needed baud rate is 9600 so
// Divisor is calculated after the formula:
// SCLK / (16 * Divisor)
#define DIVISOR 325
void initUart(void);
void uartWriteByte(byte_t b);
byte_t uartReadByte(void);

#endif /* __UART_H__ */
