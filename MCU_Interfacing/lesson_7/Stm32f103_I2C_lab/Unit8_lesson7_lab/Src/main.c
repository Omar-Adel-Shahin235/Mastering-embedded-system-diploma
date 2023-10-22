/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


//#define MASTER_Code
#define SLAVE_Code

#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103c6_EXTI_Driver.h"
#include "Stm32f103c6_USART_Driver.h"
#include "Stm32f103c6_SPI_Driver.h"
#include "Stm32f103c6_I2C_Driver.h"
#include "I2C_EEPROM.h"


unsigned char IRQ_FLAG = 0;

void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

unsigned char ch;


void Omar_UART_IRQ_Callback()
{
#ifdef MASTER_Code

	MCAL_UART_Receive_Data(USART1, &ch, Polling_DIS);
	MCAL_UART_Send_Data(USART1, &ch, Polling_EN);

	//Send to SPI

	//reset SS
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 0);

	//send and receive
	MCAL_SPI_SendReceive_Data(SPI1, &ch, Polling_ENABLE);

	//set SS
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1);

#endif
}


int main(void)
{
	clock_init();
/*
	//========UART init========
	UART_Config_t UART_Cfg;
	GPIO_PinConfig_t PinCfg;

	UART_Cfg.UART_BaudRate = UART_BaudRate_115200;
	UART_Cfg.UART_FlowCtrl = UART_FlowCtrl_none;
	UART_Cfg.UART_IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	UART_Cfg.P_IRQ_callback = Omar_UART_IRQ_Callback;
	UART_Cfg.UART_Parity = UART_Parity_none;
	UART_Cfg.UART_Payload_Length = UART_Payload_Length_8bit;
	UART_Cfg.UART_StopBits = UART_StopBits_1;
	UART_Cfg.UART_Mode = UART_MODE_Rx_Tx;
	MCAL_UART_init(USART1 , &UART_Cfg);

	MCAL_UART_GPIO_SetPins(USART1);


	//========SPI init========
	SPI_Config_t SPI1_cfg;

	//common configuration
	SPI1_cfg.CLK_Phase = SPI_Clock_second_edge_capture;
	SPI1_cfg.CLK_Polarity = SPI_Clock_Polarity_high_idle;
	SPI1_cfg.Communication_Mode = SPI_Communication_2_lines_full_duplex;
	SPI1_cfg.Data_size = SPI_Size_8bit;
	SPI1_cfg.Frame_format = SPI_MSB_First;
	SPI1_cfg.SPI_PreScaler = SPI_Prescaler_8;

#ifdef MASTER_Code
	SPI1_cfg.Device_Mode = SPI_DEVICE_Mode_Master;
	SPI1_cfg.SPI_IRQ_Enable = SPI_IRQ_Enable_none;
	SPI1_cfg.NSS = SPI_NSS_SW_set;
	SPI1_cfg.P_IRQ_callback = NULL;

	//Configures SS PORTA PIN4
	PinCfg.GPIO_pinNumber = GPIO_PIN4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA , &PinCfg);

	//Write 1
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN4, 1);

#endif


#ifdef SLAVE_Code
	SPI1_cfg.Device_Mode = SPI_DEVICE_Mode_Slave;
	SPI1_cfg.SPI_IRQ_Enable = SPI_IRQ_Enable_none;
	SPI1_cfg.NSS = SPI_NSS_hard_slave;
	SPI1_cfg.P_IRQ_callback = NULL;
#endif

	MCAL_SPI_init(SPI1, &SPI1_cfg);
	MCAL_SPI_GPIO_SetPins(SPI1);

*/

	//TEST CASE 1
	uint8_t ch1[]= {0x1 , 0x2 , 0x3 , 0x4 , 0x5 , 0x6 , 0x7};
	uint8_t ch2[7]={0};

	EEPROM_Init();
	EEPROM_Send_NBytes(0xAF, ch1, 7);
	EEPROM_read_Bytes(0xAF, ch2, 7);

	//test case 2

	ch1[0] =0xA;
	ch1[1] =0xB;
	ch1[2] =0xC;
	ch1[3] =0xD;

	EEPROM_Send_NBytes(0xFFF, ch1, 4);
	EEPROM_read_Bytes(0xFFF, ch2, 4);

	while(1)
	{
	//	MCAL_UART_Receive_Data(USART1, &ch, Polling_EN);
	//	MCAL_UART_Send_Data(USART1, &ch, Polling_EN);

	#ifdef SLAVE_Code

	if(((SPI1->SR)&1) == 1)
	{
		MCAL_SPI_SendReceive_Data(SPI1, &ch, Polling_ENABLE);
		MCAL_UART_Send_Data(USART1, &ch, Polling_EN);
	}

	#endif

	}

}


