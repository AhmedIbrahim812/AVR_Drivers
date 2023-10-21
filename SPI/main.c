/*
 * main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"



int main (void){
	//MOSI
	DIO_voidSetPinDir(PORTB_REG,PIN5,PIN_DIR_OUT);
	//SS
	DIO_voidSetPinDir(PORTB_REG,PIN4,PIN_DIR_OUT);
	//SS is low
	DIO_voidSetPinVal(PORTB_REG,PIN4,PIN_VAL_LOW);
	//MISO
	DIO_voidSetPinDir(PORTB_REG,PIN6,PIN_DIR_IN);
	//Clock
	DIO_voidSetPinDir(PORTB_REG,PIN7,PIN_DIR_OUT);

	//initilise ECU as master
	SPI_voidIntMstr();
while(1)
{
	SPI_u8Transeve(5);
}

}
