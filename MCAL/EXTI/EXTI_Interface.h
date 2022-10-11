#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void Init_voidEnable(u8 Copy_u8InterruptNumber,u8 Copy_u8InterruptSenseControl);
void Init_voidEnableINTI0(u8 Copy_u8InterruptSenseControl);
void Init_voidEnableINTI1(u8 Copy_u8InterruptSenseControl);
void Init_voidEnableINTI2(u8 Copy_u8InterruptSenseControl);
void EXTI0_SetCallBack(void(*Copy_voidInterrupt0ServiceRoutine)(void));
void EXTI0_SetCallBack(void(*Copy_voidInterrupt1ServiceRoutine)(void));



#endif