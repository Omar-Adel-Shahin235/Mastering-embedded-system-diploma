/*
 * Stm32f103c6_GPIO_Driver.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Acer
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint16_t GPIO_pinNumber        ;  //specify GPIO pin to be configured
							         //this parameter must be set besed on @ref GPIO_Pins_define

	uint8_t GPIO_MODE              ; //specify GPIO pin mode
							        //this parameter can be a value of @ref GPIO_MODE_define

	uint8_t GPIO_OUTPUT_Speed      ; //specify GPIO pin mode
							        //this parameter can be a value of @ref GPIO_SPEED_define

}GPIO_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------
/*
@ref GPIO_Pins_define
*/
#define GPIO_PIN0                         ((uint16_t)0x0001)
#define GPIO_PIN1                         ((uint16_t)0x0002)
#define GPIO_PIN2                         ((uint16_t)0x0004)
#define GPIO_PIN3                         ((uint16_t)0x0008)
#define GPIO_PIN4                         ((uint16_t)0x0010)
#define GPIO_PIN5                         ((uint16_t)0x0020)
#define GPIO_PIN6                         ((uint16_t)0x0040)
#define GPIO_PIN7                         ((uint16_t)0x0080)
#define GPIO_PIN8                         ((uint16_t)0x0100)
#define GPIO_PIN9                         ((uint16_t)0x0200)
#define GPIO_PIN10                        ((uint16_t)0x0400)
#define GPIO_PIN11                        ((uint16_t)0x0800)
#define GPIO_PIN12                        ((uint16_t)0x1000)
#define GPIO_PIN13                        ((uint16_t)0x2000)
#define GPIO_PIN14                        ((uint16_t)0x4000)
#define GPIO_PIN15                        ((uint16_t)0x8000)

/*
@ref GPIO_MODE_define
*/

//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down

//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input

#define GPIO_MODE_Analog                 	0x00000000u
#define GPIO_MODE_INPUT_FLO                 0x00000001u
#define GPIO_MODE_INPUT_PU               	0x00000002u
#define GPIO_MODE_INPUT_PD                  0x00000003u
#define GPIO_MODE_OUTPUT_PP                 0x00000004u
#define GPIO_MODE_OUTPUT_OD                 0x00000005u
#define GPIO_MODE_OUTPUT_AF_PP              0x00000006u
#define GPIO_MODE_OUTPUT_AF_OD              0x00000007u
#define GPIO_MODE_INPUT_AF					0x00000008u

/*
@ref GPIO_SPEED_define
*/

#define GPIO_SPEED_10M                      0x00000002u  //Output mode, max speed 10 MHz. //1
#define GPIO_SPEED_2M                    	0x00000001u  //Output mode, max speed 2 MHz. //2
#define GPIO_SPEED_50M                      0x00000003u  //Output mode, max speed 50 MHz.

/*
@ref GPIO_PIN_state
*/
#define GPIO_PIN_false                      0
#define GPIO_PIN_true                       1

/*
@ref GPIO_RETURN_LOCK
*/
#define GPIO_RETURN_LOCK_Enabled                1
#define GPIO_RETURN_LOCK_erorr                  0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PIN_config);
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx , uint16_t value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
