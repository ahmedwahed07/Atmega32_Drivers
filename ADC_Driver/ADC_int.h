/*
 * ADC_init.h
 *
 *  Created on: Jan 12, 2019
 *      Author: waheed
 */


#ifndef ADC_INT_H_
#define ADC_INT_H_
#include "STD_Tybes.h"

void ADC_vidIntialize();
void ADC_vidRead(u16 *pu16VoltValue);
void ADC_vidChangeTrigerMode(u8 TriggeMode);
void ADC_vidcontrolInterrupt(u8 u8InterruptState);
void ADC_vidChangeChannel(u8 u8ChannelID);

/* AREF Voltage Reference Selections for ADC */
/* External voltage Reference */
#define ADC_VREF_AREF               0
/*AVCC with external capacitor at AREF pin */
#define ADC_VREF_VCC                1
/* Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
#define ADC_VREF_2500               2

//ADC Trigger Mode
#define ADC_CONV_FREE               0
#define ADC_CONV_INT0               1
#define ADC_CONV_ANALOG_COM         2
#define ADC_CONV_TIM0_COMP          3
#define ADC_CONV_TIM0_OVF           4
#define ADC_CONV_TIM_COMP_B         5
#define ADC_CONV_TIM1_OVF           6
#define ADC_CONV_TIM1_ICU           7

#define ADC_INTERRUPT_ENABLE        1
#define ADC_INTERRUPT_DISABLE       0


#define ADC_FAST_MODE               0
#define ADC_NORMAL_MODE             1
#define ADC_LOW_MODE                2

#endif /* ADC_INT_H_ */
