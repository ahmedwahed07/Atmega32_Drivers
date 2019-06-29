/*
 * DIO_Init.h
 *
 *  Created on: Dec 24, 2018
 *      Author: waheed
 */


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "STD_Types.h"

#define PORTA_Reg        0
#define PORTB_Reg        1
#define PORTC_Reg        2
#define PORTD_Reg        3

#define PIN0             0
#define PIN1             1
#define PIN2             2
#define PIN3             3
#define PIN4             4
#define PIN5             5
#define PIN6             6
#define PIN7             7

#define OUTPUT           1
#define INPUT            0

#define HIGH             1
#define LOW              0

#define FULL_OUTPUT      0xff
#define FULL_INPUT       0x00

#define FULL_HIGH      0xff
#define FULL_LOW       0x00

void DIO_vidSetPortDirection(u8 port_no,u8 port_direction);
void DIO_vidSetPinDirection(u8 port_no,u8 pin_no,u8 pin_diection);
void DIO_vidSetPORTValue(u8 port_no,u8 port_value);
void DIO_vidSetPinValue(u8 port_no,u8 pin_no,u8 port_value);
u8 DIO_vidGetPortValue(u8 port_no);
u8 DIO_vidGetPinValue(u8 port_no,u8 pin_no);
void DIO_vidTogglePin(u8 u8Port_NO,u8 u8Pin_NO);

#endif /* DIO_INT_H_ */
