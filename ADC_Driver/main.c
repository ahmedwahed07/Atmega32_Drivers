
/*
 * main.c
 *
 *  Created on: Jan 12, 2019
 *      Author: waheed
 */
#include "ADC_int.h"
#include "LCD_Int.h"
#include <util/delay.h>
void TEMP_vidConvertVolttoTemp(u16 u16volt,u16 *pu16temp);

int main()
{
	u16 u16Read;
	u16 u16Temp;
	ADC_vidIntialize();
	LCD_vidInitialize();
	//LCD_vidWriteString("ahmed",5);

	while(1)
	{
		//ADC_vidcontrolInterrupt(ADC_INTERRUPT_ENABLE);
		ADC_vidChangeChannel(0);
		ADC_vidRead(&u16Read);
		LCD_vidWriteNumber(u16Read);
		TEMP_vidConvertVolttoTemp(u16Read,&u16Temp);
		LCD_vidWriteDatgotoaxy(1,0);
		LCD_vidWriteNumber(u16Temp);
		_delay_ms(1000);
		LCD_vidWriteCommund(0x01);
		//_delay_ms(10);
	}
}

void TEMP_vidConvertVolttoTemp(u16 u16volt,u16 *pu16temp)
{
	*pu16temp=u16volt/10;
}

