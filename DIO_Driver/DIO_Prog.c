/*
 * DIO_Prog.c
 *
 *  Created on: Dec 24, 2018
 *      Author: waheed
 */
#include "DIO_Reg.h"
#include "Bit_Math.h"
#include "DIO_Int.h"


void DIO_vidSetPortDirection(u8 port_no,u8 port_direction)
{
	switch(port_no)
	{
	case PORTA_Reg:
		DDRA=port_direction;
		break;

	case PORTB_Reg:
		DDRB=port_direction;
		break;

	case PORTC_Reg:
		DDRC=port_direction;
		break;

	case PORTD_Reg:
		DDRD=port_direction;
		break;

	default :
		DDRA=0xff;
		break;
	}
}

void DIO_vidSetPinDirection(u8 port_no, u8 pin_no, u8 pin_diection)
{
	if(pin_diection==OUTPUT)
	{
		switch(port_no){
		case PORTA_Reg:
			Set_Bit(DDRA,pin_no);
			break;
		case PORTB_Reg:
			Set_Bit(DDRB,pin_no);
			break;
		case PORTC_Reg:
			Set_Bit(DDRC,pin_no);
			break;

		case PORTD_Reg:
			Set_Bit(DDRD,pin_no);
			break;
		default:
			Clr_Bit(DDRA,PIN0);
			break;
		}
	}
	if(pin_diection==INPUT){

		switch(port_no){
		case PORTA_Reg:
			Clr_Bit(DDRA,pin_no);
			break;
		case PORTB_Reg:
			Clr_Bit(DDRB,pin_no);
			break;
		case PORTC_Reg:
			Clr_Bit(DDRC,pin_no);
			break;

		case PORTD_Reg:
			Clr_Bit(DDRD,pin_no);
			break;
		default:
			Clr_Bit(DDRA,PIN0);
			break;
		}
	}
	else
	{
		Clr_Bit(DDRA,PIN0);
	}
}

void DIO_vidSetPORTValue(u8 port_no,u8 port_value)
{
	switch(port_no)
	{
	case PORTA_Reg:
		PORTA=port_value;
		break;

	case PORTB_Reg:
		PORTB=port_value;
		break;

	case PORTC_Reg:
		PORTC=port_value;
		break;

	case PORTD_Reg:
		PORTD=port_value;
		break;

	default:
		PORTA=0xff;
		break;
	}
}

void DIO_vidSetPinValue(u8 port_no,u8 pin_no,u8 pin_value)
{
	if(pin_value==HIGH)
	{
		switch(port_no)
		{
		case PORTA_Reg:
			Set_Bit(PORTA,pin_no);
			break;
		case PORTB_Reg:
			Set_Bit(PORTB,pin_no);
			break;
		case PORTC_Reg:
			Set_Bit(PORTC,pin_no);
			break;

		case PORTD_Reg:
			Set_Bit(PORTD,pin_no);
			break;
		default:
			Clr_Bit(PORTA,PIN0);
			break;
		}
	}
	if(pin_value==LOW)
	{
		switch(port_no){
		case PORTA_Reg:
			Clr_Bit(PORTA,pin_no);
			break;
		case PORTB_Reg:
			Clr_Bit(PORTB,pin_no);
			break;
		case PORTC_Reg:
			Clr_Bit(PORTC,pin_no);
			break;

		case PORTD_Reg:
			Clr_Bit(PORTD,pin_no);
			break;
		default:
			Clr_Bit(PORTA,PIN0);
			break;
		}
	}
	else
	{
		Clr_Bit(PORTA,PIN0);
	}
}

u8 DIO_vidGetPortValue(u8 port_no)
{
	switch (port_no)
	{
	case PORTA_Reg:
		return PINA;
		break;

	case PORTB_Reg:
		return PINB;
		break;

	case PORTC_Reg:
		return PINC;
		break;

	case PORTD_Reg:
		return PIND;
		break;

	default:
		return 0;
	}
}

u8 DIO_vidGetPinValue(u8 port_no, u8 pin_no)
{

	switch (port_no){
	case PORTA_Reg:
		return Get_Bit(PINA,pin_no);
		break;

	case PORTB_Reg:
		return Get_Bit(PINB,pin_no);
		break;

	case PORTC_Reg:
		return Get_Bit(PINC,pin_no);
		break;

	case PORTD_Reg:
		return Get_Bit(PIND,pin_no);
		break;

	default:
		return 0xff;
	}
}
void DIO_vidTogglePin(u8 u8Port_NO,u8 u8Pin_NO)
{
	switch (u8Port_NO)
	{
	case PORTA_Reg:
		Toggle_Bit(PORTA,u8Pin_NO);
		break;

	case PORTB_Reg:
		Toggle_Bit(PORTB,u8Pin_NO);
		break;

	case PORTC_Reg:
		Toggle_Bit(PORTC,u8Pin_NO);
		break;

	case PORTD_Reg:
		Toggle_Bit(PORTD,u8Pin_NO);
		break;

	default:
		break;
	}
}
