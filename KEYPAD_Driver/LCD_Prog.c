/*
 * LCD_Prog.c
 *
 *  Created on: Dec 28, 2018
 *      Author: waheed
 */
#include "STD_Tybes.h"
#include "DIO_Int.h"
#include "LCD_Confg.h"
#include <util/delay.h>

void LCD_vidWriteData(u8 u8Data)
{
	/* Set RS*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,HIGH);
	/* Rest R/W*/
	DIO_vidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	/* Data->data lines */
	DIO_vidSetPORTValue(LCD_DATAPORT,u8Data) ;
	/* Set Enable */
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,HIGH);
	/* delay 5 ms */
	_delay_ms(5);
	/* Rest Enable */
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,LOW);
}

void LCD_vidWriteCommund(u8 u8Commuand)
{
	/* Reset RS*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,LOW);
	/* Rest R/W*/
	DIO_vidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	/* Command->data lines*/
	DIO_vidSetPORTValue(LCD_DATAPORT,u8Commuand) ;
	/* Set Enable */
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,HIGH);
	//delay 5 ms
	_delay_ms(5);
	/* Reset Enable */
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,LOW);
}

void LCD_vidInitialize(void)
{
	/* Set RS Direction output */
	DIO_vidSetPinDirection(LCD_RSPORT,LCD_RSPIN,OUTPUT);
	/* set Enable Direction output */
	DIO_vidSetPinDirection(LCD_ENPORT,LCD_ENPIN,OUTPUT);
	/* set R/W Direction output*/
	DIO_vidSetPinDirection(LCD_RWPORT,LCD_RWPIN,OUTPUT);
	/* Set Data Direction output */
	DIO_vidSetPortDirection(LCD_DATAPORT,FULL_OUTPUT);
	//delay 50ms
	_delay_ms(50);
	/*(0b0 0 1 DL n f x x) DL=1>8bit mode, n=1>2lines , f=0>5*8pixcel */
	LCD_vidWriteCommund(0b00111000);
	//delay 2ms
	_delay_ms(2);
	//(00001DCB)Display on,cursor on,cursor blinking off
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
		//(1Adress)changeDDRAM to address
		LCD_vidWriteCommund((128+u8y));
	}
	if(u8x==1)
	{
		//second start from address 0x40(64)
		LCD_vidWriteCommund((128+64+u8y));
	}
}

void LCD_vidWriteString(u8  const*  pu8arr,u8 u8charnum)
{
	u8 i;
	for(i=0;i<u8charnum;i++){
		LCD_vidWriteData(pu8arr[i]);
	}

}

void LCD_vidWriteNumber(s16 s16num){
	u16 u16m=1;
	s16 i;
	u8 u8Digit;
	if(s16num<0)
	{
		LCD_vidWriteData('-');
		s16num=-s16num;
	}
	while(s16num/u16m >=10){
		u16m*=10;
	}
	for(i=u16m;i>=1;i/=10){
		u8Digit=(s16num/i)%10;
		LCD_vidWriteData(u8Digit+'0');
	}

	/*
	u8 x,y,z,m;
	x=(u8)(u16num/100);
	if(x !=0)
	{
		LCD_vidWriteData(x+'0');
	}
	y=(u8)(u16num-(x*100));
	z=(u8)(y/10);
	if(z!=0)
	{
	LCD_vidWriteData(z+'0');
	}
	m=y-(z*10);
	LCD_vidWriteData(m+'0');
	 */
}

