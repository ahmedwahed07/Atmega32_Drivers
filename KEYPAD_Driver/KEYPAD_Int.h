/*
 * KEYPAD_int.h
 *
 *  Created on: Dec 29, 2018
 *      Author: waheed
 */


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#include "STD_Tybes.h"
void KEYPAD_vidInitialize(void);
u8 KEYPAD_vidRead(u8 *pu8addressvalue);

#define KEYPAD_OK  1
#define KEYPAD_NOK 0
#endif /* KEYPAD_INT_H_ */
