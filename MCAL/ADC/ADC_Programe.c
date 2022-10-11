#include"STD_TYPES.h"
#Include"BitMath.h"
#include"ADC_Private.h"
#include"ADC_Interface.h"
#include"ADC_Config.h"


void ADC_voidInit()
{
	#if ADC_VREF==Vref_AVCC
	   set_bit(ADMUX_REG,BIT6);
	   clear_bit(ADMUX_REG,BIT7);
	#elif ADC_VREF==Vref_Turned_Off
	     clear_bit(ADMUX_REG,BIT6);
	     clear_bit(ADMUX_REG,BIT7);
	#elif ADC_VREF==Vref_Internal
	     set_bit(ADMUX_REG,BIT6);
	     set_bit(ADMUX_REG,BIT7);
	#endif
	
	
	#if ADC_BIT_INPUT_FORM==Right_Adjust
	   clear_bit(ADMUX_REG,BIT5);
	#elif ADC_BIT_INPUT_FORM==Left_Adjust
	     set_bit(ADMUX_REG,BIT5);
	#endif
	
	
	#if ADC_CHANNEL==ADC0
	   clear_bit(ADMUX_REG,BIT0);
	   clear_bit(ADMUX_REG,BIT1);
	   clear_bit(ADMUX_REG,BIT2);
	   clear_bit(ADMUX_REG,BIT3);
	   clear_bit(ADMUX_REG,BIT4);
	#elif ADC_CHANNEL==ADC1
	    set_bit(ADMUX_REG,BIT0);
	    clear_bit(ADMUX_REG,BIT1);
	    clear_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
		clear_bit(ADMUX_REG,BIT4);
	#elif ADC_CHANNEL==ADC2
	    clear_bit(ADMUX_REG,BIT0);
	    set_bit(ADMUX_REG,BIT1);
	    clear_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
		clear_bit(ADMUX_REG,BIT4);
	#elif ADC_CHANNEL==ADC3
	    set_bit(ADMUX_REG,BIT0);
	    set_bit(ADMUX_REG,BIT1);
	    clear_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
		clear_bit(ADMUX_REG,BIT4);
	#elif ADC_CHANNEL==ADC4
	    clear_bit(ADMUX_REG,BIT0);
	    clear_bit(ADMUX_REG,BIT1);
	    set_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
		clear_bit(ADMUX_REG,BIT4);
	#elif ADC_CHANNEL==ADC5
	    set_bit(ADMUX_REG,BIT0);
	    clear_bit(ADMUX_REG,BIT1);
	    set_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
		clear_bit(ADMUX_REG,BIT4);
	#elif ADC_CHANNEL==ADC6
	    clear_bit(ADMUX_REG,BIT0);
	    set_bit(ADMUX_REG,BIT1);
	    set_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
        clear_bit(ADMUX_REG,BIT4);
    #elif ADC_CHANNEL==ADC6
	    set_bit(ADMUX_REG,BIT0);
	    set_bit(ADMUX_REG,BIT1);
	    set_bit(ADMUX_REG,BIT2);
	    clear_bit(ADMUX_REG,BIT3);
        clear_bit(ADMUX_REG,BIT4);
    #endif
	
	
    set_bit(ADCS_REG,BIT7);
	set_bit(ADCS_REG,BIT6);

	
    #if ADC_PRESCALER==Div2	
	  set_bit(ADCS_REG,BIT0);
	  clear_bit(ADCS_REG,BIT1);
	  clear_bit(ADCS_REG,BIT2);
	#elif ADC_PRESCALER==Div4	
	    clear_bit(ADCS_REG,BIT0);
	    set_bit(ADCS_REG,BIT1);
	    clear_bit(ADCS_REG,BIT2);
	#elif ADC_PRESCALER==Div8	
	    set_bit(ADCS_REG,BIT0);
	    set_bit(ADCS_REG,BIT1);
	    clear_bit(ADCS_REG,BIT2);
	#elif ADC_PRESCALER==Div16	
	    clear_bit(ADCS_REG,BIT0);
	    clear_bit(ADCS_REG,BIT1);
	    set_bit(ADCS_REG,BIT2);
	#elif ADC_PRESCALER==Div32	
	    set_bit(ADCS_REG,BIT0);
	    clear_bit(ADCS_REG,BIT1);
	    set_bit(ADCS_REG,BIT2);
	#elif ADC_PRESCALER==Div64	
	    clear_bit(ADCS_REG,BIT0);
	    set_bit(ADCS_REG,BIT1);
	    set_bit(ADCS_REG,BIT2);
	#elif ADC_PRESCALER==Div128	
	    set_bit(ADCS_REG,BIT0);
	    set_bit(ADCS_REG,BIT1);
	    set_bit(ADCS_REG,BIT2);
	#endif
	
	
	
}


u16 ADC_u16GetResult()
{
	return ADC_REG;
}

void ADC_voidSingleModeChange()
{
	set_bit(ADCS_REG,BIT6);
}