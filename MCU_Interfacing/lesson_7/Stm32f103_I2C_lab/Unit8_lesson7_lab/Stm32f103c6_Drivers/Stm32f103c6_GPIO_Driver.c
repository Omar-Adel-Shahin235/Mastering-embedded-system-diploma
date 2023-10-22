/*
 * Stm32f103c6_GPIO_Driver.c
 *
 *  Created on: Sep 8, 2023
 *      Author: omar
 */

#include "Stm32f103c6_GPIO_Driver.h"


uint8_t GET_CRLH_position(uint16_t PinNumber)
{
	switch(PinNumber)
	{

	case GPIO_PIN8:
	case GPIO_PIN0:
		return 0;
		break;

	case GPIO_PIN9:
	case GPIO_PIN1:
		return 4;
		break;

	case GPIO_PIN10:
	case GPIO_PIN2:
		return 8;
		break;

	case GPIO_PIN11:
	case GPIO_PIN3:
		return 12;
		break;

	case GPIO_PIN12:
	case GPIO_PIN4:
		return 16;
		break;

	case GPIO_PIN13:
	case GPIO_PIN5:
		return 20;
		break;

	case GPIO_PIN14:
	case GPIO_PIN6:
		return 24;
		break;

	case GPIO_PIN15:
	case GPIO_PIN7:
		return 28;
		break;

	}
	return -1;
}


/**================================================================
* @Fn			 - MCAL_GPIO_Init
* @brief    	 - Initializes the GPIOx PINy according to specified parameters in the Pin_config
* @param [in]	 - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @param [in] 	 - Pin_config is a pointer to a GPIO_PinConfig_t structure that contains
* 				   the configuration information for the specified GPIO pin
* @retval 		 - none
* Note			 - stm32f103c6 has a GPIO A,B,C,D,E Modules but LQFP48 package
*                  has only GPIO A,B and part of C,D and not has E.
*/
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PIN_config)
{
	//Port configuration register low (GPIOx_CRL) Configure pins 0 >>> 7
	//Port configuration register low (GPIOx_CRH) Configure pins 8 >>> 15

	volatile uint32_t *ConfigRegister = NULL;
	uint8_t Pin_config = 0;

	ConfigRegister = (PIN_config->GPIO_pinNumber < GPIO_PIN8 )? &GPIOx->CRL : &GPIOx->CRH ;

	//Clear  CNFy[1:0] MODEy[1:0]
	*ConfigRegister &= ~(0xF << GET_CRLH_position(PIN_config->GPIO_pinNumber) );

	if(PIN_config->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD || PIN_config->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP || PIN_config->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PIN_config->GPIO_MODE == GPIO_MODE_OUTPUT_PP)
	{
		Pin_config = (((( PIN_config->GPIO_MODE - 4 ) <<2) | (PIN_config->GPIO_OUTPUT_Speed)) & 0x0F );
	}
	//if pin is input
	else
	{
		if(PIN_config->GPIO_MODE == GPIO_MODE_Analog || PIN_config->GPIO_MODE == GPIO_MODE_INPUT_FLO)
		{
			Pin_config = ((( PIN_config->GPIO_MODE ) <<2) & 0x0F );
		}
		else if(PIN_config->GPIO_MODE == GPIO_MODE_INPUT_AF)     //consider it as input floating
		{
			Pin_config = ((( GPIO_MODE_INPUT_FLO ) <<2) & 0x0F );
		}
		else
		{
			Pin_config = ((( GPIO_MODE_INPUT_PU ) <<2) & 0x0F );

			if(PIN_config->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//Table 20. Port bit configuration table --> PxODR register -> 1
				GPIOx->ODR |= (PIN_config->GPIO_pinNumber);
			}
			else
			{
				//Table 20. Port bit configuration table --> PxODR register -> 0
				GPIOx->ODR &= ~(PIN_config->GPIO_pinNumber);
			}
		}
	}
	//Write on the CRL or CRH
	*ConfigRegister |= ( (Pin_config)<< GET_CRLH_position(PIN_config->GPIO_pinNumber) );
}


/**================================================================
* @Fn            - MCAL_GPIO_DeInit
* @brief         - reset all specified GPIO registers
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @retval        - none
* Note           - none
*/
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
	/*
	//manually
	GPIOx->CRL =	0x44444444;
	GPIOx->CRH = 	0x44444444;
	GPIOx->ODR = 	0x00000000;
	GPIOx->BSRR =	0x00000000;
	GPIOx->BRR = 	0x00000000;
	GPIOx->LCKR = 	0x00000000;
	*/

	//using reset controller
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}


/**================================================================
* @Fn            - MCAL_GPIO_ReadPin
* @brief         - Read the value of specific PIN
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @param [in]    - PinNumber: Set pin number according @ref GPIO_Pins_define
* @retval        - The input pin value (Two values based on based on @ref GPIO_PIN_state)
* Note           - none
*/
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	uint8_t BitStatues;

	if(  (GPIOx->IDR & PinNumber)  != GPIO_PIN_false )
	{
		BitStatues = GPIO_PIN_true;
	}
	else
	{
		BitStatues = GPIO_PIN_false;
	}

	return BitStatues;
}


/**================================================================
* @Fn            - MCAL_GPIO_ReadPort
* @brief         - Read the input PORT value
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @retval        - The input port Value
* Note           - none
*/
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	uint16_t PortVal;

	PortVal = (uint16_t)GPIOx->IDR;

	return PortVal;
}


/**================================================================
* @Fn            - MCAL_GPIO_WritePin
* @brief         - Write a value to a specific output PIN
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @param [in]    - PinNumber: Set pin number according @ref GPIO_Pins_define
* @param [in]    - Value: the pin value (Two values based on based on @ref GPIO_PIN_state
* @retval        - none
* Note           - none
*/
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t value)
{
	if( value == GPIO_PIN_true )
		{
			GPIOx->BSRR = (uint32_t)PinNumber;
		}
		else
		{
			GPIOx->BRR = (uint32_t)PinNumber;
		}
}


/**================================================================
* @Fn            - MCAL_GPIO_WritePort
* @brief         - Write a value to an output Port
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @param [in]    - Value: the pin value (Two values based on based on @ref GPIO_PIN_state
* @retval        - none
* Note           - none
*/
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx , uint16_t value)
{
	GPIOx->ODR = (uint32_t)value;
}


/**================================================================
* @Fn            - MCAL_GPIO_TogglePin
* @brief         - toggle the value of specific PIN
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @param [in]    - PinNumber: Set pin number according @ref GPIO_Pins_define
* @retval        - none
* Note           - none
*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}

/**================================================================
* @Fn            - MCAL_GPIO_LockPin
* @brief         - the locking mechanism allows the IO configuration to be frozen
* @param [in]    - GPIOx: where x can be A-E (depending on device used) to select the GPIO peripheral
* @param [in]    - PinNumber: Set pin number according @ref GPIO_Pins_define
* @retval        - 'OK' indicates if PIN locked successfully ,otherwise return 'Erorr' (ok and erorr are defined @ref GPIO_RETURN_lock
* Note           - none
*/
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	volatile uint32_t temp = (1<<16);

	//set the LCKy ( the number of bit you want to lock )

	temp |= PinNumber;

	//write 1
	GPIOx->LCKR = temp;

	//write 0
	GPIOx->LCKR = PinNumber;

	//write 1
	GPIOx->LCKR = temp;

	//read
	temp = GPIOx->LCKR;

	if((uint32_t)((GPIOx->LCKR>>16) &1) == GPIO_RETURN_LOCK_Enabled)
	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETURN_LOCK_erorr;
	}
}


