/******************* Layer : HCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : HCAL *********************/
/****************** Date : 1/9/2023 ******************/
/****************** COmponent : SW ******************/
#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

// control intialisation
#define PULL_UP   1
#define FLOATING 0

//switch data
typedef struct
{
u8 port_con;
u8 pin_con;
u8 state;	
}SW_t;


void SW_voidInit(SW_t my_switch); 
u8 SW_u8GetPressed(SW_t my_switch);





#endif
