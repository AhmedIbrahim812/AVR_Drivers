

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_interface.h"
#include "I2C_config.h"
#include "I2C_private.h"



void TWI_voidMastrInit(u8 Copy_u8Address)
{
	//set the address at the most left 7 bits
	TWAR= Copy_u8Address<<1;

	// bit rate Pre scaler = 1 (no pre scaler)
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	// clock prescaler = 16
	TWBR=2;

	//enable ack
	SET_BIT(TWCR,TWCR_TWEA);

	// I2C enable
	SET_BIT(TWCR,TWCR_TWEN);

}
void TWI_voidSlaveInit(u8 Copy_u8Address)
{
	TWAR= Copy_u8Address<<1;

	//enable ack
	SET_BIT(TWCR,TWCR_TWEA);
	// I2C enable
	SET_BIT(TWCR,TWCR_TWEN);

}
TWI_state TWI_SendStartCondition(void){
	//send data and return error type if any
	u8 local_error=no_error;

	// Start Condition
	SET_BIT(TWCR,TWCR_TWSTA);
	// Clear I2C interrupt flag
	SET_BIT(TWCR,TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR&0b11111000)==START_ACK)
	{
	}
	else
		local_error=start_error;
	return local_error;
}
TWI_state TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address)
{
	u8 local_error=no_error;
	// clear start condition, It has been already sent
	CLR_BIT(TWCR,TWCR_TWSTA);
	TWDR=Copy_u8Address<<1;

	//write
	CLR_BIT(TWDR,0);

	// Clear I2C interrupt flag
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR&0b11111000)==SLAVE_ADD_AND_WR_ACK)
	{
	}
	else
		local_error= slave_addresswith_write_error;
	return local_error;
}
TWI_state TWI_SendSlaveAddressWithRead(u8 Copy_u8Address){
	u8 local_error=no_error;
	// clear start condition, It has been already sent
	CLR_BIT(TWCR,TWCR_TWSTA);
	TWDR=Copy_u8Address<<1;

	//READ
	SET_BIT(TWDR,0);

	// Clear I2C interrupt flag
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR&0b11111000)==SLAVE_ADD_AND_RD_ACK)
	{
	}
	else
		local_error= slave_addresswith_read_error;
	return local_error;
}
TWI_state TWI_MasterWriteDataByte(u8 Copy_u8Data)
{
	u8 local_error=no_error;
	// Assign data to data register
	TWDR=Copy_u8Data;

	// Clear I2C interrupt flag
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR&0b11111000)==MSTR_WR_BYTE_WITH_ACK)
	{
	}
	else
		local_error= master_write_data_error;
	return local_error;

}
TWI_state TWI_MasterReadDataByte(u8 *Copy_u8Data)
{

	u8 local_error=no_error;

	// Clear I2C interrupt flag
	SET_BIT(TWCR,TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT)==0);
	if ((TWSR&0b11111000)==MSTR_RD_BYTE_WITH_ACK)
	{
	}
	else
		local_error= master_read_data_error;

	// return the data in data register into an address
	*Copy_u8Data=TWDR;
	return local_error;


}
void TWI_SendStopCondition(void)
{
	//Stop condition
	SET_BIT(TWCR,TWCR_TWSTO);

	// Clear I2C interrupt flag
	SET_BIT(TWCR,TWCR_TWINT);
}















