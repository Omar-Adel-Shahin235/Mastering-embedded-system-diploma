/*
 * Key_pad.h
 *
 * Created: 9/8/2023 1:46:14 AM
 *  Author: Acer
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"

#define Key_pad_PORT         GPIOB


//ROWS
#define R0                   GPIO_PIN0
#define R1                   GPIO_PIN1
#define R2                   GPIO_PIN3
#define R3                   GPIO_PIN4

//Columns
#define C0                   GPIO_PIN5
#define C1                   GPIO_PIN6
#define C2                   GPIO_PIN7
#define C3                   GPIO_PIN8

void Key_pad_init();
char Key_pad_get_char();

#endif /* KEY_PAD_H_ */
