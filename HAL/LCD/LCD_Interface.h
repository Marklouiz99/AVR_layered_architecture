#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


void LCD_voidInit(void);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidGotoxy(u8 Copy_u8X,u8 Copy_u8Y);
void LCD_voidPrintString(u8 *Copy_u8String);
void LCD_voidPrintNumber(u16 *Copy_u16Number);
void LCD_voidClearScreen(void);

#endif