/*
 * SPI_master.c
 *
 * Created: 9/22/2023 2:54:31 PM
 * Author : Acer
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

#define SS  4
#define MOSI  5
//#define MISO  6
#define CLK  7


void Master_init(void)
{
	//set pins as output
	DDRB |= ( (1<<SS) | (1<<MOSI) | (1<<CLK) );
	
	//enable SPI and master and Fclk/16
	SPCR |= ( (1<<SPE) | (1<<MSTR) | (1<<SPR0) );
}


void Master_transmit(uint8_t Data)
{
	SPDR = Data;
	
	while(!(SPSR & (1<<SPIF)));
}

void execute(uint8_t command,uint8_t Data)
{
	//Reset Slave select pin
	PORTB &= ~(1<<SS);
	
	//send the command and data
	Master_transmit(command);
	Master_transmit(Data);

	//Set Slave select pin
	PORTB |= (1<<SS);
}


int main(void)
{
	uint8_t index,count=0;
	Master_init();
	//commands to initialize
	execute(0x09, 0xFF);
	execute(0x0A, 0xFF);
	execute(0x0B, 0xF7);
	execute(0x0C, 0x01);
	
	while(1)
	{
		for(index =1 ; index<9 ; index++)
		{
			execute(index,count);
			count++;
		}
		_delay_ms(1000);
	}
}



