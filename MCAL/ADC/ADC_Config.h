#ifndef  _ADC_CONFIG.H_
#define  _ADC_CONFIG.H_

#define ADC0   0
#define ADC1   1
#define ADC2   2
#define ADC3   3
#define ADC4   4
#define ADC5   5
#define ADC6   6
#define ADC7   7


#define ADC_CHANNEL ADC0


#define Div2    0
#define Div4    1
#define Div8    2
#define Div16   3
#define Div32   4
#define Div64   5
#define Div128  6


#define ADC_PRESCALER Div2


#define BIT0   (0x00)
#define BIT1   (0x01)
#define BIT2   (0x02)
#define BIT3   (0x03)
#define BIT4   (0x04)
#define BIT5   (0x05)
#define BIT6   (0x06)
#define BIT7  (0x07)


#define Vref_Turned_Off 0
#define Vref_AVCC 1
#define Reserved 2
#define Vref_Internal 3


#define ADC_VREF Vref_AVCC


#define Right_Adjust 0
#define Left_Adjust 1


#define ADC_BIT_INPUT_FORM Right_Adjust




#endif