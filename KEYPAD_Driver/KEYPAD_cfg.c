/*
 * KEYPAD_cfg.c
 *
 *  Created on: Dec 29, 2018
 *      Author: waheed
 */

#include "DIO_Int.h"
#include "KEYPAD_cfg.h"
u8 KEYPAD_R_port[KEYPAD_R_NUM]={PORTD_Reg,PORTD_Reg,PORTD_Reg,PORTD_Reg};
u8 KEYPAD_R_pin[KEYPAD_R_NUM]={PIN0,PIN1,PIN2,PIN3};
u8 KEYPAD_C_port[KEYPAD_C_NUM]={PORTD_Reg,PORTD_Reg,PORTD_Reg,PORTD_Reg};
u8 KEYPAD_C_pin[KEYPAD_C_NUM]={PIN4,PIN5,PIN6,PIN7};
