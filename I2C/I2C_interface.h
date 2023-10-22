/*
 * I2C_interface.h
 *
 *  Created on: Sep 19, 2023
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_


typedef enum
{
	no_error,
    start_error,
    slave_addresswith_write_error,
    slave_addresswith_read_error,
	master_read_data_error,
	master_write_data_error,
}TWI_state; //TWI two wire interface (I2C)


void TWI_voidMastrInit(u8 Copy_u8Address);
void TWI_voidSlaveInit(u8 Copy_u8Address);
TWI_state TWI_SendStartCondition(void); //send data and return error type if any
TWI_state TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address);
TWI_state TWI_SendSlaveAddressWithRead(u8 Copy_u8Address);
TWI_state TWI_MasterWriteDataByte(u8 Copy_u8Data);
TWI_state TWI_MasterReadDataByte(u8 *Copy_u8Data);
void TWI_SendStopCondition(void);


#endif /* I2C_INTERFACE_H_ */
