#include"STD_TYPES.h"
#include"BitMath.h"
#include"EXTI_Private.h"
#include"EXTI_Interface.h"


void (*Global_voidEXTI0PointerToFunction)(void)=NULL;
void (*Global_voidEXTI1PointerToFunction)(void)=NULL;

void EXTI0_SetCallBack(void(*Copy_voidInterrupt0ServiceRoutine)(void))
{
	Global_voidEXTI0PointerToFunction=Copy_voidInterrupt0ServiceRoutine;
}


void EXTI0_SetCallBack(void(*Copy_voidInterrupt1ServiceRoutine)(void))
{
	Global_voidEXTI1PointerToFunction=Copy_voidInterrupt1ServiceRoutine;
}



void Init_voidEnable(u8 Copy_u8InterruptNumber,u8 Copy_u8InterruptSenseControl)
{
	switch(Copy_u8InterruptNumber)
	{
		case(EXTINTERRUPT0):
		   Init_voidEnableINTI0(u8 Copy_u8InterruptSenseControl);
		   break;
		case(EXTINTERRUPT1):
		   Init_voidEnableINTI1(u8 Copy_u8InterruptSenseControl);
		   break;
		case(EXTINTERRUPT2):
		   Init_voidEnableINTI2(u8 Copy_u8InterruptSenseControl);
		   break;
		   
	}
}


void Init_voidEnableINTI0(u8 Copy_u8InterruptSenseControl)
{
	set_bit(GIC_REG,EXTINTERRUPT0_REQUEST_PIN);
	switch(Copy_u8InterruptSenseControl)
	{
		case (RISING_EDGE):
		   set_bit(MCUC_REG,EXTINTERRUPT0_PIN1);
	       set_bit(MCUC_REG,EXTINTERRUPT0_PIN2);
		   break;
		case (FALLING_EDGE):
		   clear_bit(MCUC_REG,EXTINTERRUPT0_PIN1);
	       set_bit(MCUC_REG,EXTINTERRUPT0_PIN2);
		   break;
		case (LOW_LEVEL):
		   clear_bit(MCUC_REG,EXTINTERRUPT0_PIN1);
	       clear_bit(MCUC_REG,EXTINTERRUPT0_PIN2);
		   break;
		case (ANY_LOGICAL_CHANGE):
		   set_bit(MCUC_REG,EXTINTERRUPT0_PIN1);
	       clear_bit(MCUC_REG,EXTINTERRUPT0_PIN2);
		   break;
	
	}
}


void Init_voidEnableINTI1(u8 Copy_u8InterruptSenseControl)
{
	set_bit(GIC_REG,EXTINTERRUPT1_REQUEST_PIN);
	switch(Copy_u8InterruptSenseControl)
	{
		case (RISING_EDGE):
		   set_bit(MCUC_REG,EXTINTERRUPT1_PIN1);
	       set_bit(MCUC_REG,EXTINTERRUPT1_PIN2);
		   break;
		case (FALLING_EDGE):
		   clear_bit(MCUC_REG,EXTINTERRUPT1_PIN1);
	       set_bit(MCUC_REG,EXTINTERRUPT1_PIN2);
		   break;
		case (LOW_LEVEL):
		   clear_bit(MCUC_REG,EXTINTERRUPT1_PIN1);
	       clear_bit(MCUC_REG,EXTINTERRUPT1_PIN2);
		   break;
		case (ANY_LOGICAL_CHANGE):
		   set_bit(MCUC_REG,EXTINTERRUPT1_PIN1);
	       clear_bit(MCUC_REG,EXTINTERRUPT1_PIN2);
		   break;
	
	}
}


void Init_voidEnableINTI2(u8 Copy_u8InterruptSenseControl)
{
	set_bit(GIC_REG,EXTINTERRUPT2_REQUEST_PIN);
	switch(Copy_u8InterruptSenseControl)
	{
		case (RISING_EDGE):
		   set_bit( MCUCAS_REG,EXTINTERRUPT2_PIN1);
		   break;
		case (FALLING_EDGE):
		   clear_bit(MCUCAS_REG,EXTINTERRUPT2_PIN1);
	}
}


void __vector_1(void)__attribute__((signal));
void __vector_1()
{
	if(Global_voidEXTI0PointerToFunction!=NULL)
	{
	       Global_voidEXTI0PointerToFunction();
	}
}


void __vector_2(void)__attribute__((signal));
void __vector_2()
{
	if(Global_voidEXTI1PointerToFunction!=NULL)
	{
	       Global_voidEXTI1PointerToFunction();
	}
}



void __vector_3(void)__attribute__((signal));
void __vector_3()
{
	if(Global_voidPointerToFunction!=NULL)
	{
	       Global_voidPointerToFunction();
	}
}