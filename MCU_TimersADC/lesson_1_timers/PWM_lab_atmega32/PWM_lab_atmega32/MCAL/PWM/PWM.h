/*
 * PWM.h
 *
 * Created: 10/28/2023 12:35:05 AM
 *  Author: Acer
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "avr/io.h"
#include "utils.h"
#include "Std_Types.h"

typedef enum{
	Fast_pwm  ,
	phase_pwm 
}PWM_mode_t;

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
	normal,
	reserved ,
	inverting ,
	non_inverting 
}PWM_operation;


//structure
typedef struct
{
	PWM_mode_t	  Mode;
	timer_clk_t   prescaler;
	PWM_operation operation;
}
SPWM_config_t;

//APIs

void PWM_init(SPWM_config_t* pwm_config);
void PWM_Stop();
void PWM_Set_duty(uint8_t duty);



#endif /* PWM_H_ */