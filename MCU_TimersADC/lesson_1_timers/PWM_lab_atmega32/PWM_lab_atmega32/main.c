/*
 * Timer_lab_atmega32.c
 *
 * Created: 10/27/2023 3:47:10 PM
 * Author : Acer
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "PWM.h"





int main(void)
{
	int i;
	
	SPWM_config_t PWM_config = {Fast_pwm , No_prescaler, non_inverting};
    DDRB |= (1<<3);  //dc motor control
	
	PWM_init(&PWM_config);
	
    while (1) 
    {
		for(i=0 ; i<= 100 ; i++)
		{
			PWM_Set_duty(i);
			_delay_ms(5);
		}
		
		for(i=100 ; i<= 0 ; i--)
		{
			PWM_Set_duty(i);
			_delay_ms(5);
		}
    }
}

