
#include "alarm_monitor.h"


int alarm_period = 60;


//difintion of pointer to function
void (*AM_state)();

void AM_init()
{
	//printf("init);
}


void High_pressure_detected()
{
	AM_state = STATE(AM_alarm_on);
}


STAT_define(AM_alarm_on)
{
	//state name
	AM_state_id = AM_alarm_on;
	
	//state action
	
	//set alarm on
	start_alarm();
	
	//state waiting
	AM_state = STATE(AM_Waiting);
}

STAT_define(AM_Waiting)
{
	//STATE name
	AM_state_id = AM_Waiting;
	
	//STATE action
	Delay(alarm_period);
	
	//state off
	AM_state = STATE(AM_alarm_off);
}

STAT_define(AM_alarm_off)
{
	//STATE name
	AM_state_id = AM_alarm_off;
	
	//stop alarm
	stop_alarm();
	
	//state off
	AM_state = STATE(AM_alarm_off);
	
}
