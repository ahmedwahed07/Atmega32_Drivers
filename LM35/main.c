/*
 * main.c
 *
 *  Created on: Jan 11, 2019
 *      Author: waheed
 */
//#define F_CPU 12000000
#include <avr/interrupt.h>
#include "Bit_Math.h"
#include "LCD_Int.h"
#include <util/delay.h>
void ADC_vidRead(u16 *voltptr);
void ADC_vidInitalize();
void TEMP_vidConvertVolttoTemp(u16 u16volt,u16 *pu16temp);
int main(void)
{
	/* LCD Initialization */
	LCD_vidInitialize();
	/*ADC Initialization*/
	ADC_vidInitalize();
	u16 u16Read;
	u16	u16temp;

	//LCD_vidWriteString("ahmed",5);
	while(1)
	{
		ADC_vidRead(&u16Read);
		LCD_vidWriteNumber(u16Read);
		TEMP_vidConvertVolttoTemp(u16Read,&u16temp);
		LCD_vidWriteDatgotoaxy(1,0);
		LCD_vidWriteNumber(u16temp);
		_delay_ms(500);
		LCD_vidWriteCommund(0x01);
		_delay_ms(20);
	}
}

void ADC_vidInitalize()
{
	/*ADC pin input */
	Clr_Bit(PORTA,PIN0);
	//set reference VCC
	Set_Bit(ADMUX,REFS0);
	//set left adjust
	Set_Bit(ADMUX,ADLAR);
	//set ADC channel ,ADC0 MUX4:0=0

	//ADC Perscaler 16
	Set_Bit(ADCSRA,ADPS2);

	//enable ADC
	Set_Bit(ADCSRA,ADEN);

}

void ADC_vidRead(u16 *voltptr)
{
	u16 u16CounterValue;
	//start conversion
	Set_Bit(ADCSRA,ADSC);
	//wait conversion
	while(Get_Bit(ADCSRA,ADSC)==1);
	//read step number
	//u16CounterValue=ADC;
	u16CounterValue=((u16)(ADCL>>6))+((((u16)ADCH)*4));
	//convert from step number to voltage value
	*voltptr=(u16CounterValue)*(5000/1023);
	//*voltptr=((u16CounterValue*5000)/1023);
}

void TEMP_vidConvertVolttoTemp(u16 u16volt,u16 *pu16temp)
{
	*pu16temp=u16volt/10;
}
