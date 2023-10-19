#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"


void func(void);

void main (void)
{
	DIO_voidSetPinDir(PORTD_REG,PIN2,PIN_DIR_IN);
	//enable int0


	DIO_voidSetPinDir(PORTA_REG,PIN0,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTA_REG,PIN7,PIN_DIR_OUT);
	DIO_voidSetPinVal(PORTA_REG,PIN7,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);

	EXTI_voidSetSenseCtrl(falling_edge,int0);
	EXTI_voidEnableInterrupt(int0);
	EXTI_voidSetCallBack(int0,&func);
	GIE_voidEnable();
	_delay_ms(2000);
	DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_HIGH);




}


void func(void)
{
	DIO_voidSetPinVal(PORTA_REG,PIN7,PIN_VAL_LOW);
	DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_LOW);
		_delay_ms(2000);
}







	/*
	DIO_voidSetPinDir(PORTD_REG,PIN2,PIN_DIR_IN);

	DIO_voidSetPinVal(PORTD_REG,PIN2,PIN_VAL_HIGH);
	DIO_voidSetPinDir(PORTA_REG,PIN0,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTA_REG,PIN7,PIN_DIR_OUT);

	EXTI0_voidInit();
	GIE_voidEnable();

while (1){

	DIO_voidSetPinVal(PORTA_REG,PIN7,PIN_VAL_HIGH);
	DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);

}


}

void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_LOW);
	_delay_ms(5000);

*/




