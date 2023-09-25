/*
 * Stm32f103c6_SPI_Driver.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Acer
 */

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

struct S_IRQ_SRC
{
	uint8_t TXE:1      ;
	uint8_t RXNE:1     ;
	uint8_t ERRI:1 	   ;
	uint8_t Reserved:5 ;
};

typedef struct
{
	uint16_t Device_Mode       	 ;  //specify SPI Operating mode
								   //this parameter must be set based on @ref SPI_DEVICE_Mode

	uint16_t Communication_Mode  ; //specify the SPI communication mode state
							  	  //this parameter can be a value of @ref SPI_Communication_Mode

	uint16_t Frame_format	     ; //specify the LSB OR MSB in frame
							      //this parameter can be a value of @ref SPI_Frame_format

	uint16_t Data_size  		 ; //specify the frame size
							      //this parameter can be a value of @ref SPI_Data_size

	uint16_t CLK_Polarity  		 ; //specify the clock polarity
								  //this parameter can be a value of @ref SPI_Clock_Polarity

	uint16_t CLK_Phase  		 ; //specify the clock phase
								  //this parameter can be a value of @ref SPI_Clock_Phase

	uint16_t NSS    		     ; //specify of NSS signal is managed by software or hardware
								  //this parameter can be a value of @ref SPI_NSS

	uint16_t SPI_PreScaler       ; //specify of PreScaler of the clock
								  //this parameter can be a value of @ref SPI_prescaler

	uint16_t SPI_IRQ_Enable     ; //Enable of disable IRQ for SPI
								  //this parameter can be a value of @ref SPI_IRQ_Enable

	void(* P_IRQ_callback)(struct S_IRQ_SRC IRQ_SRC) ; //pointer to function that called when IRQ happen

}SPI_Config_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_DEVICE_Mode
#define SPI_DEVICE_Mode_Slave    (0x00000000U)
#define SPI_DEVICE_Mode_Master   (0x1<<2)       //CR1.MSTR


//@ref SPI_Communication_Mode
#define SPI_Communication_2_lines_full_duplex    (0x00000000U)
#define SPI_Communication_2_lines_Receive_only   (0x1<<10)			     //CR1.RXONLY
#define SPI_Communication_1_line_Receive_only    (0x1<<15)			     //CR1.BIDIMODE
#define SPI_Communication_1_line_Transmit_only   ((0x1<<15) | (0x1<<14)) //CR1.BIDIMODE & //CR1.BIDIOE


//@ref SPI_Frame_format
#define SPI_MSB_First           (0x00000000U)
#define SPI_LSB_First           (0x1<<7)

//@ref SPI_Data_size
#define SPI_Size_8bit           (0x00000000U)
#define SPI_Size_16bit          (0x1<<11)


//@ref SPI_Clock_Polarity
#define SPI_Clock_Polarity_low_idle 		(0x00000000U)
#define SPI_Clock_Polarity_high_idle 		(0x1<<1)


//@ref SPI_Clock_Phase
#define SPI_Clock_first_edge_capture	    (0x00000000U)
#define SPI_Clock_second_edge_capture		(0x1<<0)


//@ref SPI_NSS

//Hardware
#define SPI_NSS_hard_slave 		  (0x00000000U)
#define SPI_NSS_SS_output_enable  (0x1<<2)		  //CR2.SSOE
#define SPI_NSS_SS_output_disable ~(0x1<<2)      //CR2.SSOE

//Software
#define SPI_NSS_SW_reset    	  (0x1<<9)
#define SPI_NSS_SW_set            ((0x1<<9) | (0x1<<8))


//@ref SPI_prescaler
#define SPI_Prescaler_2 	      (0x00000000U)
#define SPI_Prescaler_4 		  (0b001 << 3)
#define SPI_Prescaler_8 		  (0b010 << 3)
#define SPI_Prescaler_16 		  (0b011 << 3)
#define SPI_Prescaler_32 		  (0b100 << 3)
#define SPI_Prescaler_64          (0b101 << 3)
#define SPI_Prescaler_128         (0b110 << 3)
#define SPI_Prescaler_256         (0b111 << 3)


//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_none       (0x00000000U)
#define SPI_IRQ_Enable_TXEIE      (0x1<<7)
#define SPI_IRQ_Enable_RXNEIE     (0x1<<6)
#define SPI_IRQ_Enable_ERRIE      (0x1<<5)


typedef enum
{
	Polling_DISABLE ,
	Polling_ENABLE
}SPI_Polling_mechanism;

/*
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/
void MCAL_SPI_init(SPI_TypeDef* SPIx , SPI_Config_t* SPI_Config);
void MCAL_SPI_Deinit(SPI_TypeDef* SPIx);

void MCAL_SPI_GPIO_SetPins(SPI_TypeDef* SPIx);

void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_mechanism Polling);
void MCAL_SPI_Receive_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_mechanism Polling);

void MCAL_SPI_SendReceive_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_mechanism Polling);

#endif /* INC_STM32F103C6_SPI_DRIVER_H_ */
