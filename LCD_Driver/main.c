/*
 * main.c
 *
 *  Created on: Dec 28, 2018
 *      Author: waheed
 */

#include "LCD_Int.h"
#include <util/delay.h>
void RightLeft();
void sinusoidalwave();
int main(){
	LCD_vidInitialize();
	LCD_vidWriteDatgotoaxy(0,0);
	LCD_vidWriteString("Bib",3);
	//LCD_vidWriteNumber(214);
	while(1){

		//RightLeft();
		//sinusoidalwave();
	}
}

void RightLeft(){
	u8 i;
	for(i=0;i<=11;i++)
	{
		LCD_vidWriteDatgotoaxy(0,i);
		LCD_vidWriteString("Ahmed",5);
		_delay_ms(10000);
		LCD_vidWriteCommund(00000001);
		_delay_ms(50);
	}
	for(i=11;i>=0;i--)
	{

		LCD_vidWriteDatgotoaxy(0,i);
		LCD_vidWriteString("Ahmed",5);
		_delay_ms(10000);
		LCD_vidWriteCommund(00000001);
		_delay_ms(50);
		if(i==0)
		{
			break;
		}
	}
}


void sinusoidalwave(){
	u8 i;
	u8 j=0;
	for(i=0;i<11;i+=5)
			{
				if(j>1)
				{
					j=0;
				}
				LCD_vidWriteDatgotoaxy(j,i);
				LCD_vidWriteString("Ahmed",5);
				_delay_ms(10000);
				LCD_vidWriteCommund(00000001);
				_delay_ms(50);
				++j;
			}
			j=0;
}
