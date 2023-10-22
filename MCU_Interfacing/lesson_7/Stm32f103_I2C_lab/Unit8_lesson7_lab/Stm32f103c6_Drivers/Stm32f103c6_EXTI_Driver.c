/*
 * Stm32f103c6_GPIO_Driver.c
 *
 *  Created on: Sep 8, 2023
 *      Author: omar
 */

#include "Stm32f103c6_EXTI_Driver.h"


/*
* ===============================================
* Generic Macros
* ===============================================
*/
#define AFIO_GPIO_EXTI_Mapping(x)		(x==GPIOA)? 0:((x==GPIOB)? 1:((x==GPIOC)? 2:((x==GPIOD)? 3:0 )))

/*
* ===============================================
* Generic Variables
* ===============================================
*/
void (* GP_IRQ_Call_Back[15])(void);

/*
* ===============================================
* Generic Functions definitions
* ===============================================
*/

void Enable_NVIC(uint8_t EXTI_line)
{
	switch(EXTI_line)
	{
	case 0:
		NVIC_IRQ6_EXTI0_EN;
		break;

	case 1:
		NVIC_IRQ7_EXTI1_EN;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_EN;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_EN;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_EN;
		break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	NVIC_IRQ23_EXTI5_9_EN;
	break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	NVIC_IRQ40_EXTI11_15_EN;
	break;
	}

}

void Disable_NVIC(uint8_t EXTI_line)
{
	switch(EXTI_line)
	{
	case 0:
		NVIC_IRQ6_EXTI0_DIS;
		break;

	case 1:
		NVIC_IRQ7_EXTI1_DIS;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_DIS;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_DIS;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_DIS;
		break;

	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	NVIC_IRQ23_EXTI5_9_DIS;
	break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	NVIC_IRQ40_EXTI11_15_DIS;
	break;
	}
}

void Update_EXTI (EXTI_PinConfig_t* EXTI_Config)
{
	//1- configure GPIO PIN to an AF as floating input
	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_pinNumber = EXTI_Config->EXTI_Pin.GPIO_Pin;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIO_Port , &PinCfg );

	//===============================================
	//2- AFIO to route between EXTI line with PORTS A,B,C and D
	uint8_t AFIO_EXTRCR_index = EXTI_Config->EXTI_Pin.EXI_InputLineNumber / 4 ;
	uint8_t AFIO_EXTRCR_pos   = (EXTI_Config->EXTI_Pin.EXI_InputLineNumber % 4) * 4 ;

	//clear the four bit
	AFIO->EXTICR[AFIO_EXTRCR_index] &= ~(0xF << AFIO_EXTRCR_pos);

	//Enable EXTI line
	AFIO->EXTICR[AFIO_EXTRCR_index] |= ( ( AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_Pin.GPIO_Port) &0xF ) << AFIO_EXTRCR_pos);

	//=============================================
	//3-Update rising and falling edge

	//clear the rising and falling registers
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
	EXTI->FSTR &= ~(1 << EXTI_Config->EXTI_Pin.EXI_InputLineNumber);

	//Enable rising edge or falling edge or both According to user input
	if(EXTI_Config->Trigger_case == EXTI_TRIGGER_Rising)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_case == EXTI_TRIGGER_Falling)
	{
		EXTI->FSTR |= (1 << EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_case == EXTI_TRIGGER_Rising_and_Falling)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
		EXTI->FSTR |= (1 << EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
	}

	//=============================================
	//4-Update IRQ handling callback

	GP_IRQ_Call_Back[EXTI_Config->EXTI_Pin.EXI_InputLineNumber] = EXTI_Config->P_IRQ_Call_Back ;

	//=============================================
	//5-Enable / disable EXTI and NVIC

	if(EXTI_Config->EXTI_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<< EXTI_Config->EXTI_Pin.EXI_InputLineNumber );
		Enable_NVIC(EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
	}
	else
	{
		EXTI->IMR &= ~(1<< EXTI_Config->EXTI_Pin.EXI_InputLineNumber );
		Disable_NVIC(EXTI_Config->EXTI_Pin.EXI_InputLineNumber);
	}

}


/*
* ===============================================
* APIs Functions definitions
* ===============================================
*/

/**================================================================
* @Fn			 - MCAL_EXTI_GPIO_Init
* @brief    	 - Initializes the EXTIO according to specified GPIO pin and specify the mask / trigger condtion and IRQ CallBack
* @param [in]	 - EXTI_Config set by @ref EXTI_define , EXTI_TRIGGER_define and EXTI_IRQ_define
* @param [in] 	 - Pin_config is a pointer to a GPIO_PinConfig_t structure that contains
* 				   the configuration information for the specified GPIO pin
* @retval 		 - none
* Note			 - stm32f103c6 has a GPIO A,B,C,D,E Modules but LQFP48 package has only GPIO A,B and part of C,D and not has E.
*                - must be enable AFIO and RCC
*/
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI (EXTI_Config);
}


