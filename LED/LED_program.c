#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"



void LED_voidLedOn(LED_con led_t)
{
if (led_t.active_state==ACTIVE_HIGH){
	DIO_voidSetPinVal(led_t.port,led_t.pin,PIN_VAL_HIGH);	// in case activation by high

}
else if (led_t.active_state==ACTIVE_LOW)
{
	DIO_voidSetPinVal(led_t.port,led_t.pin,PIN_VAL_LOW);	// in case activation by low
}

}

void LED_voidLedOff(LED_con led_t)
{
if (led_t.active_state==ACTIVE_HIGH){
	DIO_voidSetPinVal(led_t.port,led_t.pin,PIN_VAL_LOW);	// in case activation by high
}
else if (led_t.active_state==ACTIVE_LOW)
{
	DIO_voidSetPinVal(led_t.port,led_t.pin,PIN_VAL_HIGH);	// in case activation by low
}
}



