#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"
#include <util/delay.h>





void main (void)
{

	// this application tests UART drivers using putty exe
	//if 'A' is recieved, PIN0 at PortA will be high
	//if 'B' is recieved, PIN1 at PortA will be high
	// After receiving, we send 'D' to putty
	USART_voidInt();
	u8 local_val= 0;
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN0,PIN_DIR_IN);
	DIO_voidSetPinDir(PORTD_REG,PIN1,PIN_DIR_OUT);
	while(1)
	{
		DIO_voidSetPINVal(PORTA_REG,PIN0,PIN_VAL_LOW);
		DIO_voidSetPINVal(PORTA_REG,PIN1,PIN_VAL_LOW);
		local_val=USART_u8Receive();

		if(local_val=='A')
		{
			DIO_voidSetPINVal(PORTA_REG,PIN0,PIN_VAL_HIGH);
			_delay_ms(500);

		}
		else if(local_val=='B')
		{
			DIO_voidSetPINVal(PORTA_REG,PIN1,PIN_VAL_HIGH);
			_delay_ms(500);
		}
		USART_voidSend('D');
	}

}
