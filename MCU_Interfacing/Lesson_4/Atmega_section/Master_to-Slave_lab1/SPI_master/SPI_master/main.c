/*
 * SPI_master.c
 *
 * Created: 9/22/2023 2:54:31 PM
 * Author : Acer
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

#define SS  4
#define MOSI  5
#define MISO  6
#define CLK  7


void Master_init(void)
{
	//set pins as output
	DDRB |= ( (1<<SS) | (1<<MOSI) | (1<<CLK) );
	
	//Set MISO pin as input
	DDRB &= ~(1<<MISO);
	
	//enable SPI and master and Fclk/16
	SPCR |= ( (1<<SPE) | (1<<MSTR) | (1<<SPR0) );
}

uint8_t Master_transmit(uint8_t Data)
{
	SPDR = Data;
	
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

int main(void)
{
	Master_init();
	
	
	//Set 7-segment pins as putput
	DDRA = 0xFF;
	
	uint8_t data;
	
	for(data =0 ; data<=255 ; data++)
	{
		_delay_ms(1000);
		PORTA = Master_transmit(data);
	}

}

