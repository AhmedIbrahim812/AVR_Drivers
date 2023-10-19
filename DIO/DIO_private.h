/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : MCAL *********************/
/****************** Date : 16/8/2023 ******************/
/****************** COmponent : DIO ******************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

// Addresses for PORTA, DDRA, and PINA registers from data sheet

#define PORTA  *((volatile u8*)0X3B)
#define DDRA   *((volatile u8*)0X3A)
#define PINA   *((volatile u8*)0X39)

// Addresses for PORTB, DDRB, and PINB registers from data sheet
#define PORTB  *((volatile u8*)0X38)
#define DDRB   *((volatile u8*)0X37)
#define PINB   *((volatile u8*)0X36)

// Addresses for PORTC, DDRC, and PINC registers from data sheet
#define PORTC  *((volatile u8*)0X35)
#define DDRC   *((volatile u8*)0X34)
#define PINC   *((volatile u8*)0X33)

// Addresses for PORTD, DDRD, and PIND registers from data sheet
#define PORTD  *((volatile u8*)0X32)
#define DDRD   *((volatile u8*)0X31)
#define PIND   *((volatile u8*)0X30)




#endif
