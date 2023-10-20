/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 01			*********/
/*********    Date: 6/9/2023	*********/

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*
 * options:
 * 1- OVF_MODE
 * 2- CTC_MODE
 * 3- FASTPWM_MODE
 */

#define TIMER0_MODE  CTC_MODE

/*
 * options:
 * 1- DIV_BY_1
 * 2- DIV_BY_8
 * 3- DIV_BY_64
 * 4- DIV_BY_256
 * 5- DIV_BY_1024
 */

#define PRESCALER  DIV_BY_8

/*
 * options: FAST_PWM
 * 1- SET_TOP_CLR_COMP
 * 2- SET_COMP_CLR_TOP
 */

#define FAST_PWM SET_TOP_CLR_COMP






#endif
