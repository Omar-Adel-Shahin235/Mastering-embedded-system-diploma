/*
 * SPI_Slave.c
 *
 * Created: 9/22/2023 4:15:46 PM
 * Author : Acer
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

#define SS  4
#define MOSI  5
#define MISO  6
#define CLK  7


void Slave_init(void)
{
	//set MISO as output
	DDRB |=  (1<<MISO);
	
	//set MOSI  , SS and clk as input
	DDRB &= ~( (1<<MOSI) | (1<<SS) | (1<<CLK));
	
	//enable SPI and master and Fclk/16
	SPCR |= (1<<SPE);
}

uint8_t Slave_Receive(uint8_t Data)
{
	SPDR = Data;
	
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

int main(void)
{
	Slave_init();
	
	
	//Set 7-segment pins as output
	DDRA = 0xFF;
	
	uint8_t data;
	
	for(data =255 ; data>=0 ; data--)
	{
		PORTA = Slave_Receive(data);
	}

}