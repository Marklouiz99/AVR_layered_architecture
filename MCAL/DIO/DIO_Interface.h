#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

         /*Prototypes*/
void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir);
void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);
u8 DIO_voidgetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

#endif