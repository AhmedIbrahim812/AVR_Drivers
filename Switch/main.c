#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include <util/delay.h>

void main (void)
{
	//_delay_ms(500);
	SW_t strct={PORTA_REG,PIN0,PIN_VAL_HIGH};
	//SW_voidInit(strct);
	u8 result= SW_u8GetPressed(strct);
	//if (result==1)
	DIO_voidSetPinVal(PORTD_REG,PIN0,result);


}


