/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : MCAL *********************/
/****************** Date : 30/8/2023 ******************/
/****************** COmponent : EXTI ******************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR  *((volatile u8*)0X55)
//ISC00 and ISC01 are for controlling int1
#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
//ISC10 and ISC11 are for controlling int2
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#define MCUCSR  *((volatile u8*)0X54)
//for sense control for int2
#define MCUCSR_ISC2   6

#define GICR   *((volatile u8*)0X5B)
//for activating INT0 , INT1 , INT2
#define GICR_INT0  6
#define GICR_INT1  7
#define GICR_INT2  5



#endif