#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


static void (*GlobalPtrToFunc0)(void)=NULL;
static void (*GlobalPtrToFunc1)(void)=NULL;
static void (*GlobalPtrToFunc2)(void)=NULL;

void EXTI_voidSetSenseCtrl(sense_ctrl Copy_sense_ctrl,interrupt_idx Copy_interrupt_idx)
{
	switch (Copy_interrupt_idx)
	{
	case int0: switch(Copy_sense_ctrl)
	{
	case low_level:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case on_change:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case falling_edge:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	case rising_edge:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
	}
	break;
	case int1:switch(Copy_sense_ctrl)
	{
	case low_level:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case on_change:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case falling_edge:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
	case rising_edge:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
	}
	break;
	case int2:switch(Copy_sense_ctrl)
	{
	case falling_edge:
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	case rising_edge:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	}
	break;
	}

}
void EXTI_voidEnableInterrupt(interrupt_idx Copy_interrupt_idx)
{
	switch (Copy_interrupt_idx)
	{

	case int0:SET_BIT(GICR,GICR_INT0);
	break;
	case int1:SET_BIT(GICR,GICR_INT1);
	break;
	case int2:SET_BIT(GICR,GICR_INT2);
	break;
	}

}
void EXTI_voidDisableInterrupt(interrupt_idx Copy_interrupt_idx)
{
	switch (Copy_interrupt_idx)
	{

	case int0:CLR_BIT(GICR,GICR_INT0);
	break;
	case int1:CLR_BIT(GICR,GICR_INT1);
	break;
	case int2:CLR_BIT(GICR,GICR_INT2);
	break;
	}
}


	void EXTI_voidSetCallBack(interrupt_idx Copy_interrupt_idx,void (*ptrtofunc)(void))
	{
		if (ptrtofunc!=NULL)
		{
			switch(Copy_interrupt_idx)
			{
			case int0 : GlobalPtrToFunc0=ptrtofunc;break;
			case int1 : GlobalPtrToFunc1=ptrtofunc;break;
			case int2 : GlobalPtrToFunc2=ptrtofunc;break;

			}
		}
		else
		{
			asm("NOP");
		}
	}


void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	if (GlobalPtrToFunc0!=NULL)
		GlobalPtrToFunc0();
	else
		asm("NOP");
}
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	if (GlobalPtrToFunc1!=NULL)
		GlobalPtrToFunc1();
	else
		asm("NOP");
}

void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	if (GlobalPtrToFunc2!=NULL)
		GlobalPtrToFunc2();
	else
		asm("NOP");
}








