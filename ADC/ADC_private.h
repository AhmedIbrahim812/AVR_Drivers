/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : MCAL *********************/
/****************** Date : 30/8/2023 ******************/
/****************** COmponent : ADC ******************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


// ADMUX register and its pins
#define ADMUX  *((volatile u8*)0X27)
#define ADMUX_MUX0     0
#define ADMUX_MUX1     1
#define ADMUX_MUX2     2
#define ADMUX_MUX3     3
#define ADMUX_MUX4     4
#define ADMUX_ADLAR    5
#define ADMUX_RFS0     6    //REF SELECTION BIT0
#define ADMUX_RFS1     7    //REF SELECTION BIT1


//ADCSRA register and its pins
#define ADCSRA  *((volatile u8*)0X26)
#define ADCSRA_ADPS0   0    //PRE SCALER BIT0
#define ADCSRA_ADPS1   1    //PRE SCALER BIT1
#define ADCSRA_ADPS2   2    //PRE SCALER BIT2
#define ADCSRA_ADIE    3    //INTERRUBT ENABLE PIN
#define ADCSRA_ADIF    4    //INTERRUBT FLAG
#define ADCSRA_ADATE   5    //auto trigger enable
#define ADCSRA_ADSC    6    //START CONVERSION
#define ADCSRA_ADEN    7    //ADC enable


// Data register
#define ADCH  *((volatile u8*)0X25)
#define ADCL  *((volatile u8*)0X24)






#define DIV_BY_TWO   1
#define DIV_BY_FOUR  2
#define DIV_BY_EIGHT 3


#define CHANNEL_ZERO 0
#define CHANNEL_ONE  1
#define CHANNEL_TWO  2
#define CHANNEL_THREE  3

#define ADMUX_CLEAR  0b11100000
#define ADCSRA_CLEAR 0b11111000

#endif
