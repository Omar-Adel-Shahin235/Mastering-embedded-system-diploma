
#include "driver.h"
#include "pressure_sensor.h"
#include "alarm_monitor.h"
#include "alarm_actuator.h"

void setup()
{
	//init
	GPIO_INITIALIZATION();
	PS_init();
	AA_init();
	
	//States
	PS_state = STATE(PS_READING);
	AM_state = STATE(AM_alarm_off);
	AA_state = STATE(AA_alarm_off);
}

int threshold = 20;

int main (){
	
	setup();
	
	
	while (1)
	{
		//Implement your Design 
		PS_state();
		AM_state();
		AA_state();
	}

}

void set_pressure_val(int Pval)
{
	if(Pval > threshold)
		High_pressure_detected();
}

