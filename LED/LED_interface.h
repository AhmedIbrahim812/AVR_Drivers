/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : HCAL *********************/
/****************** Date : 17/8/2023 ******************/
/****************** COmponent : LED ******************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct {
	u8 port;
	u8 pin;
	u8 active_state;
}LED_con;



#define ACTIVE_HIGH  1
#define ACTIVE_LOW   0




void LED_voidLedOn(LED_con led_t);
void LED_voidLedOff(LED_con led_t);



#endif
