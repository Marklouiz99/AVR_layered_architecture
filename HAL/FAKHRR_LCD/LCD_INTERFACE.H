#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H



void LCD_voidInit(void);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteDATA(u8 Copy_u8DATA);
void LCD_GoToXY(u8 X, u8 Y);
void LCD_voidWriteSting(u8 *Copy_u8string);

#endif
