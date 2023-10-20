/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 02			*********/
/*********    Date: 16/9/2023	*********/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0        	*((volatile u8*)0x53)	//TIMER COUNTER CTRL REG
#define TCCR0_WGM00 	6
#define TCCR0_WGM01 	3
#define TCCR0_COM01 	5
#define TCCR0_COM00 	4
#define TCCR0_CS00  	0
#define TCCR0_CS01  	1
#define TCCR0_CS02  	2

#define OCR0        	*((volatile u8*)0x5c)	//COMPARE VALUE

#define TIMSK        	*((volatile u8*)0x59)	//INTERRUPT ENABLE
#define TIMSK_TOIE0 		0			//INTERRUPT ENABLE OVER FLOW MODE
#define TIMSK_OCIE0 		1			//INTERRUPT ENABLE COMPARE MATCH MODE (CMP MODE)


#define TIFR        	*((volatile u8*)0x58)	//FLAG REG
#define TIFR_TOV0 			0			//INTERRUPT FLAG OVER FLOW MODE
#define TIMSK_OCF0  		1			//INTERRUPT FLAG COMPARE MODE (CMP MODE)


#define TCNT0        	*((volatile u8*)0x52)	//TICKS NUM


/*
 * options:
 * 1- OVF_MODE
 * 2- CTC_MODE
 * 3- FASTPWM
 */
#define FASTPWM 	3
#define CTC_MODE 	2
#define OVF_MODE 	1

/*
 * options:
 * 1- PULLING_MODE
 * 2- INTERRUPT_MODE
 * 3- NA
 */
#define PULLING_MODE 	1
#define INTERRUPT_MODE 	2
#define NA  			0

/*
 * options:
 * 1- DIV_BY_1
 * 2- DIV_BY_8
 * 3- DIV_BY_64
 * 4- DIV_BY_256
 * 5- DIV_BY_1024
 */

#define DIV_BY_1 			1
#define DIV_BY_8 			8
#define DIV_BY_64 			64
#define DIV_BY_256 			256
#define DIV_BY_1024 		1024


/*
 * options: FAST_PWM
 * 1- SET_TOP_CLR_COMP
 * 2- SET_COMP_CLR_TOP
 */

#define SET_TOP_CLR_COMP 	1
#define SET_COMP_CLR_TOP 	2



#endif
