/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 01			*********/
/*********    Date: 6/9/2023	*********/

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A        	*((volatile u8*)0x4F)	//CTRL REG1
#define TCCR1A_COM1A0 	6
#define TCCR1A_COM1A1 	7
#define TCCR1A_WGM10 	0
#define TCCR1A_WGM11 	1


#define TCCR1B        	*((volatile u8*)0x4E)	//CTRL REG2
#define TCCR1B_WGM12 	3
#define TCCR1B_WGM13 	4
#define TCCR1B_CS10 	0
#define TCCR1B_CS11 	1
#define TCCR1B_CS12 	2

#define OCR1A  			*((volatile u16*)0x4A) //COMPARE REG TIMER1 (LOW & HIGH)

#define ICR1 			*((volatile u16*)0x46) // Input Capture Register (lOW & HIGH)
#define TCNT1           *((volatile u16*)0x4C)

#endif
