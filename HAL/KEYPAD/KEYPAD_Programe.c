#include"STD_TYPES.h"
#include"BitMath.h"
#include"DIO_Interface.h"
#include"DIO_Config.h"
#include"KEYPAD_interface.h"
#include"KEYPAD_Config.h"
#include"avr/delay.h"


u8 KEYPAD_GetPressedKey(void)
{
	u8 LOC_SW_Value[4][4]={{7,8,9,'/'}
		                   {4,5,6,'*'}
						   {1,2,3,'-'}
						   {'c',0,'=','+'}};
	u8 LOC_Key_State=NORMAL_STATE;					   
	u8 LOC_Col=KYP_COLSTART;
	u8 LOC_Row=KYP_ROWSTART;
	u8 LOC_Check_Pressed=UNPRESSED;
	DIO_voidSetPinDirection(KYP_PORT,0x0F);
	DIO_voidSetPortValue(KYP_PORT,0xFF);
	for(LOC_Col=KYP_COLSTART;LOC_Col<KYP_COLSHIFT;LOC_Col++)
	{
		DIO_voidSetPinValue(KYP_PORT,LOC_Col,PIN_LOW);
		for(LOC_Row=KYP_ROWSTART;LOC_Row<KYP_ROWSHIFT;LOC_Row++)
		{
			LOC_Check_Pressed=DIO_voidgetPinValue(KYP_PORT,LOC_Row+KYP_ROWSHIFT);
			if(LOC_Check_Pressed==PRESSED)
			{
				LOC_Key_State=LOC_SW_Value[LOC_Row][LOC_Col];
				while(LOC_Check_Pressed==PRESSED)
				{
					LOC_Check_Pressed=DIO_voidgetPinValue(KYP_PORT,LOC_Row+KYP_ROWSHIFT);
				}
				_delay_ms(50);
				return LOC_Key_State;
			}
		}
		DIO_voidSetPinValue(KYP_PORT,LOC_Col,PIN_HIGH);
	}
	return LOC_Key_State;
}