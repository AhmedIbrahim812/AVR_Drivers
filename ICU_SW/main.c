#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "EXTI_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
void SWICU(void);
static u16 Reading1=0, Reading2=0;






void main (void)
{
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);

//Set pwm pin to out
DIO_voidSetPinDir(PORTB_REG,PIN3,PIN_DIR_OUT);
//set int0 pin to input
DIO_voidSetPinDir(PORTD_REG,PIN2,PIN_DIR_IN);
CLCD_voidInit();
TIMER0_voidInit();
TIMER1_voidInit();
EXTI_voidEnableInterrupt(int0);
EXTI_voidSetSenseCtrl(int0,rising_edge);

GIE_voidEnable();

EXTI_voidSetCallBack(int0,SWICU);
while (1)
{
CLCD_voidSetPosition(0,0);
CLCD_voidSendString("Duty is: ");
CLCD_voidSendNum(Reading2);
CLCD_voidSetPosition(1,0);
CLCD_voidSendString("ticks: ");
CLCD_voidSendNum(Reading1);
}




}


void SWICU(void)
{
static u8 counter=0;
counter++;
if (counter==1)
{
	TIMER1_voidWriteVal(0);
}
else if (counter==2)
{
Reading1=TIMER1_u16GetVal();
EXTI_voidSetSenseCtrl(int0,falling_edge);
}
else if (counter==3)
{
Reading2=TIMER1_u16GetVal();
Reading2 -=Reading1;
EXTI_voidDisableInterrupt(int0);
}
}
