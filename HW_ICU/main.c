#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"
#include "HW_ICU_interface.h"
void HW_ICU(void);
static u16 onticks,periodticks;

void main (void)
{
DIO_voidSetPinDir(PORTB_REG,PIN3,PIN_DIR_OUT);
DIO_voidSetPinDir(PORTD_REG,PIN6,PIN_DIR_IN);
DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);

CLCD_voidInit();
TIMER0_voidInit();
TIMER1_voidInit();
HWICU_voidInit();
HWICU_voidSetCallBack(HW_ICU);
GIE_voidEnable();

while(1)
{
CLCD_voidSetPosition(0,0);
CLCD_voidSendString("ONTICKS : ");
CLCD_voidSendNum(onticks);
CLCD_voidSetPosition(1,0);
CLCD_voidSendString("P_Ticks : ");
CLCD_voidSendNum(periodticks);
}

}



void HW_ICU(void)
{
	static u8 counter=0;
	static u16 reading1=0,reading2=0,reading3=0;
	counter++;
	if(counter==1)
	{
		reading1= HWICU_u16GetReading();
	}
	else if (counter==2)
	{
		reading2= HWICU_u16GetReading();
		periodticks=reading2-reading1;
		HWICU_voidSetTriggeredge(FALLING);
	}
	else if (counter==3)
	{
		reading3= HWICU_u16GetReading();
		onticks=reading3-reading2;
		HWICU_voidInerruptDisnable();
	}
}
