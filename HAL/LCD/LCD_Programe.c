#include"STD_TYPES.h"
#include"BitMath.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"LCD_Config.h"
#include"DIO_Config.h"
#include"avr/delay.h"


void LCD_voidInit(void)
{
	DIO_voidSetPinDirection(CONTROL_PINS_PORT,RS_PIN,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(CONTROL_PINS_PORT,RW_PIN,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(CONTROL_PINS_PORT,EN_PIN,PIN_OUTPUT_ID);
	DIO_voidSetPortDirection(DISPLAY_PINS_PORT,0xff);
	_delay_ms(30);
	LCD_voidWriteCommand(0b00111000);
	_delay_ms(2);
	LCD_voidWriteCommand(0b00001100);
	_delay_ms(2);
	LCD_voidWriteCommand(0b00000001);
}

void LCD_voidWriteCommand(u8 Copy_u8Command)
{
	/*RS=O*/
	DIO_voidSetPinValue(CONTROL_PINS_PORT,RS_PIN,PIN_LOW );
	/*RW=O*/
	DIO_voidSetPinValue(CONTROL_PINS_PORT,RW_PIN,PIN_LOW );
	/*Send Command*/
	DIO_voidSetPortValue(DISPLAY_PINS_PORT,Copy_u8Command);
	/*Enable Pulse*/
	DIO_voidSetPinValue(CONTROL_PINS_PORT,EN_PIN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CONTROL_PINS_PORT,EN_PIN,PIN_LOW );
}

void LCD_voidWriteData(u8 Copy_u8Data)
{
	/*RS=1--->pin0*/
    DIO_voidSetPinValue(CONTROL_PINS_PORT,RS_PIN,PIN_HIGH);
 	/*RW=0--->pin1*/
    DIO_voidSetPinValue(CONTROL_PINS_PORT,RW_PIN,PIN_LOW);
    /*Send Data*/
    DIO_voidSetPortValue(DISPLAY_PINS_PORT,Copy_u8Data);
    /*Enable Pulse*/
    DIO_voidSetPinValue(CONTROL_PINS_PORT,EN_PIN,PIN_HIGH);
	_delay_ms(2); //1 second delay
    DIO_voidSetPinValue(CONTROL_PINS_PORT,EN_PIN,PIN_LOW);
	
}
void LCD_voidGotoxy(u8 Copy_u8X,u8 Copy_u8Y)
{
   u8 Loc_Default=LINE1_ADRESS;
   if(Copy_u8X==Line1)
   {
	   Loc_Default=Loc_Default+Copy_u8Y;
   }
   else if(Copy_u8X==Line2)
   {
	   Loc_Default=Loc_Default+Copy_u8Y+LINE1_LENGTH;
   }
   LCD_voidWriteCommand(Loc_Default);
}
void LCD_voidPrintString(char *Copy_u8String)
{
	u8 i = 0;
	while(Copy_u8String[i])
	{
		LCD_voidWriteData(Copy_u8String[i]);
		i++;
		if(i == 16)
		{
			LCD_voidGotoxy(Line2,0);
		}
	}

/*	u8 i=0,c=0,k=0,LOC_Default=LINE1_ADRESS,LOC_Check=LINE1_ADRESS+LINE_TRUE_LENGTH;
	while(Copy_u8String[i]!='\0')
	{
		if(LOC_Default<=LOC_Check)
		{
			LCD_voidGotoxy(Line1,k);
			k++;
			LOC_Default++;
		}
		else if(LOC_Default>LOC_Check)
		{
			LCD_voidGotoxy(Line2,c);
			c++;
		}
		//LCD_voidWriteData(Copy_u8String[i]);
		i++;
	}*/
}
void LCD_voidPrintNumber(u8 *Copy_u16Number)
{
	u8 num_digits=0;
	u8 temp=*Copy_u16Number;
	while(temp!=0)
		{
			temp=temp/10;
			num_digits++;
		}
	while(*Copy_u16Number!=0)
	{
		u8 SentData=*Copy_u16Number;
		for(u8 i=0;i<num_digits;i++)
		{
			SentData=SentData%10;
		}
		LCD_voidWriteData(SentData+48);
		num_digits--;
		*Copy_u16Number=*Copy_u16Number/10;
	}
}
void LCD_voidClearScreen(void)
{
	LCD_voidWriteCommand(CLR_ADDRESS);
}
