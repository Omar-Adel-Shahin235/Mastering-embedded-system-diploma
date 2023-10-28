/*
 * Timer_lab_atmega32.c
 *
 * Created: 10/27/2023 3:47:10 PM
 * Author : Acer
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>

#include "Timer.h"

extern uint8_t ovf_counter;

void timer_ovf_callback()
{
	PORTA = ~PORTA;
}

int main(void)
{
    DDRA = 0xFF;
    Timer0_callback_cmp_interrupt(timer_ovf_callback);

	sei(); //ENABLES GLOBAL INTERRUPT

    Stimer0_config_t config = {ctc , prescaler8 ,  OCIE_enable , TOIE0_Dis};
    Timer0_set_compare_val(0xF0);
    Timer0_init(&config);
	
	while(!get_bit(TIFR,OCF0));
    while (1) 
    {
    }
}

