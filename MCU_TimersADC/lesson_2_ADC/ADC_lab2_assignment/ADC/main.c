/*
 * ADC.c
 *
 * Created: 11/2/2023 8:32:29 AM
 * Author : Acer
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "LCD.h"
#include "ADC.h"


int main(void)
{
	uint16_t data , volt , per_value , channel;
	uint8_t arr[16]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	uint8_t i;
	
	LCD_init();
	
	DDRA &= ~(1<<0);
	ADC_init(VREF_AVCC , ADC_prescaler_64);
	
	LCD_Location(0,0);
	LCD_Write_string("ADC:");
	LCD_Location(0,1);
	
    /* Replace with your application code */
    while (1) 
    {
		
		data = ADC_Read(ADC_CH_0);
		
		LCD_Write_command(0x80);
		LCD_Write_string("ADC:");
	
		LCD_Write_command(0x85);
		LCD_Write_Number((data/(float)10.24));
		
		LCD_Write_command(0xC0);
		for(i = 0 ; i<(data/64) ; i++)
		{
			LCD_Write_char(arr[i]);
		}
		
		_delay_ms(50);
		LCD_clear_screen();
    }
}

