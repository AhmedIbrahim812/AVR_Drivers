#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "DIO_interface.h"

static void (*Global_ptrtofunc1)(void) = NULL;
static void (*Global_ptrtofunc2)(void) = NULL;
u32 Global_u32Counter1=1;	//30518
u32 Global_u32Counter2=1;	//2

void TIMER0_voidInit(void){

	//select the mode setting
	
#if TIMER0_MODE == CTC_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	
#if TIMER0_USE == PULLING_MODE

#elif TIMER0_USE == INTERRUPT_MODE
	SET_BIT(TIMSK,TIMSK_OCIE0);
#endif
	

#elif TIMER0_MODE == OVF_MODE
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	
#if TIMER0_USE == PULLING_MODE

#elif TIMER0_USE == INTERRUPT_MODE
	SET_BIT(TIMSK,TIMSK_TOIE0);

#endif
	

#elif TIMER0_MODE == FASTPWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);

#else
#error("WRONG MODE");
#endif
	

	//select the prescaler
	
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

}

u8 TIMER0_voidSetCallBack(void (*Copy_ptrtofunc)(void)){
	u8 Local_u8Errorstate = OK;
	if(Copy_ptrtofunc!=NULL){
		Global_ptrtofunc1=Copy_ptrtofunc;
	}
	else{
		Local_u8Errorstate = NOK;
	}
	return Local_u8Errorstate;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){

	if(Global_ptrtofunc1!=NULL){
		Global_ptrtofunc1();

		Global_ptrtofunc1 = NULL;
	}

	if(Global_ptrtofunc2 !=NULL){
		static u32 Local_u32Counter1=0;
		Local_u32Counter1++;

		if(Local_u32Counter1==Global_u32Counter1){
			for(u8 Local_u8Counter2 = 0; Local_u8Counter2 <= Global_u32Counter2; Local_u8Counter2++){
			Global_ptrtofunc2();
			}
			Local_u32Counter1=0;
			Global_ptrtofunc2=NULL;

		}
	}
}

void TIMER0_voidSetOcrValue(u8 Copy_u8Value){
	OCR0 = Copy_u8Value;
}

void TIMER0_voidSetDelay(u32 Copy_u8Time_mSec, void (*Copy_ptrtofunc)(void), u8 Copy_u8Iterator){
	// calculation of NO of Ticks and value of counter
	u32 overflowticks=1;
	float overflowtime;
	u32 counter=0;
	u8 preload;

	//Timer Count (2^resolution)
	for(u8 i=0;i<Resolution;i++){
		overflowticks *=2;
	}	//overflowticks = 2^resolution

	//tick time
	overflowtime = ((f32)(overflowticks * PRESCALER)/freq);	

	//Counter and preload
	counter = (f32)(Copy_u8Time_mSec)/(1000*overflowtime);	8
	preload = ((f32)(((Copy_u8Time_mSec/1000)/overflowtime)*overflowticks));
	preload = 256-preload; 	//preload==108
	if(preload){
		counter++;
	}	


	TCNT0 = preload;	

	//Set the global counters
	Global_u32Counter1 = counter;			
	Global_u32Counter2 = Copy_u8Iterator;	

	//passing the function to the interrupt
	if(Copy_ptrtofunc!=NULL){
		Global_ptrtofunc2=Copy_ptrtofunc;
	}
}
