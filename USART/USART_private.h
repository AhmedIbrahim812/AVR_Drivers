/*
 * UART_private.h
 *
 *  Created on: Sep 13, 2023
 *      Author: ahmed
 */

#ifndef USART_PRIVATE_H__
#define USART_PRIVATE_H_H_

#define UDR 	*((volatile u8*)0X2C)
#define UCSRA 	*((volatile u8*)0X2B)
#define UCSRA_RXC		 7
#define UCSRA_TXC        6
#define UCSRA_UDRE 		 5
#define UCSRA_U2X        1

#define UCSRB 	*((volatile u8*)0X2A)
#define UCSRB_RXCIE      7
#define UCSRB_TXCIE      6
#define UCSRB_RXEN       4
#define UCSRB_TXEN       3
#define UCSRB_UCZ2       2

#define UCSRC 	*((volatile u8*)0X40)
#define UCSRC_URSEL      7
#define UCSRC_USBS       3
#define UCSRC_UCSZ1      2
#define UCSRC_UCSZ0      1





#define UBRRL 	*((volatile u8*)0X29)
#define UBRRH 	*((volatile u8*)0X40)

#endif /*USART_PRIVATE_H__H_ */
