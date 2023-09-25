/*
 * Stm32f103c6_USART_Driver.h
 *
 *  Created on: Sep 19, 2023
 *      Author: OMAR
 */

#ifndef INC_STM32F103C6_USART_DRIVER_H_
#define INC_STM32F103C6_USART_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103c6_RCC_Driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint8_t UART_Mode       	 ;  //specify Tx/Rx  enable/disable
								   //this parameter must be set based on @ref UART_MODE_define

	uint32_t UART_BaudRate  	 ; //specify the UART communication baud rate
							  	  //this parameter can be a value of @ref UART_BaudRate_define

	uint8_t UART_Payload_Length  ; //specify the number of data bits that transmitted or received in frame
							      //this parameter can be a value of @ref UART_Payload_Length_define

	uint8_t UART_Parity  		 ; //specify the parity mode
							      //this parameter can be a value of @ref UART_Parity_define

	uint8_t UART_StopBits  		 ; //specify the number of stop bits
								  //this parameter can be a value of @ref UART_StopBits_define

	uint8_t UART_FlowCtrl  		 ; //specify the flow control bits CTS/RTS enabled/disabled
								  //this parameter can be a value of @ref UART_FlowCtrl_define

	uint8_t UART_IRQ_Enable      ; //Enable of disable IRQ for tx/rx
								  //this parameter can be a value of @ref UART_IRQ_Enable _define

	void(* P_IRQ_callback)(void) ; //pointer to function that called when IRQ happen

}UART_Config_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref UART_MODE_define
#define UART_MODE_Rx			(uint32_t)(1<<3)  				 //Bit 3 TE: Transmitter enable
#define UART_MODE_Tx			(uint32_t)(1<<2)   				 //Bit 2 RE: Receiver enable
#define UART_MODE_Rx_Tx			(uint32_t)((1<<3) | ((1<<2)))	 //Transmitter enable & Receiver enable


//@ref UART_BaudRate_define
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_230400		230400
#define UART_BaudRate_2250000		2250000
#define UART_BaudRate_4500000		4500000


//@ref UART_Payload_Length_define
#define UART_Payload_Length_8bit			(uint32_t)0
#define UART_Payload_Length_9bit			(uint32_t)(1<<12)


//@ref UART_Parity_define
#define UART_Parity_none 					(uint32_t)0
#define UART_Parity_even 					(uint32_t)(1<<10)
#define UART_Parity_odd 					(uint32_t)((1<<10) | ((1<<9)))


//@ref UART_StopBits_define
#define  UART_StopBits_half					(uint32_t)(1<<12)
#define  UART_StopBits_1					(uint32_t)(0)
#define  UART_StopBits_1_half				(uint32_t)((1<<12) | ((1<<13)))
#define  UART_StopBits_2					(uint32_t)(1<<13)


//@ref UART_FlowCtrl_define
#define  UART_FlowCtrl_none					(uint32_t)(0)
#define  UART_FlowCtrl_CTS					(uint32_t)(1<<9)
#define  UART_FlowCtrl_RTS					(uint32_t)(1<<8)
#define  UART_FlowCtrl_CTS_RTS				(uint32_t)((1<<8) | ((1<<9)))


//@ref UART_IRQ_Enable _define
#define  UART_IRQ_Enable_none				(uint32_t)(0)
#define  UART_IRQ_Enable_TXE				(uint32_t)(1<<7)
#define  UART_IRQ_Enable_TC					(uint32_t)(1<<6)
#define  UART_IRQ_Enable_RXNEIE				(uint32_t)(1<<5)
#define  UART_IRQ_Enable_PE					(uint32_t)(1<<8)


#define UART_mantissa(P_clk ,baud)		(uint32_t)(P_clk / (baud*16))
#define UART_MulBy100(P_clk ,baud)		(uint32_t)( (25*P_clk) / (baud*4) )
#define UART_fraction(P_clk ,baud)		(uint32_t)((UART_MulBy100(P_clk ,baud) - (UART_mantissa(P_clk ,baud)*100))*16 / 100 )
#define UART_BRR_Register(P_clk ,baud)  ( (UART_mantissa(P_clk ,baud)<<4) | (UART_fraction(P_clk ,baud)& 0xF) )

typedef enum
{
	Polling_DIS ,
	Polling_EN
}Polling_mechanism;
/*
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/

void MCAL_UART_init(USART_TypeDef* USARTx , UART_Config_t* UART_Config);
void MCAL_UART_Deinit(USART_TypeDef* USARTx);

void MCAL_UART_GPIO_SetPins(USART_TypeDef* USARTx);

void MCAL_UART_Send_Data(USART_TypeDef* USARTx , uint16_t* p_TxBuffer , Polling_mechanism Polling);
void MCAL_UART_Receive_Data(USART_TypeDef* USARTx , uint16_t* p_TxBuffer , Polling_mechanism Polling);

void MCAL_UART_Wait_TC(USART_TypeDef* USARTx);

#endif /* INC_STM32F103C6_USART_DRIVER_H_ */
