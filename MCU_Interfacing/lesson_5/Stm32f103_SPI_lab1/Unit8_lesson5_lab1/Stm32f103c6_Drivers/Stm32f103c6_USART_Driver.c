/*
 * Stm32f103c6_RCC_Driver.c
 *
 *  Created on: Sep 18, 2023
 *      Author: omar
 */

#include "Stm32f103c6_USART_Driver.h"


/*
 * ===============================================
 * Generic Macros
 * ===============================================
 */


/*
 * ===============================================
 * Generic Variables
 * ===============================================
 */

UART_Config_t* Global_UART_Config = NULL ;

/*
 * ===============================================
 * Generic Functions definitions
 * ===============================================
 */

/**================================================================
 * @Fn            - MCAL_UART_init
 * @brief         - Initialize UART
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - UART_Config: all UART configuration
 * @retval        - none
 * Note           - none
 */
void MCAL_UART_init(USART_TypeDef* USARTx , UART_Config_t* UART_Config)
{
	Global_UART_Config = UART_Config;
	uint32_t P_clk ;

	//enable clock
	if(USARTx == USART1)
		RCC_USART1_CLK_EN;

	else if(USARTx == USART2)
		RCC_USART2_CLK_EN;

	else if(USARTx == USART3)
		RCC_USART3_CLK_EN;

	//Enable UART Module
	USARTx->CR1 |= (1<<13);

	//Enable UART Tx or Rx based on UART_MODE
	USARTx->CR1 |= UART_Config->UART_Mode;

	//Payload length based on UART payload length
	USARTx->CR1 |= UART_Config->UART_Payload_Length;

	//Configure parity based on UART_parity
	USARTx->CR1 |= UART_Config->UART_Parity;

	//Configure stop bits
	USARTx->CR2 |= UART_Config->UART_StopBits;

	//hardware flow control
	USARTx->CR3 |= UART_Config->UART_FlowCtrl;

	//Baud rate
	if(USARTx == USART1)
		P_clk =  MCAL_RCC_GetPCLK2Freq();
	else
		P_clk =  MCAL_RCC_GetPCLK1Freq();

	USARTx->BRR = UART_BRR_Register(P_clk ,UART_Config->UART_BaudRate);


	//ENABLE/DISABLE interrupt
	if(UART_Config->UART_IRQ_Enable != UART_IRQ_Enable_none)
	{
		USARTx->CR1 |= UART_Config->UART_IRQ_Enable;

		//Enable NVIC
		if(USARTx == USART1)
			//NVIC_IRQ37_USART1_EN;
			*((volatile uint32_t *)0xE000E104UL) |= (1<<(37-32));

		else if(USARTx == USART2)
			*((volatile uint32_t *)0xE000E104UL) |= (1<<(38-32));

		else if(USARTx == USART3)
			*((volatile uint32_t *)0xE000E104UL) |= (1<<(39-32));
	}

}


/**================================================================
 * @Fn            - MCAL_UART_Deinit
 * @brief         - DeInitialize UART
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @retval        - none
 * Note           - none
 */
void MCAL_UART_Deinit(USART_TypeDef* USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_CLK_DIS;
		NVIC_IRQ37_USART1_DIS;
	}

	else if(USARTx == USART2)
	{
		RCC_USART2_CLK_DIS ;
		NVIC_IRQ38_USART2_DIS;
	}

	else if(USARTx == USART3)
	{
		RCC_USART3_CLK_DIS ;
		NVIC_IRQ39_USART3_DIS;
	}
}

