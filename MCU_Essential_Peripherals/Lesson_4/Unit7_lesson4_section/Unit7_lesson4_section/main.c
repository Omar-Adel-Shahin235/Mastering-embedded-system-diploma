/*
 * Unit7_lesson2_section.c
 *
 * Created: 9/8/2023 12:25:29 AM
 * Author : Acer
 */ 

//#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

#include "Key_pad.h"
#include "LCD.h"

int main(void)
{
	LCD_init();

	_delay_ms(100);
	LCD_clear_screen();
	_delay_ms(100);
	
	LCD_Write_string("Learn in depth");
		
    while (1) 
    {

	}
		
}


