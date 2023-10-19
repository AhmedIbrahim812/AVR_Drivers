/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : MCAL *********************/
/****************** Date : 4/9/2023 ******************/
/****************** COmponent : EXTI ******************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

//control sense control
typedef enum
{
low_level=0,
on_change,
falling_edge,
rising_edge
}sense_ctrl;

// which interrupt
typedef enum
{
	int0=0,
	int1,
	int2
}interrupt_idx;

void EXTI_voidSetSenseCtrl(sense_ctrl Copy_sense_ctrl,interrupt_idx Copy_interrupt_idx);
void EXTI_voidEnableInterrupt(interrupt_idx Copy_interrupt_idx);
void EXTI_voidDisableInterrupt(interrupt_idx Copy_interrupt_idx);
void EXTI_voidSetCallBack(interrupt_idx Copy_interrupt_idx,void (*ptrtofunc)(void));



#endif
