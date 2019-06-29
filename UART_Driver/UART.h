/*
 * UART.h
 *
 *  Created on: Mar 15, 2019
 *      Author: waheed
 */

#ifndef UART_H_
#define UART_H_
#include "STD_Tybes.h"
void UART_vidInitialize();
void UART_vidTx(u8 u8Transmitdata);
u8 UART_vidRX();
void UART_vidTx_string(u8 *);
char UART_recievechar();

#endif /* UART_H_ */
