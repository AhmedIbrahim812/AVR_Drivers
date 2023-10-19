#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"


// function enables the user to set port direction (input/output)
void DIO_voidSetPortDir(u8 Copy_u8Port,u8 Copy_u8Dir)
{
	//Switch which port we want to access, then assign dir value
	switch (Copy_u8Port)
	{
	case PORTA_REG:DDRA=Copy_u8Dir;break;
	case PORTB_REG:DDRB=Copy_u8Dir;break;
	case PORTC_REG:DDRC=Copy_u8Dir;break;
	case PORTD_REG:DDRD=Copy_u8Dir;break;
	}
}

// function enables the user to set pin direction (input/output)
void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Dir)
{
	// Make sure that user has written valid bit (safety if condition)
	if (Copy_u8Pin <=7)
	{
		//When the direction is output, we access certain port,
		// then set certain bit to 1
		if (Copy_u8Dir==PIN_DIR_OUT)
		{
			switch(Copy_u8Port)
			{
			case PORTA_REG : SET_BIT(DDRA,Copy_u8Pin);break;
			case PORTB_REG : SET_BIT(DDRB,Copy_u8Pin);break;
			case PORTC_REG : SET_BIT(DDRC,Copy_u8Pin);break;
			case PORTD_REG : SET_BIT(DDRD,Copy_u8Pin);break;
			}
		}
		//When the direction is output, we access certain port,
		// then set certain bit to 0
		else if (Copy_u8Dir==PIN_DIR_IN)
		{
			switch(Copy_u8Port)
			{
			case PORTA_REG : CLR_BIT(DDRA,Copy_u8Pin);break;
			case PORTB_REG : CLR_BIT(DDRB,Copy_u8Pin);break;
			case PORTC_REG : CLR_BIT(DDRC,Copy_u8Pin);break;
			case PORTD_REG : CLR_BIT(DDRD,Copy_u8Pin);break;
			}
		}
	}
}

// function enables the user to set port value (high,low)
void DIO_voidSetPortVal(u8 Copy_u8Port,u8 Copy_u8Val){
	//Switch which port we want to access, then assign port value
	// on certain port register
	switch (Copy_u8Port)
	{
	case PORTA_REG:PORTA=Copy_u8Val;break;
	case PORTB_REG:PORTB=Copy_u8Val;break;
	case PORTC_REG:PORTC=Copy_u8Val;break;
	case PORTD_REG:PORTD=Copy_u8Val;break;
	}
}

// function enables the user to set pin value (high,low)
void DIO_voidSetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Val)
{
	if (Copy_u8Pin <=7)
	{
		if (Copy_u8Val==PIN_VAL_HIGH)
		{
			//When the value is high, we access certain port,
			// then set certain bit to 1
			switch(Copy_u8Port)
			{
			case PORTA_REG : SET_BIT(PORTA,Copy_u8Pin);break;
			case PORTB_REG : SET_BIT(PORTB,Copy_u8Pin);break;
			case PORTC_REG : SET_BIT(PORTC,Copy_u8Pin);break;
			case PORTD_REG : SET_BIT(PORTD,Copy_u8Pin);break;
			}
		}
		else if (Copy_u8Val==PIN_VAL_LOW)
		{
			//When the value is low, we access certain port,
			// then set certain bit to 0
			switch(Copy_u8Port)
			{
			case PORTA_REG : CLR_BIT(PORTA,Copy_u8Pin);break;
			case PORTB_REG : CLR_BIT(PORTB,Copy_u8Pin);break;
			case PORTC_REG : CLR_BIT(PORTC,Copy_u8Pin);break;
			case PORTD_REG : CLR_BIT(PORTD,Copy_u8Pin);break;
			}
		}
	}
}

// Get the value of certain pin
u8 DIO_u8GetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Realing=0;
	// safety if condition
	if (Copy_u8Pin <=7)
	{
		switch(Copy_u8Port)
		{
		case PORTA_REG : Local_u8Realing=GET_BIT(PINA,Copy_u8Pin);break;
		case PORTB_REG : Local_u8Realing=GET_BIT(PINB,Copy_u8Pin);break;
		case PORTC_REG : Local_u8Realing=GET_BIT(PINC,Copy_u8Pin);break;
		case PORTD_REG : Local_u8Realing=GET_BIT(PIND,Copy_u8Pin);break;
		}
	}
	return Local_u8Realing;
}












