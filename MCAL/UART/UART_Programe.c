#include"STD_TYPES.h"
#include"BitMath.h"
#include"UART_Private.h"
#include"UART_Interface.h"



void UART_voidIntit()
{
	u8 temp;
	set_bit(UCSRB,3);
	set_bit(UCSRB,4);
	temp=set_bit(temp,7);
	temp=clear_bit(temp,6);
	temp=clear_bit(temp,5);
	temp=clear_bit(temp,4);
	temp=clear_bit(temp,3);
	temp=set_bit(temp,1);
	temp=set_bit(temp,2);
	temp=clear_bit(temp,0);
	UCSRC_UBRRH=temp;
	UBRRL=51;
	
}


void UART_voidSendData(u8 Copy_u8SentData)
{
	UDR=Copy_u8SentData;
	while(read_bit(UCSRA,5)==0);
	set_bit(UCSRA,5);
}


u8 UART_voidReciveData(u8 Copy_u8RecivedData)
{
	while(read_bit(UCSRA,7)==0);
	set_bit(UCSRA,7);
	return UDR;
}