/*
 * UART_interface.h
 *
 *  	Created on: Sep 13, 2023
 *      Author: ahmed
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#ifndef USART_INTERFACE_H__
#define USART_INTERFACE_H_H_

void USART_voidInt(void);
void USART_voidSend(u8 Copy_u8Data);
u8 USART_u8Receive(void);


#endif /*USART_INTERFACE_H__H_ */