/**================================================================
* @Fn			 - MCAL_EXTI_GPIO_DeInit
* @brief    	 - Reset the EXTI registers and NVIC CORRESPONDING IRQ mask
* @param [in]	 - none
* @retval 		 - none
* Note			 -
*/
void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR 	= 0x00000000;
	EXTI->EMR 	= 0x00000000;
	EXTI->RTSR	= 0x00000000;
	EXTI->FSTR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->EMR 	= 0xFFFFFFFF;

	//Disable all IRQ on NVIC
 NVIC_IRQ6_EXTI0_DIS		;
 NVIC_IRQ7_EXTI1_DIS		;
 NVIC_IRQ8_EXTI2_DIS		;
 NVIC_IRQ9_EXTI3_DIS		;
 NVIC_IRQ10_EXTI4_DIS		;
 NVIC_IRQ23_EXTI5_9_DIS		;
 NVIC_IRQ40_EXTI11_15_DIS	;
}


/*
*================================================================
* @Fn			 - MCAL_EXTI_GPIO_Update
* @brief    	 - Initializes the EXTIO according to specified GPIO pin and specify the mask / trigger condtion and IRQ CallBack
* @param [in]	 - EXTI_Config set by @ref EXTI_define , EXTI_TRIGGER_define and EXTI_IRQ_define
* @param [in] 	 - Pin_config is a pointer to a GPIO_PinConfig_t structure that contains
* 				   the configuration information for the specified GPIO pin
* @retval 		 - none
* Note			 - stm32f103c6 has a GPIO A,B,C,D,E Modules but LQFP48 package has only GPIO A,B and part of C,D and not has E.
*                - must be enable AFIO and RCC
*/
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{

	Update_EXTI (EXTI_Config);
}




//======================================
//          ISR Functions
//======================================

void EXTI0_IRQHandler(void)
{


	//Clear pending register
	EXTI->PR |= (1<<0);

	//call IRQ function
	GP_IRQ_Call_Back[0]();
}

void EXTI1_IRQHandler(void)
{
	//GP_IRQ_Call_Back[EXTI_Pin.EXI_InputLineNumber];

	//Clear pending register
	EXTI->PR |= (1<<1);

	//call IRQ function
	GP_IRQ_Call_Back[1]();

}


void EXTI2_IRQHandler(void)
{
	//GP_IRQ_Call_Back[EXTI_Pin.EXI_InputLineNumber];

	//Clear pending register
		EXTI->PR |= (1<<2);

	//call IRQ function
	GP_IRQ_Call_Back[2]();

}


void EXTI3_IRQHandler(void)
{
	//GP_IRQ_Call_Back[EXTI_Pin.EXI_InputLineNumber];

	//Clear pending register
		EXTI->PR |= (1<<3);

	//call IRQ function
	GP_IRQ_Call_Back[3]();
}


void EXTI4_IRQHandler(void)
{
	//GP_IRQ_Call_Back[EXTI_Pin.EXI_InputLineNumber];

	//Clear pending register
	EXTI->PR |= (1<<4);

	//call IRQ function
	GP_IRQ_Call_Back[4]();
}


void EXTI9_5_IRQHandler(void)
{
	//GP_IRQ_Call_Back[EXTI_Pin.EXI_InputLineNumber];

	//Clear pending register and call IRQ function
	if( EXTI->PR & (1<<5) ) { EXTI->PR |= (1<<5); GP_IRQ_Call_Back[5](); }
	if( EXTI->PR & (1<<6) ) { EXTI->PR |= (1<<6); GP_IRQ_Call_Back[6](); }
	if( EXTI->PR & (1<<7) ) { EXTI->PR |= (1<<7); GP_IRQ_Call_Back[7](); }
	if( EXTI->PR & (1<<8) ) { EXTI->PR |= (1<<8); GP_IRQ_Call_Back[8](); }
	if( EXTI->PR & (1<<9) ) { EXTI->PR |= (1<<9); GP_IRQ_Call_Back[9](); }
}


void EXTI15_10_IRQHandler(void)
{
	//Clear pending register and call IRQ function
		if( EXTI->PR & (1<<10) ) { EXTI->PR |= (1<<10); GP_IRQ_Call_Back[10](); }
		if( EXTI->PR & (1<<11) ) { EXTI->PR |= (1<<11); GP_IRQ_Call_Back[11](); }
		if( EXTI->PR & (1<<12) ) { EXTI->PR |= (1<<12); GP_IRQ_Call_Back[12](); }
		if( EXTI->PR & (1<<13) ) { EXTI->PR |= (1<<13); GP_IRQ_Call_Back[13](); }
		if( EXTI->PR & (1<<14) ) { EXTI->PR |= (1<<14); GP_IRQ_Call_Back[14](); }
		if( EXTI->PR & (1<<15) ) { EXTI->PR |= (1<<15); GP_IRQ_Call_Back[15](); }
}

