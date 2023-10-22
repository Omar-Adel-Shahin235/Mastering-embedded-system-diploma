/*
 * I2C_EEPROM.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Acer
 */

#ifndef INCLUDES_I2C_EEPROM_H_
#define INCLUDES_I2C_EEPROM_H_

#include "Stm32f103x6.h"
#include "Stm32f103c6_I2C_Driver.h"

#define EEPROM_Slave_address   0x2A

//APIs

void EEPROM_Init(void);
void EEPROM_Send_NBytes(uint16_t address ,uint8_t* data_byte , uint8_t data_length);
void EEPROM_read_Bytes(uint16_t address ,uint8_t* data_byte , uint8_t data_length);

#endif /* INCLUDES_I2C_EEPROM_H_ */
