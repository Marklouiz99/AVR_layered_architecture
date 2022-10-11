#include"STD_TYPES.h"
#include"BitMath.h"
#include"DIO_Interface.h"
#include"DIO_Config.h"
#include"avr/delay.h"



void DCMOTOR_voidInit(void)
{
	DIO_voidSetPinDirection(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_OUTPUT_ID);
}

void DCMOTOR_voidDirection(u8 Copy_u8MotorDir)
{
	switch(*Copy_u8MotorDir)
	{
	case (Right):
	       DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_HIGH);
	       DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_LOW);
		   _delay_ms(200);
		   break;
	
	case (Left):
	       DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_LOW);
	       DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_HIGH);
		   _delay_ms(200);
		   break;
    case (Stop):
	       DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN1,PIN_LOW);
	       DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_PIN2,PIN_LOW);
		   _delay_ms(200);
		   break;
	}	   
	
}