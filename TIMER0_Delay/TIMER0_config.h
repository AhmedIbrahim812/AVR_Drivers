/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed		*********/
/********* Version: 02			*********/
/*********    Date: 16/9/2023	*********/

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define freq 		8000000
#define Resolution 	8

/*
 * options:
 * 1- OVF_MODE
 * 2- CTC_MODE
 * 3- FASTPWM_MODE
 */

#define TIMER0_MODE  OVF_MODE

/*
 * options:
 * 1- PULLING_MODE
 * 2- INTERRUPT_MODE
 * 3- NA
 */
#define TIMER0_USE 	INTERRUPT_MODE

/*
 * options:
 * 1- DIV_BY_1
 * 2- DIV_BY_8
 * 3- DIV_BY_64
 * 4- DIV_BY_256
 * 5- DIV_BY_1024
 */

#define PRESCALER  DIV_BY_64

/*
 * options: FAST_PWM
 * 1- SET_TOP_CLR_COMP
 * 2- SET_COMP_CLR_TOP
 */

#define FAST_PWM 	SET_TOP_CLR_COMP






#endif
