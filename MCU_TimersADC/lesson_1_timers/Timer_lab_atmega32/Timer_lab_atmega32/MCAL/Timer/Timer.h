/*
 * Timer.h
 *
 * Created: 10/27/2023 3:52:41 PM
 *  Author: Acer
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "utils.h"
#include "Std_Types.h"

typedef enum
{
	normal ,
	ctc = 0x08,
}
Timer0_mode_t;


typedef enum
{
	No_clk_prescaler,
	No_prescaler,
	prescaler8,
	prescaler64,
	prescaler256,
	prescaler1024,
	ext_clk_falling,
	ext_clk_rising
}
timer_clk_t;


typedef enum
{
	OCIE_Dis,
	OCIE_enable = 0x02,
}
OCIE_mode_t;

typedef enum
{
	TOIE0_Dis,
	TOIE0_enable = 0x01,
}
TOIE0_mode_t;

typedef struct
{
	Timer0_mode_t mode1;
	timer_clk_t   prescaler;
	OCIE_mode_t  ocm_interrupt;
	TOIE0_mode_t ovf_interrupt;
}
Stimer0_config_t;

unsigned char Timer0_init(Stimer0_config_t* timer0);
unsigned char Timer0_stop(void);

unsigned char Timer0_Get_compare_val(unsigned char* ticks);
unsigned char Timer0_set_compare_val(unsigned char ticks);

unsigned char Timer0_Get_counter_val(unsigned char* ticks);
unsigned char Timer0_set_counter_val(unsigned char ticks);

unsigned char Timer0_Get_overflow_val(unsigned char* ticks);
unsigned char Timer0_set_overflow_val(unsigned char ticks);

void Timer0_callback_ovf_interrupt(PTR_VoidFuncVoid_t callback);
void Timer0_callback_cmp_interrupt(PTR_VoidFuncVoid_t callback);







#endif /* TIMER_H_ */