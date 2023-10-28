/*
 * PWM.c
 *
 * Created: 10/28/2023 12:35:32 AM
 *  Author: Acer
 */ 

#include "PWM.h"
SPWM_config_t* config;

uint8_t timer_val = 0;

void PWM_init(SPWM_config_t* pwm_config)
{
	
	config = pwm_config;
	TCNT0 = (config->Mode) | (config->prescaler) | (config->operation);	
	
	if(config->Mode == Fast_pwm)
		timer_val |= ((1<<WGM00) | (1<<WGM01));  //
		else
		{
			timer_val |= (1<<WGM01);
			timer_val &= ~(1<<WGM00);
		}
		
	timer_val |= (config->prescaler);
	
	if(config->operation == non_inverting)
	{
		timer_val &= ~(1<<COM00);
		timer_val |= (1<<COM01);
	}
	else if(config->operation == inverting)
	{
		timer_val |= (1<<COM00) | (1<<COM01);
	}
	else
	{
		timer_val &= ~((1<<COM00) | (1<<COM01));
	}
	
	TCCR0 = timer_val;	
	
}
void PWM_Stop()
{
	TCNT0 = 0x00;
}
void PWM_Set_duty(uint8_t duty)
{
		if(config->operation == non_inverting)
		{
			OCR0 = (255/100)*duty;
		}
		else
		{
			OCR0 = 255 - ((255/100)*duty);
		}
	
}