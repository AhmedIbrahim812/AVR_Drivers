#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER1_private.h"
#include "HW_ICU_interface.h"

static void (*Globalptrtofunc)(void)=NULL;
void HWICU_voidInit(void)
{
	SET_BIT(TIMSK1,TIMSK1_TICIE1);
	SET_BIT(TCCR1B,TCCR1B_ICES1);

}
void HWICU_voidInerruptEnable(void){
	SET_BIT(TIMSK1,TIMSK1_TICIE1);

}
void HWICU_voidInerruptDisnable(void){
	CLR_BIT(TIMSK1,TIMSK1_TICIE1);
}
void HWICU_voidSetTriggeredge(u8 Copy_u8Edge)
{
	if (Copy_u8Edge==RISING)
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	else if (Copy_u8Edge==FALLING)
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
}
u16 HWICU_u16GetReading(void)
{
return ICR1;
}
void HWICU_voidSetCallBack(void(*ptrtofunc)(void))
{
	if (ptrtofunc!=NULL)
		Globalptrtofunc=ptrtofunc;
}


void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	if (Globalptrtofunc!=NULL)
		Globalptrtofunc();
}










