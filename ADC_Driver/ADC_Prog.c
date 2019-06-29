/*
 * ADC_Prog.c
 *
 *  Created on: Jan 12, 2019
 *      Author: waheed
 */
#include "ADC_cfg.h"
#include "ADC_int.h"
#include "Bit_Math.h"
#include "ADC_Reg.h"
#include "STD_Tybes.h"


/*ADC Initialization */
void ADC_vidIntialize()
{
	/*select Vref value*/
#if ADC_VREF==ADC_VREF_AREF
	Clr_Bit(ADMUX,REFS0);
	Clr_Bit(ADMUX,REFS1);

#elif ADC_VREF == ADC_VREF_VCC
	Set_Bit(ADMUX,REFS0);
	Clr_Bit(ADMUX,REFS1);

#elif ADC_VREF == ADC_VREF_2500
	Set_Bit(ADMUX,REFS0);
	Set_Bit(ADMUX,REFS1);

#else
#error  "Wrong selection"

#endif

	/*Select Channel*/
#if ADC_CHANNEL == 0
	ADMUX&=~(0x1f);
#elif ADC_CHANNEL == 1;
	Set_Bit(ADMUX,MUX0);
#elif ADC_CHANNEL == 2;
	Set_Bit(ADMUX,MUX1);
#elif ADC_CHANNEL == 3;
	Set_Bit(ADMUX,MUX0);
	Set_Bit(ADMUX,MUX1);
#elif ADC_CHANNEL == 4;
	Set_Bit(ADMUX,MUX2);
#elif ADC_CHANNEL == 5;
	Set_Bit(ADMUX,MUX0);
	Set_Bit(ADMUX,MUX2);
#elif ADC_CHANNEL == 6;
	Set_Bit(ADMUX,MUX1);
	Set_Bit(ADMUX,MUX2);
#elif ADC_CHANNEL == 7;
	Set_Bit(ADMUX,MUX0);
	Set_Bit(ADMUX,MUX1);
	Set_Bit(ADMUX,MUX2);
#else
#error  "Wrong selection"

#endif

	/*Select Trigger Source */
#if ADC_CONVESION_MODE ==  ADC_CONV_FREE
	Clr_Bit(ADCSRA,ADATE);
#elif  ADC_CONVESION_MODE == ADC_CONV_ANALOG_COM
	Set_Bit(ADCSRA,ADATE);
	Set_Bit(SFIOR,ADTS0);
	Clr_Bit(SFIOR,ADTS1);
	Clr_Bit(SFIOR,ADTS2);
#elif  ADC_CONVESION_MODE == ADC_CONV_INT0
	Set_Bit(ADCSRA,ADATE);
	Clr_Bit(SFIOR,ADTS0);
	Set_Bit(SFIOR,ADTS1);
	Clr_Bit(SFIOR,ADTS2);
#elif  ADC_CONVESION_MODE == ADC_CONV_TIM0_COMP
	Set_Bit(ADCSRA,ADATE);
	Set_Bit(SFIOR,ADTS0);
	Set_Bit(SFIOR,ADTS1);
	Clr_Bit(SFIOR,ADTS2);
#elif  ADC_CONVESION_MODE == ADC_CONV_TIM0_OVF
	Set_Bit(ADCSRA,ADATE);
	Clr_Bit(SFIOR,ADTS0);
	Clr_Bit(SFIOR,ADTS1);
	Set_Bit(SFIOR,ADTS2);
#elif  ADC_CONVESION_MODE == ADC_CONV_TIM_COMP_B
	Set_Bit(ADCSRA,ADATE);
	Set_Bit(SFIOR,ADTS0);
	Clr_Bit(SFIOR,ADTS1);
	Set_Bit(SFIOR,ADTS2);

#elif  ADC_CONVESION_MODE == ADC_CONV_TIM1_OVF
	Set_Bit(ADCSRA,ADATE);
	Clr_Bit(SFIOR,ADTS0);
	Set_Bit(SFIOR,ADTS1);
	Set_Bit(SFIOR,ADTS2);


#elif  ADC_CONVESION_MODE == ADC_CONV_TIM1_ICU
	Set_Bit(ADCSRA,ADATE);
	Set_Bit(SFIOR,ADTS0);
	Set_Bit(SFIOR,ADTS1);
	Set_Bit(SFIOR,ADTS2);

#else
#error  "Wrong selection"
#endif

	/* Select Interrupt State */
#if ADC_INTERRUPT_STATE == ADC_INTERRUPT_ENABLE
	Set_Bit(ADCSRA,ADIE);
#elif ADC_INTERRUPT_STATE == ADC_INTERRUPT_DISABLE
	Clr_Bit(ADCSRA,ADIE);
#else
#error  "Wrong selection"
#endif

	/*Select Conversion Spedd*/
#if ADC_SPEED_MODE == ADC_FAST_MODE
	/*Prescler 2*/
	Set_Bit(ADCSRA,ADPS0);
	Clr_Bit(ADCSRA,ADPS1);
	Clr_Bit(ADCSRA,ADPS2);
#elif ADC_SPEED_MODE == ADC_NORMAL_MODE
	/*Prescler 16*/
	Clr_Bit(ADCSRA,ADPS0);
	Clr_Bit(ADCSRA,ADPS1);
	Set_Bit(ADCSRA,ADPS2);

#elif ADC_SPEED_MODE == ADC_LOW_MODE
	/*Prescler 64*/
	Clr_Bit(ADCSRA,ADPS0);
	Set_Bit(ADCSRA,ADPS1);
	Set_Bit(ADCSRA,ADPS2);
#else
#error  "Wrong selection"
#endif

	/*Left Adjustment */
	Set_Bit(ADMUX,ADLAR);
	//ADC Enable */
	Set_Bit(ADCSRA,ADEN);

}
void ADC_vidRead(u16 *pu16VoltValue)
{
	u16 u16CounterValue;
	/*start conversion*/
	Set_Bit(ADCSRA,ADSC);
#if ADC_INTERRUPT_STATE == ADC_INTERRUPT_DISABLE
	/*wait until conversion complete*/
	while(Get_Bit(ADCSRA,ADSC)==1);
	u16CounterValue=(ADCL>>6)+(4*ADCH);
	*pu16VoltValue=(u16CounterValue)*(5000/1023);
#endif

}


