/*
 * Stm32f103c6_EXTI_Driver.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Acer
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint16_t		 EXI_InputLineNumber;
	GPIO_TypeDef*    GPIO_Port;
	uint16_t 		 GPIO_Pin;
	uint8_t          IVR_IRQ_Number;

}EXTI_GPIO_Mapping_t;


typedef struct
{
	EXTI_GPIO_Mapping_t		 EXTI_Pin;       //Specifies the external interuppt GPIO mapping
									        //this parameter must be set based on @ref EXTI_define

	uint8_t     			 Trigger_case;  //Specifies Rising or Falling or both
	   	   	   	   	   	   	   	   	   	   //this parameter must be set based on @ref EXTI_TRIGGER_define

	uint8_t     			 EXTI_EN;  	  //Enable and Disable the EXTI IRQ (enable the IRQ mask in EXTI and also on the NVIC
		   	   	   	   	   	   	   	   	 //this parameter must be set based on @ref EXTI_IRQ_define

	void (* P_IRQ_Call_Back)(void);     //pointer to C function that called when IRQ is happen
}EXTI_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

#define EXTI0          0
#define EXTI1          1
#define EXTI2          2
#define EXTI3          3
#define EXTI4          4
#define EXTI5          5
#define EXTI6          6
#define EXTI7          7
#define EXTI8          8
#define EXTI9          9
#define EXTI10         10
#define EXTI11         11
#define EXTI12         12
#define EXTI13         13
#define EXTI14         14
#define EXTI15         15


/*
@ref EXTI_define
*/
//EXTI0
#define EXTI_PA0                (EXTI_GPIO_Mapping_t){ EXTI0  , GPIOA  ,  GPIO_PIN0  , EXTI0_IRQ }
#define EXTI_PB0                (EXTI_GPIO_Mapping_t){ EXTI0  , GPIOB  ,  GPIO_PIN0  , EXTI0_IRQ }
#define EXTI_PC0                (EXTI_GPIO_Mapping_t){ EXTI0  , GPIOC  ,  GPIO_PIN0  , EXTI0_IRQ }
#define EXTI_PD0                (EXTI_GPIO_Mapping_t){ EXTI0  , GPIOD  ,  GPIO_PIN0  , EXTI0_IRQ }

//EXTI1
#define EXTI_PA1                (EXTI_GPIO_Mapping_t){ EXTI1  , GPIOA  ,  GPIO_PIN1  , EXTI1_IRQ }
#define EXTI_PB1                (EXTI_GPIO_Mapping_t){ EXTI1  , GPIOB  ,  GPIO_PIN1  , EXTI1_IRQ }
#define EXTI_PC1                (EXTI_GPIO_Mapping_t){ EXTI1  , GPIOC  ,  GPIO_PIN1  , EXTI1_IRQ }
#define EXTI_PD1                (EXTI_GPIO_Mapping_t){ EXTI1  , GPIOD  ,  GPIO_PIN1  , EXTI1_IRQ }

//EXTI2
#define EXTI_PA2                (EXTI_GPIO_Mapping_t){ EXTI2  , GPIOA  ,  GPIO_PIN2  , EXTI2_IRQ }
#define EXTI_PB2                (EXTI_GPIO_Mapping_t){ EXTI2  , GPIOB  ,  GPIO_PIN2  , EXTI2_IRQ }
#define EXTI_PC2                (EXTI_GPIO_Mapping_t){ EXTI2  , GPIOC  ,  GPIO_PIN2  , EXTI2_IRQ }
#define EXTI_PD2                (EXTI_GPIO_Mapping_t){ EXTI2  , GPIOD  ,  GPIO_PIN2  , EXTI2_IRQ }

//EXTI3
#define EXTI_PA3                (EXTI_GPIO_Mapping_t){ EXTI3  , GPIOA  ,  GPIO_PIN3  , EXTI3_IRQ }
#define EXTI_PB3                (EXTI_GPIO_Mapping_t){ EXTI3  , GPIOB  ,  GPIO_PIN3  , EXTI3_IRQ }
#define EXTI_PC3                (EXTI_GPIO_Mapping_t){ EXTI3  , GPIOC  ,  GPIO_PIN3  , EXTI3_IRQ }
#define EXTI_PD3                (EXTI_GPIO_Mapping_t){ EXTI3  , GPIOD  ,  GPIO_PIN3  , EXTI3_IRQ }

