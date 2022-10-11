#include"STD_TYPES.h"
#include"BitMath.h"
#include"TIMER0_Interface.h"
#include"TIMER0_Private.h"
#include"TIMER0_Config.h"


void (*Global_voidNormalModePointerToFunction)(void)=NULL;
void (*Global_voidCompareModePointerToFunction)(void)=NULL;



void Timer0_voidSetCallBack(void(*Copy_voidInterruptNormalModeServiceRoutine)(void))
{
	Global_voidNormalModePointerToFunction=Copy_voidInterruptNormalModeServiceRoutine;
	
}


void Timer0_voidCompareModeSetCallBack(void(*Copy_voidInterruptCompareModeServiceRoutine)(void))
{
	Global_voidCompareModePointerToFunction=Copy_voidInterruptCompareModeServiceRoutine;
	
}


void Timer0_voidNormalModeInit(void)
{
	       /*Normal Mode Wave Generation*/
	clear_bit(TCC_REG0,WGM01_BIT);
	clear_bit(TCC_REG0,WGM00_BIT);
	       /*InterruptEnable*/
	set_bit(TIMSK_REG0,TOIE0_BIT);
}


void Timer0_voidNormalModeEnable(void)
{
	       /*Prescaler*/	
	clear_bit(TCC_REG0,Clock_Select_BIT0);
	clear_bit(TCC_REG0,Clock_Select_BIT2);
	set_bit(TCC_REG0,Clock_Select_BIT1);
}


void Timer0_voidCompareModeInit(u8 Copy_u8OC0PinDirection,u8 Copy_u8PrescalerValue)
{
	TCC_REG0=0x00;
	     /*Compare Mode WaveGeneration*/
	TCC_REG0|=Copy_u8OC0PinDirection;
	     /*Prescaler*/
	TCC_REG0|=Copy_u8PrescalerValue;
	     /*InterruptEnable*/
	set_bit(TIMSK_REG0,OCIE0_BIT);
	
}


void Timer0_u8PreLoder(u8 Copy_u8Preloader)
{
	TCNT_REG0=Copy_u8Preloader;
}


void Timer0_u8CompareRegisterValue(u8 Copy_u8CompareregisterValue)
{
	OCR_REG0=Copy_u8CompareregisterValue;

}


void Timer0_voidFastPwmIntit(u8 Copy_u8OC0PinDirection,u8 Copy_u8PrescalerValue)
{
	TCC_REG0=0x00;
	   /*Fast PWM Mode WaveGeneration*/
	TCC_REG0|=Copy_u8OC0PinDirection;
	   /*Prescaler*/
	TCC_REG0|=Copy_u8PrescalerValue;
}


void __vector_11(void)__attribute__((signal));
void __vector_11()
{
	if(Global_voidNormalModePointerToFunction!=NULL)
	{
		Global_voidNormalModePointerToFunction();
	}
}

void __vector_10(void)__attribute__((signal));
void __vector_10()
{
	if(Global_voidCompareModePointerToFunction!=NULL)
	{
		Global_voidCompareModePointerToFunction();
	}
}