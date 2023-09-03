/*
 * Unit6_lesson4_Assignment.c
 *
 * Created: 9/3/2023 5:52:22 AM
 * Author : Acer
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

#define Base 0x20
//Registers

// I/O PORTS
#define PORTD *((volatile unsigned char*)Base+0x12)
#define DDRD  *((volatile unsigned char*)Base+0x11)
#define DDRB  *((volatile unsigned char*)Base+0x17)

//External interrupt registers
#define MCUCR  *((volatile unsigned char*)Base+0x35)
#define GICR  *((volatile unsigned char*)Base+0x3B)
#define SREG  *((volatile unsigned char*)Base+0x3F)

ISR (INT0_vect)
{
	PORTD |=(1<<7);
	_delay_ms(1000);
	PORTD &=~(1<<7);
	_delay_ms(1000);
}

ISR (INT1_vect)
{
	PORTD |=(1<<6);
	_delay_ms(1000);
	PORTD &=~(1<<6);
	_delay_ms(1000);
}

ISR (INT2_vect)
{
	PORTD |=(1<<5);
	_delay_ms(1000);
	PORTD &=~(1<<5);
	_delay_ms(1000);
}

int main(void)
{
	//set pin7 , pin6 , pin5 in PORTD as output
	DDRD|=(1<<7) | (1<<6) | (1<<5);
	
	//set pin2 , pin3 in PORTD as input
	DDRD&=~(1<<2); DDRD&=~(1<<3);
	
	//set pin2 in PORTB as input
	DDRB&=~(1<<2);
	
	//Enable global interrupt
	SREG|=(1<<7);
	
	//Enable external interrupt pins (INT0 , INT1 , INT2)
	GICR|=(1<<7) | (1<<6) | (1<<5);
	
	//INT0 - any logical change
	MCUCR|=(1<<0);
	
	//INT1 - rising edge
	MCUCR|=(1<<2) | (1<<3);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}
