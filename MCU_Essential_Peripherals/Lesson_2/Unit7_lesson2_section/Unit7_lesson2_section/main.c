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
	Key_pad_init();
	
	_delay_ms(10);
	LCD_Custom_charachters();

	
	char pressed_key;
    while (1) 
    {
		pressed_key = Key_pad_get_char();
		
		switch(pressed_key)
		{
			case '!':
			LCD_clear_screen();
			break;
			
			case 'N':
			break;
			
			default:
			LCD_Write_char(pressed_key);
		}		
    }
}

