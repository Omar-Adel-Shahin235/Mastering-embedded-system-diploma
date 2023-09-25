/*
 * Stm32f103c6_RCC_Driver.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Acer
 */

#ifndef INC_STM32F103C6_RCC_DRIVER_H_
#define INC_STM32F103C6_RCC_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------


//-----------------------------
//Macros Configuration References
//-----------------------------

#define HSI_CLK     (uint32_t)8000000

#define HSE_CLK     (uint32_t)16000000

/*
* ===============================================
* APIs Supported by "MCAL RCC DRIVER"
* ===============================================
*/

uint32_t MCAL_RCC_GetSysCLK(void);
uint32_t MCAL_RCC_GetPCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);


#endif /* INC_STM32F103C6_RCC_DRIVER_H_ */
