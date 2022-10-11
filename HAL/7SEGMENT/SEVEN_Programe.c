#include"SEVEN_Interface.h"
#include"DIO_Interface.h"
#include"DIO_Config.h"
#include"SEVEN_Config.h"


void SEVENSEGMENT_voidInit(void)
{
	DIO_voidSetPortDirection(SEVENSEG_PORT,0xff);
}



void SEVENSEGMENT_voidDisplayNumber(u8 Copy_u8Number)
{
	DIO_voidSetPortValue(SEVENSEG_PORT,Copy_u8Number);
}
