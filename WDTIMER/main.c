#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
// watch dog timer from page 38 in data sheet , it has only one register WDTCR
// we will write direct to the pin location as a register
// because we need to assign values at pin in the same operation
#define WDTCR   *((volatile u8*)0x41)

void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidSleep(u8 Copy_u8Time);



void main (void)
{
DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);
_delay_ms(1000);
DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_LOW);
WDT_voidEnable();
WDT_voidSleep(6);
while(1)
{

}

}

void WDT_voidEnable(void)
{
SET_BIT(WDTCR,3);
}
void WDT_voidDisable(void)
{
	WDTCR=0b00011000; //WDE and WDTOE is one
	WDTCR=0;
}
void WDT_voidSleep(u8 Copy_u8Time)
{
	WDTCR&=0b11111000;
	WDTCR |=Copy_u8Time;
}







