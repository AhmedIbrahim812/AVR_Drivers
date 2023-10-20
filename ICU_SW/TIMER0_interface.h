/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 01			*********/
/*********    Date: 6/9/2023	*********/

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);
u8 TIMER0_voidSetCallBack(void (*Copy_ptrtofunc)(void));
void TIMER0_voidSetOcrValue(u8 Copy_u8Value);
void TIMER0_voidSetPWMMode(void);

#endif
