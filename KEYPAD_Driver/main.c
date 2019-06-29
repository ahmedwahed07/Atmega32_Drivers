/*
 * main.c
 *
 *  Created on: Dec 29, 2018
 *      Author: waheed
 */
#include "DIO_Int.h"
#include "KEYPAD_Int.h"
#include "LCD_Int.h"
#include <util/delay.h>
int main(void)
{
	u8 u8read;
	u8 u8readstatus;

	//initialization
	KEYPAD_vidInitialize();
	LCD_vidInitialize();
	//LCD_vidWriteData('A');
	u8 arr[16];
	u8 i=0;
	u8 res=0;
	while(1)
	{
		u8readstatus=KEYPAD_vidRead(&u8read);
		if(u8readstatus==KEYPAD_OK)
		{
			LCD_vidWriteData(u8read);
			arr[i]=u8read;
			if(arr[i] == '=')
			{
				res=arr[0]+arr[2];
				//LCD_vidWriteDatgotoaxy(1,0);
                 LCD_vidWriteNumber(res-96);
			}
			i++;
		}
		else
		{

		}
	}
}
