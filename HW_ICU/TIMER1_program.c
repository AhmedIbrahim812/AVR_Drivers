#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"


void TIMER1_voidInit (void){


	//pre scaler 8
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}


void TIMER1_voidWriteVal(u16 value)
{
TCNT1=value;
}

u16 TIMER1_u16GetVal(void)
{
return TCNT1;
}
/*
void TEMER1_voidSetOCRVal(u16 Copy_u16Value){
	OCR1A = Copy_u16Value;
}

void TEMER1_voidSetICRVal(u16 Copy_u16Value){
	ICR1 = Copy_u16Value;
}
*/
