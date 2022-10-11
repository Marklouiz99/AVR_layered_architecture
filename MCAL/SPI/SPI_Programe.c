#include"STD_TYPES.h"
#include"BitMath.h"
#include"SPI_Private.h"
#include"SPI_Interface"


void SPI_voidMasterIntit()
{
	set_bit(SPCR,SPI_Enable);
	clear_bit(SPCR,SPI_DataOrder);      //MSB Of Data Transmitted first
	set_bit(SPCR,MasterOrSlave);	//Select Master
	    /*Clock Polarity 
		Leading Edge: Rising
		Tralling Edge: Falling*/
	clear_bit(SPCR,SPI_ClockPolarity);
         /*Clock Phase
            Master Sends First: Setup
            Slave Sends Second: Sample*/			
	set_bit(SPCR,SPI_ClockPhase);
	    /*Master Clock Rate
		  Frequancy/16
		  No Double Speed Enabled*/
	set_bit(SPCR,SPI_ClockRateSelect_BIT0);
	clear_bit(SPCR,SPI_ClockRateSelect_BIT1);
}


void SPI_voidSlaveIntit()
{
	set_bit(SPCR,SPI_Enable);
	clear_bit(SPCR,SPI_DataOrder);      //MSB Of Data Transmitted first
	set_bit(SPCR,MasterOrSlave);	//Select Slave
	    /*Clock Polarity 
		Leading Edge: Rising
		Tralling Edge: Falling*/
	clear_bit(SPCR,SPI_ClockPolarity);
         /*Clock Phase
            Master Sends First: Setup
            Slave Sends Second: Sample*/			
	set_bit(SPCR,SPI_ClockPhase);
}


u8 SPI_u8Tranreciver(u8 Copy_u8SendData)
{
	SPDR=Copy_u8SendData; //if Slave Dummy Value else if Master Data TO Send
	while(read_bit(SPSR,SPI_InterruptFlag)==0); //Waiting Until Raising Transfer Flag 
	return SPDR;
}