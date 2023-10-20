/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Ahmed
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"
#include <util/delay.h>

void func(void);

int main(void){

DIO_voidSetPinDir(PORTA_REG,PIN0,PIN_DIR_OUT);
DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);

DIO_voidSetPinDir(PORTA_REG,PIN1,PIN_DIR_OUT);
DIO_voidSetPinVal(PORTA_REG,PIN1,PIN_VAL_LOW);


GIE_voidEnable();
TIMER0_voidSetDelay(1000,func,10);   //delay for 1000 ms, after 1000 ms func will be executed 10 times 


while(1);


	return 0;
}

void func(void){

		static u8 led_state=0;
		TOG_BIT(led_state,0);
	DIO_voidSetPinVal(PORTA_REG,PIN0,led_state);
	DIO_voidSetPinVal(PORTA_REG,PIN1,!led_state);
	_delay_ms(200);
}
