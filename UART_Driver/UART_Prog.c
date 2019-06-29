/*
 * UART_Prog.c
 *
 *  Created on: Mar 15, 2019
 *      Author: waheed
 */
#include <avr/io.h>
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "STD_Tybes.h"
#include <avr/interrupt.h>
#include <util/delay.h>
void UART_vidInitialize()
{
	/*7 bit UCSRC must be 1 in every operation*/
	/*Frame 8 Bit, Asynchronous Mode,Disable Parity Mode,1 Stop Bit	*/
	/*UCSRC=0b10000110 */
	UCSRC|=((1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1));
	Clr_Bit(UCSRB,UCSZ2);
	/*Baud Rate 9600*/
	UBRRL=77;
	/*Enable Receiver*/
	Set_Bit(UCSRB,RXEN);
	/*Enable Transmitter */
	Set_Bit(UCSRB,TXEN);
	//Set_Bit(UCSRB,UDRIE);
	Set_Bit(UCSRB,RXCIE);
	DIO_vidSetPinDirection(PORTD_Reg,PIN7,OUTPUT);
}

u8 UART_vidRX()
{
	DIO_vidSetPinDirection(PORTD_Reg,PIN7,OUTPUT);
	//Wait there are not unread data in the receive buffer
	while(Get_Bit(UCSRA,RXC)==0);
	DIO_vidSetPinValue(PORTD_Reg,PIN7,HIGH);
	//Save unread data
	return UDR;
}

void UART_vidTx(u8 u8Transmitdata)
{
	/*Wait transmit buffer is not empty*/
	while(Get_Bit(UCSRA,UDRE)==0);
	/*Send data*/
	UDR=u8Transmitdata;
	/*Wait until data in the transmit Shift Register shifted out */
	while(Get_Bit(UCSRA,TXC)==0);
	/*Clear Flag*/
	Set_Bit(UCSRA,TXC);

}

void UART_vidTx_string(u8 *pu8Data)
{
	u8 u8i;
	u8i=0;
	while(pu8Data[u8i]!='\0')
	{
		UART_vidTx(pu8Data[u8i]);
		u8i++;
	}

}
