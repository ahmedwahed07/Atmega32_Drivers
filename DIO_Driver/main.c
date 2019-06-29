
/*
 * main.c
 *
 *  Created on: Dec 24, 2018
 *      Author: waheed
 */

#include <util/delay.h>
#include "DIO_Int.h"


int main()
{
	/* set switch input */
	DIO_vidSetPinDirection(PORTB_Reg,PIN4,INPUT);
	/* pull up resistor */
	DIO_vidSetPinValue(PORTB_Reg,PIN4,HIGH);
	/* led output */
	DIO_vidSetPinDirection(PORTD_Reg,PIN7,OUTPUT);

	while(1)
	{
			DIO_vidTogglePin(PORTD_Reg,PIN7);
			_delay_ms(700);
	}
	return 0;
}
