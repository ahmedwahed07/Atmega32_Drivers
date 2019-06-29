/*
 * LCD_Prog.c
 *
 *  Created on: Dec 28, 2018
 *      Author: waheed
 */
//#define F_CPU 12000000
#include "STD_tybes.h"
#include "LCD_Confg.h"
#include "DIO_Int.h"
#include <util/delay.h>

void LCD_vidWriteData(u8 u8Data)
{
	// RS=1
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,HIGH);
	// R/W=0
	DIO_vidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	// Data->data lines
	DIO_vidSetPORTValue(LCD_DATAPORT,u8Data) ;
	//Enable=1
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,HIGH);
	//delay 5 ms
	_delay_ms(5);
	//Disable
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,LOW);
}

void LCD_vidWriteCommund(u8 u8Commuand)
{
	// RS=0
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,LOW);
	// R/W=0
	DIO_vidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	// Command->data lines
	DIO_vidSetPORTValue(LCD_DATAPORT,u8Commuand) ;
	///Enable=1
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,HIGH);
	//delay 5 ms
	_delay_ms(5);
	//Disable
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,LOW);
}

void LCD_vidInitialize(void)
{
	//RS Direction output
	DIO_vidSetPinDirection(LCD_RSPORT,LCD_RSPIN,OUTPUT);
	//Enable Direction output
	DIO_vidSetPinDirection(LCD_ENPORT,LCD_ENPIN,OUTPUT);
	//R/E Direction output
	DIO_vidSetPinDirection(LCD_RWPORT,LCD_RWPIN,OUTPUT);
	//Data Direction output
	DIO_vidSetPortDirection(LCD_DATAPORT,FULL_OUTPUT);
	//delay 50ms
	_delay_ms(50);
	//(0b0011nfxx)2 lines ,5*8pixcel
	LCD_vidWriteCommund(0b00111000);
	//delay 2ms
	_delay_ms(2);
	//(00001DCA)Display on,cursor on,cursor blinking
	LCD_vidWriteCommund(0b00001110);
	//delay 2ms
	_delay_ms(2);
	//Clear command
	LCD_vidWriteCommund(0b00000001);
	//delay 2ms
	_delay_ms(50);

}
void LCD_vidWriteDatgotoaxy(u8  u8x,u8 u8y)
{
	//0 means first row
	if(u8x==0)
	{
		//(1(Adress))changeDDRAM to address
		LCD_vidWriteCommund((128+u8y));
	}
	if(u8x==1)
	{
		//second start from address 0x40(64)
		LCD_vidWriteCommund((128+64+u8y));
	}
}

void LCD_vidWriteString(char *pu8arr,u8 u8charnum)
{
	u8 i;
	for(i=0;i<u8charnum;i++){
		LCD_vidWriteData(pu8arr[i]);
	}

}
void LCD_vidWriteNumber(u16 u16num){
	u16 m=1;
	u16 u16i;
	u8 u16Digit;
	while(u16num/m >=10){
		m*=10;
	}
	for(u16i=m;u16i>=1;u16i/=10){
		u16Digit=(u16num/u16i)%10;
		LCD_vidWriteData(u16Digit+'0');
	}

}
