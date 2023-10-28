/*
 * Timer.c
 *
 * Created: 10/27/2023 3:52:55 PM
 *  Author: Acer
 */ 

#include "Timer.h"

PTR_VoidFuncVoid_t callback_ovf;
PTR_VoidFuncVoid_t callback_cmp;

uint8_t ovf_counter = 0;
Stimer0_config_t* TIMER0_Config;

unsigned char Timer0_init(Stimer0_config_t* timer0_config)
{
	Erorr_check retval = E_nok;

	if(NULL_PTR == timer0_config)
	{
		retval = E_nok;
	}
	else
	{
		TIMER0_Config = timer0_config;

		if(normal == TIMER0_Config->mode1 || ctc==TIMER0_Config->mode1)
		{
			TCCR0 |= 0x08;
			retval = E_ok;
		}
		else
		{
			retval = E_nok;
		}

		if(No_clk_prescaler <= TIMER0_Config->prescaler || ext_clk_rising>=TIMER0_Config->prescaler)
		{
			TCCR0 |= 0x02;
			retval = E_ok;
		}
		else
		{
			retval = E_nok;
		}


		if(OCIE_Dis == TIMER0_Config->ocm_interrupt || OCIE_enable==TIMER0_Config->ocm_interrupt)
		{
			TIMSK |= (1<<1);
			retval = E_ok;
		}
		else
		{
			retval = E_nok;
		}



		if(TOIE0_Dis == TIMER0_Config->ovf_interrupt || TOIE0_enable ==TIMER0_Config->ovf_interrupt)
		{
			TIMSK |= (1<<0);
			retval = E_ok;
		}
		else
		{
			retval = E_nok;
		}


	}
	return retval;

}

unsigned char Timer0_stop(void)
{
	Erorr_check retval = E_ok;

	TCCR0 &= ~(1<<0);
	TCCR0 &= ~(1<<1);
	TCCR0 &= ~(1<<2);

	return retval;
}

unsigned char Timer0_Get_compare_val(unsigned char* ticks)
{
	Erorr_check retval = E_ok;
	*ticks = OCR0;
	return retval;
}

unsigned char Timer0_set_compare_val(unsigned char ticks)
{
	Erorr_check retval = E_ok;
	OCR0 = ticks;
	return retval;
}

unsigned char Timer0_Get_counter_val(unsigned char* ticks)
{
	Erorr_check retval = E_ok;
	*ticks = TCNT0;
	return retval;
}

unsigned char Timer0_set_counter_val(unsigned char ticks)
{
	Erorr_check retval = E_ok;
	TCNT0 = ticks;
	return retval;
}

unsigned char Timer0_Get_overflow_val(unsigned char* ticks)
{
	Erorr_check retval = E_ok;
	*ticks = ovf_counter;
	return retval;
}

unsigned char Timer0_set_overflow_val(unsigned char ticks)
{
	Erorr_check retval = E_ok;
	ovf_counter = ticks;
	return retval;

}

void Timer0_callback_ovf_interrupt(PTR_VoidFuncVoid_t callback)
{
	callback_ovf = callback;
	
}

void Timer0_callback_cmp_interrupt(PTR_VoidFuncVoid_t callback)
{
	callback_cmp = callback;
}


ISR(TIMER0_OVF_vect)
{
	ovf_counter++;
	callback_ovf();

}

ISR(TIMER0_COMP_vect)
{
	PORTA = 0x1;
	callback_cmp();
}
