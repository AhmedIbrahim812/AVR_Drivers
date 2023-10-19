/******************* Layer : MCAL *********************/
/******************* Author : Ahmed *******************/
/******************* Version : 01 *********************/
/****** ************ Layer : MCAL *********************/
/****************** Date : 30/8/2023 ******************/
/****************** COmponent : ADC ******************/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_



/*
 * Options for the pre scaler
 * 1-> DIV_BY_TWO
 * 2-> DIV_BY_FOUR
 * 3-> DIV_BY_EIGHT
 * .
 * .
 * 8->      by 128
 *
 *
 */


/*
 * Options for Channels
 * CHANNEL_ZERO
 * CHANNEL_ONE
 * CHANNEL_TWO
 * CHANNEL_THREE
 */

#define PRESCALER  DIV_BY_EIGHT
#define CHANNEL    CHANNEL_ZERO

#endif