void ADC_vidChangeTrigerMode(u8 u8TriggeMode)
{
	switch(u8TriggeMode)
	{

	//Free Running mode
	case ADC_CONV_FREE:
		Clr_Bit(ADCSRA,ADATE);
		break;
		//Analog Comparator
	case ADC_CONV_ANALOG_COM:
		Set_Bit(ADCSRA,ADATE);
		Set_Bit(SFIOR,ADTS0);
		Clr_Bit(SFIOR,ADTS1);
		Clr_Bit(SFIOR,ADTS2);
		break;
		//External Interrupt Request 0
	case ADC_CONV_INT0:
		Set_Bit(ADCSRA,ADATE);
		Clr_Bit(SFIOR,ADTS0);
		Set_Bit(SFIOR,ADTS1);
		Clr_Bit(SFIOR,ADTS2);
		break;
		//Timer/Counter0 Compare Match
	case ADC_CONV_TIM0_COMP:
		Set_Bit(ADCSRA,ADATE);
		Set_Bit(SFIOR,ADTS0);
		Set_Bit(SFIOR,ADTS1);
		Clr_Bit(SFIOR,ADTS2);
		break;
		//Timer/Counter0 Overflow
	case ADC_CONV_TIM0_OVF:
		Set_Bit(ADCSRA,ADATE);
		Clr_Bit(SFIOR,ADTS0);
		Clr_Bit(SFIOR,ADTS1);
		Set_Bit(SFIOR,ADTS2);
		break;
		//Timer/Counter Compare Match B
	case ADC_CONV_TIM_COMP_B:
		Set_Bit(ADCSRA,ADATE);
		Set_Bit(SFIOR,ADTS0);
		Clr_Bit(SFIOR,ADTS1);
		Set_Bit(SFIOR,ADTS2);
		break;
		//Timer/Counter1 Overflow
	case ADC_CONV_TIM1_OVF:
		Set_Bit(ADCSRA,ADATE);
		Clr_Bit(SFIOR,ADTS0);
		Set_Bit(SFIOR,ADTS1);
		Set_Bit(SFIOR,ADTS2);
		break;
		//Timer/Counter1 Capture Event
	case ADC_CONV_TIM1_ICU:
		Set_Bit(ADCSRA,ADATE);
		Set_Bit(SFIOR,ADTS0);
		Set_Bit(SFIOR,ADTS1);
		Set_Bit(SFIOR,ADTS2);
		break;
		//Free Running mode
	default:
		Clr_Bit(ADCSRA,ADATE);
		break;
	}
}

void ADC_vidcontrolInterrupt(u8 u8InterruptState)
{
	if(u8InterruptState==1)
	{
		Set_Bit(ADCSRA,ADIE);
	}
	if(u8InterruptState==0)
	{
		Clr_Bit(ADCSRA,ADIE);
	}
	else
	{

	}
}

void ADC_vidChangeChannel(u8 u8ChannelID)
{
	switch(u8ChannelID)
	{
	case 0:
		ADMUX&=~(0x1f);
		break;
		//Channel 1
	case 1:
		Set_Bit(ADMUX,MUX0);
		break;
		//Channel 2
	case 2:
		Set_Bit(ADMUX,MUX1);
		break;
		//Channel 3
	case 3:
		Set_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX1);
		break;
		//Channel 4
	case 4:
		Set_Bit(ADMUX,MUX2);
		break;
		//Channel 5
	case 5:
		Set_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX2);
		break;
		//Channel 6
	case 6:
		Set_Bit(ADMUX,MUX1);
		Set_Bit(ADMUX,MUX2);
		break;
		//Channel 7
	case 7:
		Set_Bit(ADMUX,MUX0);
		Set_Bit(ADMUX,MUX1);
		Set_Bit(ADMUX,MUX2);
		break;

	default:
		//Channel 0
		ADMUX&=~(0x1f);
		break;
	}
}