//EXTI4
#define EXTI_PA4                (EXTI_GPIO_Mapping_t){ EXTI4  , GPIOA  ,  GPIO_PIN4  , EXTI4_IRQ }
#define EXTI_PB4                (EXTI_GPIO_Mapping_t){ EXTI4  , GPIOB  ,  GPIO_PIN4  , EXTI4_IRQ }
#define EXTI_PC4                (EXTI_GPIO_Mapping_t){ EXTI4  , GPIOC  ,  GPIO_PIN4  , EXTI4_IRQ }
#define EXTI_PD4                (EXTI_GPIO_Mapping_t){ EXTI4  , GPIOD  ,  GPIO_PIN4  , EXTI4_IRQ }

//EXTI5
#define EXTI_PA5                (EXTI_GPIO_Mapping_t){ EXTI5  , GPIOA  ,  GPIO_PIN5  , EXTI5_IRQ }
#define EXTI_PB5                (EXTI_GPIO_Mapping_t){ EXTI5  , GPIOB  ,  GPIO_PIN5  , EXTI5_IRQ }
#define EXTI_PC5                (EXTI_GPIO_Mapping_t){ EXTI5  , GPIOC  ,  GPIO_PIN5  , EXTI5_IRQ }
#define EXTI_PD5                (EXTI_GPIO_Mapping_t){ EXTI5  , GPIOD  ,  GPIO_PIN5  , EXTI5_IRQ }

//EXTI6
#define EXTI_PA6                (EXTI_GPIO_Mapping_t){ EXTI6  , GPIOA  ,  GPIO_PIN6  , EXTI6_IRQ }
#define EXTI_PB6                (EXTI_GPIO_Mapping_t){ EXTI6  , GPIOB  ,  GPIO_PIN6  , EXTI6_IRQ }
#define EXTI_PC6                (EXTI_GPIO_Mapping_t){ EXTI6  , GPIOC  ,  GPIO_PIN6  , EXTI6_IRQ }
#define EXTI_PD6                (EXTI_GPIO_Mapping_t){ EXTI6  , GPIOD  ,  GPIO_PIN6  , EXTI6_IRQ }

//EXTI7
#define EXTI_PA7                (EXTI_GPIO_Mapping_t){ EXTI7  , GPIOA  ,  GPIO_PIN7  , EXTI7_IRQ }
#define EXTI_PB7                (EXTI_GPIO_Mapping_t){ EXTI7  , GPIOB  ,  GPIO_PIN7  , EXTI7_IRQ }
#define EXTI_PC7                (EXTI_GPIO_Mapping_t){ EXTI7  , GPIOC  ,  GPIO_PIN7  , EXTI7_IRQ }
#define EXTI_PD7                (EXTI_GPIO_Mapping_t){ EXTI7  , GPIOD  ,  GPIO_PIN7  , EXTI7_IRQ }

//EXTI8
#define EXTI_PA8                (EXTI_GPIO_Mapping_t){ EXTI8  , GPIOA  ,  GPIO_PIN8  , EXTI8_IRQ }
#define EXTI_PB8                (EXTI_GPIO_Mapping_t){ EXTI8  , GPIOB  ,  GPIO_PIN8  , EXTI8_IRQ }
#define EXTI_PC8                (EXTI_GPIO_Mapping_t){ EXTI8  , GPIOC  ,  GPIO_PIN8  , EXTI8_IRQ }
#define EXTI_PD8                (EXTI_GPIO_Mapping_t){ EXTI8  , GPIOD  ,  GPIO_PIN8  , EXTI8_IRQ }

//EXTI9
#define EXTI_PA9                (EXTI_GPIO_Mapping_t){ EXTI9  , GPIOA  ,  GPIO_PIN9  , EXTI9_IRQ }
#define EXTI_PB9                (EXTI_GPIO_Mapping_t){ EXTI9  , GPIOB  ,  GPIO_PIN9  , EXTI9_IRQ }
#define EXTI_PC9                (EXTI_GPIO_Mapping_t){ EXTI9  , GPIOC  ,  GPIO_PIN9  , EXTI9_IRQ }
#define EXTI_PD9                (EXTI_GPIO_Mapping_t){ EXTI9  , GPIOD  ,  GPIO_PIN9  , EXTI9_IRQ }

