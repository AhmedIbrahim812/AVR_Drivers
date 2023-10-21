/*
 * UART_program.c
 *
 *  Created on: Sep 13, 2023
 *      Author: ahmed
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#ifndef USART_PROGRAM_C_
#define USART_PROGRAM_C_

void USART_voidInt(void)
{
	// One stop bits USRC bit3, no parity (UCRA bit2 0 ), ch size 8 bits USRB (011), no interrupt, mode async --> normal , baud rate 9600 UBRR=51
	UCSRC=0b10000110;
	UBRRL=0x33;
	UCSRB=0b00011000;

}
void USART_voidSend(u8 Copy_u8Data)
{
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0); //check the register is empty

	UDR=Copy_u8Data;
}
u8 USART_u8Receive(void)
{
	while (GET_BIT(UCSRA,UCSRA_RXC)==0); //receive complete check
	return UDR;
}

#endif /* UART_PROGRAM_C_ */
