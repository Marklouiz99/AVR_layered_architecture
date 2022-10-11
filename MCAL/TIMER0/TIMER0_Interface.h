#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H


void Timer0_voidNormalModeInit(void);
void Timer0_voidNormalModeEnable(void);
void Timer0_voidCompareModeInit(u8 Copy_u8OC0PinDirection,u8 Copy_u8PrescalerValue);
void Timer0_voidPreLoder(u8 Copy_u8Preloader);
void Timer0_voidCompareRegisterValue(u8 Copy_u8CompareregisterValue);
void Timer0_voidSetCallBack(void(*Copy_voidInterruptNormalModeServiceRoutine)(void));
void Timer0_voidCompareModeSetCallBack(void(*Copy_voidInterruptCompareModeServiceRoutine)(void));
void Timer0_voidFastPwmIntit(u8 Copy_u8OC0PinDirection,u8 Copy_u8PrescalerValue);


#endif