void MCAL_UART_GPIO_SetPins(USART_TypeDef* USARTx)
{
	GPIO_PinConfig_t PinCfg;

	if(USARTx == USART1)
	{
		//PA9 --> Tx
		PinCfg.GPIO_pinNumber = GPIO_PIN9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA , &PinCfg );

		//PA10 --> Rx
		PinCfg.GPIO_pinNumber = GPIO_PIN10;
		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA , &PinCfg );


		if(Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS || Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS_RTS)
		{
			//PA11 --> CTS
			PinCfg.GPIO_pinNumber = GPIO_PIN11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &PinCfg );
		}

		if(Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_RTS || Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS_RTS)
		{
			//PA12 --> RTS
			PinCfg.GPIO_pinNumber = GPIO_PIN12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA , &PinCfg );
		}

	}
	else if(USARTx == USART2)
	{

		//PA2 --> Tx
		PinCfg.GPIO_pinNumber = GPIO_PIN2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA , &PinCfg );

		//PA3 --> Rx
		PinCfg.GPIO_pinNumber = GPIO_PIN3;
		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOA , &PinCfg );


		if(Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS || Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS_RTS)
		{
			//PA0 --> CTS
			PinCfg.GPIO_pinNumber = GPIO_PIN0;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &PinCfg );
		}

		if(Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_RTS || Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS_RTS)
		{
			//PA1 --> RTS
			PinCfg.GPIO_pinNumber = GPIO_PIN1;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA , &PinCfg );
		}

	}
	else if(USARTx == USART3)
	{

		//PB10 --> Tx
		PinCfg.GPIO_pinNumber = GPIO_PIN10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB , &PinCfg );

		//PB11 --> Rx
		PinCfg.GPIO_pinNumber = GPIO_PIN11;
		PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(GPIOB , &PinCfg );


		if(Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS || Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS_RTS)
		{
			//PA13 --> CTS
			PinCfg.GPIO_pinNumber = GPIO_PIN13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB , &PinCfg );
		}

		if(Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_RTS || Global_UART_Config->UART_FlowCtrl == UART_FlowCtrl_CTS_RTS)
		{
			//PA14 --> RTS
			PinCfg.GPIO_pinNumber = GPIO_PIN14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB , &PinCfg );
		}

	}

}

/**================================================================
 * @Fn            - MCAL_UART_Send_Data
 * @brief         - Send buffer to UART
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - p_TxBuffer: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - Polling: Enable polling or disable it
 * @retval        - none
 * Note           - none
 */
void MCAL_UART_Send_Data(USART_TypeDef* USARTx , uint16_t* p_TxBuffer , Polling_mechanism Polling)
{
	if(Polling == Polling_EN)
		while(((USARTx->SR >>7)&1) == 0);

	if(Global_UART_Config->UART_Payload_Length == UART_Payload_Length_9bit)
	{
		USARTx->DR = ((*p_TxBuffer) & (uint16_t)0x1FF );
	}
	else
	{
		USARTx->DR = ((*p_TxBuffer) & (uint8_t)0xFF );
	}
}


void MCAL_UART_Receive_Data(USART_TypeDef* USARTx , uint16_t* p_TxBuffer , Polling_mechanism Polling)
{
	if(Polling == Polling_EN)
		while(((USARTx->SR >>5)&1) == 0);

	if(Global_UART_Config->UART_Payload_Length == UART_Payload_Length_9bit)
	{
		if(Global_UART_Config->UART_Parity == UART_Parity_none)
		{
			*((uint16_t*)p_TxBuffer) = USARTx->DR;
		}
		else
		{
			*((uint16_t*)p_TxBuffer) = ( USARTx->DR  & (uint16_t)0xFF );
		}
	}
	else
	{
		if(Global_UART_Config->UART_Parity == UART_Parity_none)
		{
			*((uint16_t*)p_TxBuffer) = ( USARTx->DR  & (uint16_t)0xFF );
		}
		else
		{
			*((uint16_t*)p_TxBuffer) = ( USARTx->DR  & (uint16_t)0x7F );
		}
	}
}

void MCAL_UART_Wait_TC(USART_TypeDef* USARTx)
{
	//wait until TC flag is set
	while(((USARTx->SR >>6)&1) == 0);
}


//ISR

void USART1_IRQHandler(void)
{
	/* USART1 global interrupt */
	Global_UART_Config->P_IRQ_callback ();
}

void USART2_IRQHandler(void)
{
	/* USART2 global interrupt */
	Global_UART_Config->P_IRQ_callback ();
}

void USART3_IRQHandler(void)
{
	/* USART3 global interrupt */
	Global_UART_Config->P_IRQ_callback ();
}



