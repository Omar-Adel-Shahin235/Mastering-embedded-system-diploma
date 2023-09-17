/*
 * Unit7_lesson2_section.c
 *
 * Created: 9/8/2023 12:25:29 AM
 * Author : Acer
 */ 

//#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

#include "UART.h"
#include "LCD.h"

char* x[25];

int main(void)
{
	LCD_init();
	UART_Init();
	
	LCD_clear_screen();
	_delay_ms(100);
	
	LCD_Write_string("UART test:");
	
	UART_String_Transmit("Omar");

		
	LCD_Location(2,0);	
    while (1) 
    {
		
		UART_String_Receive(x);
		LCD_Write_string(x);
		
	}
		
}

