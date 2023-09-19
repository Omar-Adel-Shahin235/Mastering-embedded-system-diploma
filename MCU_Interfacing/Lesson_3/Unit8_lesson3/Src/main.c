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

#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103c6_EXTI_Driver.h"
#include "Stm32f103c6_USART_Driver.h"
#include "LCD.h"
#include "Key_pad.h"

unsigned char IRQ_FLAG = 0;

void clock_init()
{

	RCC_GPIOA_CLK_EN();
	RCC_AFIO_CLK_EN();
}

unsigned char ch;

void Omar_UART_IRQ_Callback()
{
	MCAL_UART_Receive_Data(USART1, &ch, Polling_DIS);
	MCAL_UART_Send_Data(USART1, &ch, Polling_EN);
}


int main(void)
{
	clock_init();

	UART_Config_t UART_Cfg;

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


	while(1)
	{
	//	MCAL_UART_Receive_Data(USART1, &ch, Polling_EN);
	//	MCAL_UART_Send_Data(USART1, &ch, Polling_EN);
	}

}

