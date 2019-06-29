/*
 * main.c
 *
 *  Created on: Mar 15, 2019
 *      Author: waheed
 */

#include "UART.h"
#include "DIO_Int.h"
#include <util/delay.h>
#include "LCD_Int.h"
#include "Bit_Math.h"
#include "avr/interrupt.h"
int main(void)
{
DIO_vidSetPinDirection(PORTD_Reg,PIN7,OUTPUT);
    //UART Initialization
	UART_vidInitialize();
	u16 u8DataReceived;
	LCD_vidInitialize();
	//LCD_vidWriteNumber(125);
	//DIO_vidSetPinValue(PORTD_Reg,PIN7,HIGH);
Set_Bit(SREG,SREG_I);

//UART_vidTx('a');
//UART_vidTx_string("ahmed");

	while(1)
	{

//LCD_vidWriteCommund(0x01);
		u8DataReceived=UART_vidRX();
        //LCD_vidWriteNumber(u8DataReceived);

		if(u8DataReceived == 'a')
		{
			DIO_vidSetPinValue(PORTD_Reg,PIN7,HIGH);
		}
		else
		{
			DIO_vidSetPinValue(PORTD_Reg,PIN7,LOW);
		}

		//UART_vidTx('1');
		//_delay_ms(1000);
		//UART_vidTx('2');
		_delay_ms(1000);
		//LCD_vidWriteNumber(12);
		//UART_vidTx('20');
		//_delay_ms(1000);

	}
}
