/*
 * UART.h
 *
 *  Created on: 13 may 2022
 *      Author: dell
 */

#ifndef UART_UART_H_
#define UART_UART_H_

extern void Configurar_UART4(uint32_t Baudrate);
extern char readChar(void);
extern void writeChar(char c);
//extern void writeString(char c * S);
extern void Configurar_PLL(uint32_t freq);
//extern void SetSystemClock(uint32_t freq)



#endif /* UART_UART_H_ */
