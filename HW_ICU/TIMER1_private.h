/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 01			*********/
/*********    Date: 6/9/2023	*********/

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A        	*((volatile u8*)0x4F)	//CTRL REG1



#define TCCR1B        	*((volatile u8*)0x4E)	//CTRL REG2

#define TCCR1B_CS10 	0
#define TCCR1B_CS11 	1
#define TCCR1B_CS12 	2
#define TCCR1B_ICES1    6



#define OCR1A  			*((volatile u16*)0x4A) //COMPARE REG TIMER1 (LOW & HIGH)

#define ICR1 			*((volatile u16*)0x46) // Input Capture Register (lOW & HIGH)
#define TCNT1           *((volatile u16*)0x4C)
#define TIMSK1           *((volatile u16*)0x59)
#define TIMSK1_TICIE1            5
#define RISING                   1
#define FALLING                  0
#endif
