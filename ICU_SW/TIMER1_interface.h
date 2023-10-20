/********* 	 Layer: MACL 		*********/
/*********	Author: Ahmed 		*********/
/********* Version: 01			*********/
/*********    Date: 11/9/2023	*********/

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInit (void);
void TEMER1_voidSetOCRVal(u16 Copy_u16Value);
void TEMER1_voidSetICRVal(u16 Copy_u16Value);
void TIMER1_voidWriteVal(u16 value);
u16 TIMER1_u16GetVal(void); // TCNT1 value is returned

#endif
