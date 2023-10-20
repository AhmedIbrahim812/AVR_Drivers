#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LED_interface.h"




void main (void)
{
	DIO_voidSetPinDir(PORTA_REG,PIN0,PIN_DIR_OUT);
	LED_con led={PORTA_REG,PIN0,ACTIVE_HIGH};
	while(1){
		LED_voidLedOn(led);
		_delay_ms(1000);
		LED_voidLedOff(led);
		_delay_ms(1000);
	}




}
