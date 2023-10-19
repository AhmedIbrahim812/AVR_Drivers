#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"





void ADC_voidInit(void)
{
	//SET VCC as the reference voltage
	SET_BIT(ADMUX,ADMUX_RFS0);
	CLR_BIT(ADMUX,ADMUX_RFS1);
	//Choose left adjust (we can see only 8 bits (most left))
	SET_BIT(ADMUX,ADMUX_ADLAR);

	// Set prescaler
	ADCSRA &=0b11111000;
	ADCSRA |=PRESCALER;

	//Enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u8 ADC_u8GetChannelReading(void)
{
	ADMUX&=ADMUX_CLEAR;
	ADMUX|=CHANNEL;
	// Start conversion
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)){}
	SET_BIT(ADCSRA,ADCSRA_ADIF);

return ADCH;
}














