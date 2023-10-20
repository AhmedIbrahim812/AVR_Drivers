/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : MCAL *********************/
/****************** Date : 16/8/2023 ******************/
/****************** COmponent : HW_ICU ******************/
#ifndef HW_ICU_INTERFACE_H_
#define HW_ICU_INTERFACE_H_

void HWICU_voidInit(void);
void HWICU_voidInerruptEnable(void);
void HWICU_voidInerruptDisnable(void);
void HWICU_voidSetTriggeredge(u8 Copy_u8Edge);
u16 HWICU_u16GetReading(void);
void HWICU_voidSetCallBack(void(*ptrtofunc)(void));





#endif
