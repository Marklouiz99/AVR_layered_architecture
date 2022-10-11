#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H


#define TCCA_REG1 *((volatile u8*)0x4F)
#define TCCB_REG1 *((volatile u8*)0x4E)
#define TCNT_REG1 *((volatile u16*)0x4C)
#define OCRA_REG1 *((volatile u16*)0x4A)
#define OCRB_REG1 *((volatile u16*)0x48)
#define ICR_REG1 *((volatile u16*)0x46)
#define TIMSK_REG *((volatile u8*)0x59)


#endif
