#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

static void (*Global_ptrtofunc)(void) = NULL;

void TIMER0_voidInit(void){

	//COMPARE MATCH FAST MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

	//SET OCR0 64
	OCR0 = 64;

	// CHOSE NON-INVERTED MODE
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	// COMPARE MATCH INTERRUPT ENABLE
	//SET_BIT(TIMSK,TIMSK_OCIE0);

	//PRESCALLER 8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
/*
#if TIMER0_MODE == CTC_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

#elif TIMER0_MODE == OVF_MODE
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

#elif TIMER0_MODE == FASTPWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

#else
#error("WRONG MODE");
#endif

#if PRESCALER == DIV_BY_1
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif PRESCALER == DIV_BY_8
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);

#elif PRESCALER == DIV_BY_64
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);


#elif PRESCALER == DIV_BY_256
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#elif PRESCALER == DIV_BY_1024
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#else
#error ("WRONG PRESCALER")

#endif
*
}

void TIMER0_voidSetPWMMode(void){
#if FAST_PWM == SET_TOP_CLR_COMP
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
#elif FAST_PWM == SET_COMP_CLR_TOP
	SET_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);

#error ("WRONG VALUE")
#endif
*/
}

u8 TIMER0_voidSetCallBack(void (*Copy_ptrtofunc)(void)){
	u8 Local_u8Errorstate = OK;
	if(Copy_ptrtofunc!=NULL){
		Global_ptrtofunc=Copy_ptrtofunc;
	}
	else{
		Local_u8Errorstate = NOK;
	}
	return Local_u8Errorstate;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	if(Global_ptrtofunc!=NULL){
		Global_ptrtofunc;
	}

/*
	static u16 Local_u16Counter=0;
	Local_u16Counter++;

	if(Local_u16Counter==4000){
		if(Global_ptrtofunc!=NULL){
			Global_ptrtofunc();
			Local_u16Counter=0;
		}
	}*/
}

void TIMER0_voidSetOcrValue(u8 Copy_u8Value){
	OCR0 = Copy_u8Value;
}
