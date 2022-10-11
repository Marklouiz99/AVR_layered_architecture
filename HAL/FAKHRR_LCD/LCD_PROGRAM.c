#include <util/delay.h>
#include "Std_Types.h"
#include "Macros.h"
#include "DIO_PRIVATE.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"




void LCD_voidInit(void)
{ 


    /* Set Pin Direction*/ 
    DIO_voidSetPinDirection(PORTB_ID,PIN0_ID, 1);
    DIO_voidSetPinDirection(PORTB_ID,PIN1_ID, 1);
    DIO_voidSetPinDirection(PORTB_ID,PIN2_ID, 1);

    /*Set Port Direction*/
    DIO_voidSetPortDirection(PORTB_ID,0b11111111);
    /*Delay 30*/ 
	_delay_ms(30);
    /* Send Command Function Set*/
	LCD_voidWriteCommand(0b00111000);
    /*Delay 2*/
	_delay_ms(2);
    /*Send Command Display on/off*/
	LCD_voidWriteCommand(0b00001100);
    /*Delay 2ms*/
	_delay_ms(2);
    /*Send Command Clear Display*/
	LCD_voidWriteCommand(0b00000001);

}



void LCD_voidWriteCommand( u8 Copy_u8Command)
{
	/*RS=1--->pin0*/
    DIO_voidSetPinValue(PORTB_ID, PIN0_ID,0);
	/*RW=1--->pin1*/
    DIO_voidSetPinValue(PORTB_ID, PIN1_ID,0);
    /*Send Data*/
   DIO_voidSetPortValue(PORTA_ID,Copy_u8Command);
   /*Enable Pulse*/
   DIO_voidSetPinValue(PORTB_ID, PIN2_ID,1);
	_delay_ms(2); //1 second delay
   DIO_voidSetPinValue(PORTB_ID, PIN2_ID,0);


	
}
void  LCD_voidWriteDATA( u8 Copy_u8DATA)
{
	/*RS=1--->pin0*/
    DIO_voidSetPinValue(PORTB_ID, PIN0_ID,1);
 	/*RW=1--->pin1*/
    DIO_voidSetPinValue(PORTB_ID, PIN1_ID,0);
    /*Send Data*/
    DIO_voidSetPortValue(PORTA_ID,Copy_u8DATA);
    /*Enable Pulse*/
    DIO_voidSetPinValue(PORTB_ID, PIN2_ID,1);
	_delay_ms(2); //1 second delay
    DIO_voidSetPinValue(PORTB_ID, PIN2_ID,0);
}

void LCD_GoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{

	u8 LOC_Default=128;
if (Copy_u8X==1)
{
	LOC_Default= LOC_Default+Copy_u8Y;
	LCD_voidWriteCommand(LOC_Default);
}
else
{
	LOC_Default= LOC_Default+Copy_u8Y+0X40;

	LCD_voidWriteCommand(LOC_Default);
}
}

void LCD_voidWriteSting(u8 *Copy_u8string)
{
	u8 i=0 ;
	while (Copy_u8string[i]!='\0')
	{
		LCD_GoToXY(0,i);
		LCD_voidWriteDATA(Copy_u8string[i]);
		i++;
	}

}



