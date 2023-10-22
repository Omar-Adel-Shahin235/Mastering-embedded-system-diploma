/*
 * I2C_EEPROM.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Acer
 */

#include  "I2C_EEPROM.h"

void EEPROM_Init(void)
{
	I2C_InitTypedef I2C1CFG;

	I2C1CFG.I2C_General_call_address = I2C_CR1_ENGC;
	I2C1CFG.I2C_ACK_CONTROL = I2C_ACK_Enable;
	I2C1CFG.clk_speed = I2C_Sclk_sm_100kH;
	I2C1CFG.I2C_Mode = I2C_Mode_I2C;
	I2C1CFG.P_Slave_event_callback = NULL;
	I2C1CFG.Stretch_mode = I2C_Stretch_enable;

	MCAL_I2C_GPIO_SetPins(I2C1);
	MCAL_I2C_init(I2C1, &I2C1CFG);
}

void EEPROM_Send_NBytes(uint16_t address ,uint8_t* data_byte , uint8_t data_length)
{
	uint8_t i=0;

	uint8_t buffer[256];

	buffer[0] = address >>8;
	buffer[1] = address;

	for(i=2 ; i<(data_length +2) ; i++)
	{
		buffer[i] = data_byte[i-2];
	}

	MCAL_I2C_MASTER_Transmit(I2C1, EEPROM_Slave_address, buffer, (data_length+2), with_stop, Start);


}

void EEPROM_read_Bytes(uint16_t address ,uint8_t* data_byte , uint8_t data_length)
{
	uint8_t i=0;

	uint8_t buffer[2];

	buffer[0] = address >>8;
	buffer[1] = address;


	MCAL_I2C_MASTER_Transmit(I2C1, EEPROM_Slave_address, buffer, 2, with_stop, Start);
	MCAL_I2C_MASTER_Receive(I2C1, EEPROM_Slave_address, data_byte, data_length,with_stop, repeated_start);

}
