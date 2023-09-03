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

typedef volatile unsigned int vuint_32;
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//register addresses

//GPIOA
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL *((vuint_32 *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH *((vuint_32 *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR *((vuint_32 *)(GPIOA_BASE + 0x0C))

//RCC
#define RCC_BASE 0x40021000
#define RCC_APB2ENR  *((vuint_32 *)(RCC_BASE + 0x18))

//EXTI
#define EXTI_BASE 0x40010400
#define EXTI_IMR  *((vuint_32 *)(EXTI_BASE + 0x00))
#define EXTI_RTSR *((vuint_32 *)(EXTI_BASE + 0x08))
#define EXTI_PR   *((vuint_32 *)(EXTI_BASE + 0x14))

//AFIO
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *((vuint_32 *)(AFIO_BASE + 0x08))


//NVIC
#define NVIC_EXTI0 *((vuint_32 *)(0xE000E100))
void clock_init()
{
	/* Enable GPIOA clock */
		RCC_APB2ENR |= 1<<2 ;

	/* Enable AFIO clock */
		RCC_APB2ENR |= (1<<0) ;
}


void GPIO_init()
{
	//pin13 PORTA output
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	//pin0 PORTA input
	GPIOA_CRL |= (1<<2);
}

int main(void)
{
	clock_init();
	GPIO_init();

	//AFIO PORTA pin0
	AFIO_EXTICR1 = 0;

	//Enable EXTI (line 0  )
	EXTI_IMR |= (1<<0);

	//Enable rising edge
	EXTI_RTSR |= (1<<0);

	//Enable NVIC irq6 for EXTI0
	NVIC_EXTI0 |=(1<<6);

    /* Loop forever */
	while(1);
}

void EXTI0_IRQHandler(void)
{
	//IRQ is happend EXTI0 - PORTA , pin0 -> rising edge
	//toggle led pin13
	GPIOA_ODR ^= (1<<13);

	//Clear pending request for line 0
	EXTI_PR |= (1<<0);
}

