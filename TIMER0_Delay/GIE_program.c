#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_voidEnable(void){
	SET_BIT(SREG,SREG_I);
}


void GIE_voidDisable(void){
	CLR_BIT(SREG,SREG_I);
}
