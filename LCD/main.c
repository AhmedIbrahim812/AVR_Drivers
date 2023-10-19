#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"


// LM016L in Protues (LCD)


void main (void)
{

	DIO_voidSetPortDir(PORTD_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);
	CLCD_voidInit();

//u8 arr[5]={'A','B'};
//CLCD_voidSendData('A');

	CLCD_voidSendNum(5);
CLCD_voidSetPosition(0,1);
	CLCD_voidSendString("Saif");
//	CLCD_voidSendString("ENG.");
//	CLCD_voidSetPosition(1,8);
//	CLCD_voidSendString("Sief");
	//u8 arr[8]={0b0001111,0b0001111,0b0000000,0b0001111,0b0001111,0b0000000,0b0001111,0b0001111};
	//CLCD_voidDrawSpecialChar(arr, 1,0,3);


while(1){

}




}











