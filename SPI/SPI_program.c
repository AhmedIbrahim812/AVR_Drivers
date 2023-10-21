#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_interface.h"


void SPI_voidIntMstr(void)
{
	//int as a master
SET_BIT(SPCR,SPCR_MSTR);
// spi enable
SET_BIT(SPCR,SPCR_SPE);
// prescaler 64  is only at master becaouse only the master generates clock
SET_BIT(SPCR,SPCR_SPR0);
SET_BIT(SPCR,SPCR_SPR1);
SET_BIT(SPSR,SPSR_SPI2X);
}
void SPI_voidIntSlave(void)
{
	CLR_BIT(SPCR,SPCR_MSTR);
	SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_u8Transeve(u8 Copy_Data)
{
	SPDR=Copy_Data;
	while(!GET_BIT(SPSR,SPSR_SPIF));
	return SPDR;
}



