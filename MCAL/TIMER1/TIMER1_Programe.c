#include"STD_TYPES.h"
#include"BitMath.h"
#include"TIMER1_Private.h"
#include"TIMER1_Interface.h"



void TIMER1_voidFastPwmMode()
{
	set_bit(TCCB_REG1,3);
	set_bit(TCCB_REG1,4);
	set_bit(TCCA_REG1,1);
	clear_bit(TCCA_REG1,0);
	set_bit(TCCA_REG1,7);
	clear_bit(TCCA_REG1,6);
	clear_bit(TCCB_REG1,2);
	clear_bit(TCCB_REG1,0);
	set_bit(TCCB_REG1,1);
	ICR_REG1=20000;
	OCRA_REG1=1000;
}


void TIMER1_voidNormalMode()
{
	clear_bit(TCCB_REG1,3);
	clear_bit(TCCB_REG1,4);
	clear_bit(TCCA_REG1,1);
	clear_bit(TCCA_REG1,0);
	clear_bit(TCCB_REG1,2);
	clear_bit(TCCB_REG1,0);
	set_bit(TCCB_REG1,1);
	
	
}


void TIMER1_voidCaptureTrigger(u8 Copy_u8InterruptSensing)
{
	if(Copy_u8InterruptSensing==1)
	{
		set_bit(TCCB_REG1,6);
	}
	else if(Copy_u8InterruptSensing==0)
	{
		clear_bit(TCCB_REG1,6);
	}
	set_bit(TIMSK_REG,5);
}

u16 TIMER1_u16InputCaptureValue()
{
	return ICR_REG1;
}