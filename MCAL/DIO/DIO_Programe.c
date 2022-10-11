#include"STD_TYPES.h"
#include"BitMath.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DIO_Config.h"


 void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir)
 {
	 if (Copy_u8PinDir==1)                                   //OUTPUT
	 {
	 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        set_bit(DDRA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        set_bit(DDRB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        set_bit(DDRC_REG,Copy_u8PinID);        //Port C
		 break ;
		 case (PORTD_ID):        set_bit(DDRD_REG,Copy_u8PinID);        //Port D
 		 break ;
		 
		
	 }
	 
	 }
	 else if (Copy_u8PinDir==0)                           //INPUT
	 {
		 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        clear_bit(DDRA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        clear_bit(DDRB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        clear_bit(DDRC_REG,Copy_u8PinID);       //Port C
		 break ;
		 case (PORTD_ID):        clear_bit(DDRD_REG,Copy_u8PinID);       //Port D
 		 break ;
		 
		
	 }
	 }
	 
 }
void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
 {
	 
	  if (Copy_u8PinValue==1)                                   //HIGH
	 {
	 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        set_bit(PORTA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        set_bit(PORTB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        set_bit(PORTC_REG,Copy_u8PinID);        //Port C
		 break ;
		 case (PORTD_ID):        set_bit(PORTD_REG,Copy_u8PinID);        //Port D
 		 break ;
		 
		
	 }
	 
	 }
	 else if (Copy_u8PinValue==0)                           //LOW
	 {
		 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        clear_bit(PORTA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        clear_bit(PORTB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        clear_bit(PORTC_REG,Copy_u8PinID);       //Port C
		 break ;
		 case (PORTD_ID):        clear_bit(PORTD_REG,Copy_u8PinID);       //Port D
 		 break ;
		 
		
	 }
	 }
	 
	 
	 
	 
 }
 void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir)
 {
 	switch(Copy_u8PortID)
 	{
 	case PORTA_ID: DDRA_REG= Copy_u8PortDir; break;
 	case PORTB_ID: DDRB_REG= Copy_u8PortDir; break;
 	case PORTC_ID: DDRC_REG= Copy_u8PortDir; break;
 	case PORTD_ID: DDRD_REG= Copy_u8PortDir; break;

 	}
 }
 void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
 {
 	switch(Copy_u8PortID)
 		{
 		case PORTA_ID: PORTA_REG= Copy_u8PortValue; break;
 		case PORTB_ID: PORTB_REG= Copy_u8PortValue; break;
 		case PORTC_ID: PORTC_REG= Copy_u8PortValue; break;
 		case PORTD_ID: PORTD_REG= Copy_u8PortValue; break;

 		}

 }
u8 DIO_voidgetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
	{


		u8 value ;


		switch(Copy_u8PortID)
		{


		case (PORTA_ID) :
		        value=read_bit(PINA_REG,Copy_u8PinID);
		        break ;

		case (PORTB_ID) :
				value=read_bit(PINB_REG,Copy_u8PinID);
				break ;


		case (PORTC_ID) :
				value=read_bit(PINC_REG,Copy_u8PinID);
				break ;

		case (PORTD_ID) :
				value=read_bit(PIND_REG,Copy_u8PinID);
				break ;

		}
		 return value ;

	}
void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	switch(Copy_u8PortID)
	    {
		    case PORTA_ID:toggle_bit(PINA_REG,Copy_u8PinID);break;
		    case PORTB_ID:toggle_bit(PINB_REG,Copy_u8PinID);break;
		    case PORTC_ID:toggle_bit(PINC_REG,Copy_u8PinID);break;
		    case PORTD_ID:toggle_bit(PIND_REG,Copy_u8PinID);break;
	    }
}