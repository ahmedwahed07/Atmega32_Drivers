/*
 * KEYPAD_prog.c
 *
 *  Created on: Dec 29, 2018
 *      Author: waheed
 */

#include "KEYPAD_cfg.h"
#include "DIO_Int.h"
#include "KEYPAD_Int.h"
#include <util/delay.h>
#include "STD_Tybes.h"

u8 KEYPAD_MAPPing[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};

void KEYPAD_vidInitialize(void)
{

	u8 	u8counter_R=0;
	u8 	u8counter_C=0;
	for(u8counter_R=0;u8counter_R<KEYPAD_R_NUM;u8counter_R++){
		/*Set row input */
		DIO_vidSetPinDirection(KEYPAD_R_port[u8counter_R],KEYPAD_R_pin[u8counter_R],INPUT);
		/* Set pull up resistor */
		DIO_vidSetPinValue(KEYPAD_R_port[u8counter_R],KEYPAD_R_pin[u8counter_R],HIGH);
	}

	for(u8counter_C=0;u8counter_C<KEYPAD_C_NUM;u8counter_C++){
		/* Set column output */
		DIO_vidSetPinDirection(KEYPAD_C_port[u8counter_C],KEYPAD_C_pin[u8counter_C],OUTPUT);
	}

}

u8 KEYPAD_vidRead(u8 *pu8addressvalue)
{
	u8 	u8counter_C=0;
	u8 	u8counter_R=0;
	u8  u8Readvalue=0;
	for(u8counter_C=0;u8counter_C<KEYPAD_C_NUM;u8counter_C++)
	{
		/* First set high to all columns (1111) */
		DIO_vidSetPinValue(KEYPAD_C_port[u8counter_C],KEYPAD_C_pin[u8counter_C],HIGH);
	}

	for(u8counter_C=0;u8counter_C<KEYPAD_C_NUM;u8counter_C++)
	{
		/* 0111,1011,1101,1110 */
		DIO_vidSetPinValue(KEYPAD_C_port[u8counter_C],KEYPAD_C_pin[u8counter_C],LOW);
		for(u8counter_R=0;u8counter_R<KEYPAD_R_NUM;u8counter_R++)
		{
			u8Readvalue=DIO_vidGetPinValue(KEYPAD_R_port[u8counter_R],KEYPAD_R_pin[u8counter_R]);
			if(u8Readvalue==LOW){
				_delay_ms(500);
				*pu8addressvalue=KEYPAD_MAPPing[u8counter_R][u8counter_C];
				while(u8Readvalue==LOW){
					u8Readvalue=DIO_vidGetPinValue(KEYPAD_R_port[u8counter_R],KEYPAD_R_pin[u8counter_R]);
				}
				return KEYPAD_OK;
			}
		}
		DIO_vidSetPinValue(KEYPAD_C_port[u8counter_C],KEYPAD_C_pin[u8counter_C],HIGH);
	}
	return KEYPAD_NOK;
}
