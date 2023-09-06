/*
 * Unit7_lesson1_section.c
 *
 * Created: 9/5/2023 8:53:01 PM
 * Author : Acer
 */ 

//#include <avr/io.h>
#include "Memory_map.h"
#include "Utils.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main(void)
{
	//set PORTC direction to output
	DDRC = 0xFF;
	
	//set PORTB direction to output
	DDRB = 0xFF;
	
	//set PORTD pins 0,1 and 2 direction to input
	DDRD &=~(0b111);
	
	//Variable definition
	unsigned char i,j,count;
	volatile unsigned char press=0;
	   
    while (1) 
    {
		//if button 0 in portD is pressed , then start the Seven-segment counter
		if(READ_BIT(PIND,0) == 1)
		{
			
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					for(count=0 ; count<10 ; count++)
					{
						//Operate the left seven segment and stop the right one
						PORTC = (0b1011) | (i<<4);
						_delay_ms(10);
					
					//Operate the right seven segment and stop the left one
						PORTC = (0b0111) | (j<<4);
						_delay_ms(10);
					}
				}	
			}
			//Turn off the right seven segment 
			CLR_BIT(PORTC,2);
		}
		
		_delay_ms(10);
		
		//if button 1 in portD is pressed then turn on the specific LED  
		if(READ_BIT(PIND,1) == 1)
		{
			//if button is pressed 8 times , then reset all the LEDS
			if(press == 8)
			{
				PORTB = 0;
				press =0;
			}
			else
			{
				SET_BIT(PORTB,press);
				press++;
			}
			while(READ_BIT(PIND,1) == 1); //single pressing
		}
		
		
    }
}

