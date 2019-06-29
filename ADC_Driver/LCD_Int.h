/*
 * LCD_Init.h
 *
 *  Created on: Dec 28, 2018
 *      Author: waheed
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "STD_Tybes.h"
void LCD_vidWriteData(u8 u8Data);
void LCD_vidWriteCommund(u8 u8Commuand);
void LCD_vidInitialize(void);
void LCD_vidWriteDatgotoaxy(u8 u8x, u8 u8y);
void LCD_vidWriteString(u8 const *  pu8arr,u8 u8charnum);
void LCD_vidWriteNumber(u16 u16num);

#endif /* LCD_INT_H_ */