//EXTI10
#define EXTI_PA10               (EXTI_GPIO_Mapping_t){ EXTI10  , GPIOA  ,  GPIO_PIN10  , EXTI10_IRQ }
#define EXTI_PB10               (EXTI_GPIO_Mapping_t){ EXTI10  , GPIOB  ,  GPIO_PIN10  , EXTI10_IRQ }
#define EXTI_PC10               (EXTI_GPIO_Mapping_t){ EXTI10  , GPIOC  ,  GPIO_PIN10  , EXTI10_IRQ }
#define EXTI_PD10               (EXTI_GPIO_Mapping_t){ EXTI10  , GPIOD  ,  GPIO_PIN10  , EXTI10_IRQ }

//EXTI11
#define EXTI_PA11               (EXTI_GPIO_Mapping_t){ EXTI11  , GPIOA  ,  GPIO_PIN11  , EXTI11_IRQ }
#define EXTI_PB11               (EXTI_GPIO_Mapping_t){ EXTI11  , GPIOB  ,  GPIO_PIN11  , EXTI11_IRQ }
#define EXTI_PC11               (EXTI_GPIO_Mapping_t){ EXTI11  , GPIOC  ,  GPIO_PIN11  , EXTI11_IRQ }
#define EXTI_PD11               (EXTI_GPIO_Mapping_t){ EXTI11  , GPIOD  ,  GPIO_PIN11  , EXTI11_IRQ }

//EXTI12
#define EXTI_PA12               (EXTI_GPIO_Mapping_t){ EXTI12  , GPIOA  ,  GPIO_PIN12  , EXTI12_IRQ }
#define EXTI_PB12               (EXTI_GPIO_Mapping_t){ EXTI12  , GPIOB  ,  GPIO_PIN12  , EXTI12_IRQ }
#define EXTI_PC12               (EXTI_GPIO_Mapping_t){ EXTI12  , GPIOC  ,  GPIO_PIN12  , EXTI12_IRQ }
#define EXTI_PD12               (EXTI_GPIO_Mapping_t){ EXTI12  , GPIOD  ,  GPIO_PIN12  , EXTI12_IRQ }

//EXTI13
#define EXTI_PA13               (EXTI_GPIO_Mapping_t){ EXTI13  , GPIOA  ,  GPIO_PIN13  , EXTI13_IRQ }
#define EXTI_PB13               (EXTI_GPIO_Mapping_t){ EXTI13  , GPIOB  ,  GPIO_PIN13  , EXTI13_IRQ }
#define EXTI_PC13               (EXTI_GPIO_Mapping_t){ EXTI13  , GPIOC  ,  GPIO_PIN13  , EXTI13_IRQ }
#define EXTI_PD13               (EXTI_GPIO_Mapping_t){ EXTI13  , GPIOD  ,  GPIO_PIN13  , EXTI13_IRQ }

//EXTI14
#define EXTI_PA14               (EXTI_GPIO_Mapping_t){ EXTI14  , GPIOA  ,  GPIO_PIN14  , EXTI14_IRQ }
#define EXTI_PB14               (EXTI_GPIO_Mapping_t){ EXTI14  , GPIOB  ,  GPIO_PIN14  , EXTI14_IRQ }
#define EXTI_PC14               (EXTI_GPIO_Mapping_t){ EXTI14  , GPIOC  ,  GPIO_PIN14  , EXTI14_IRQ }
#define EXTI_PD14               (EXTI_GPIO_Mapping_t){ EXTI14  , GPIOD  ,  GPIO_PIN14  , EXTI14_IRQ }

//EXTI15
#define EXTI_PA15               (EXTI_GPIO_Mapping_t){ EXTI15  , GPIOA  ,  GPIO_PIN15  , EXTI15_IRQ }
#define EXTI_PB15               (EXTI_GPIO_Mapping_t){ EXTI15  , GPIOB  ,  GPIO_PIN15  , EXTI15_IRQ }
#define EXTI_PC15               (EXTI_GPIO_Mapping_t){ EXTI15  , GPIOC  ,  GPIO_PIN15  , EXTI15_IRQ }
#define EXTI_PD15               (EXTI_GPIO_Mapping_t){ EXTI15  , GPIOD  ,  GPIO_PIN15  , EXTI15_IRQ }

/*
@ref EXTI_TRIGGER_define
*/
#define EXTI_TRIGGER_Rising                 0
#define EXTI_TRIGGER_Falling   			    1
#define EXTI_TRIGGER_Rising_and_Falling     2

/*
@ref EXTI_IRQ_define
*/
#define EXTI_IRQ_Enable						1
#define EXTI_IRQ_Disable					0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_GPIO_DeInit(void);

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);


#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
