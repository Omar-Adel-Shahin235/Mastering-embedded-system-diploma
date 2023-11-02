/*
 * Key_pad.h
 *
 * Created: 9/8/2023 1:46:14 AM
 *  Author: Acer
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "Register_map.h"
#include <util/delay.h>

#define Key_pad_PORT         PORTD
#define Key_pad_Dir_PORT	 DDRD
#define Key_pad_PIN          PIND

//ROWS
#define R0                   0
#define R1                   1
#define R2                   2
#define R3                   3

//Columns
#define C0                   4
#define C1                   5
#define C2                   6
#define C3                   7

void Key_pad_init();
char Key_pad_get_char();

#endif /* KEY_PAD_H_ */