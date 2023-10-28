/*
 * WDT.c
 *
 * Created: 10/27/2023 10:55:30 AM
 * Author : Acer
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR      DDRC
#define LED_PORT     PORTC
#define LED_Pin      0

void Watchdog_disable(void)
{

WDTCR = (1<<WDTOE)|(1<<WDE);
WDTCR = 0x00;
}


void Watchdog_enable(void)
{
//2 SECOND

	WDTCR |=  (1 << WDP1) | (1 << WDP2) | (1 << WDE);
	WDTCR &= ~(1 << WDP0);
}

int main(void)
{
	LED_DDR |= (1<<LED_Pin);
    /* Replace with your application code */
	LED_PORT |= (1<<LED_Pin);
	_delay_ms(500);
    while (1) 
    {
	Watchdog_enable();
	LED_PORT ^= (1<<LED_Pin);
	_delay_ms(2000);
	Watchdog_disable();
    }
}

