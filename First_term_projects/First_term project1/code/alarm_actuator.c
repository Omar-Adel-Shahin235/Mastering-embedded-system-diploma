

#include "alarm_actuator.h"

//difintion of pointer to function
void (*AA_state)();

void AA_init()
{
	//printf("init);
}

void start_alarm()
{
	AA_state = STATE(AA_alarm_on);
}

void stop_alarm()
{
	AA_state = STATE(AA_alarm_off);
}


STAT_define(AA_alarm_on)
{
	AA_state_id = AA_alarm_on;
	
	//state action
	
	// alarm on
	Set_Alarm_actuator(0);
	
}
STAT_define(AA_alarm_off)
{
	AA_state_id = AA_alarm_on;
	
	//state action
	
	// alarm off
	Set_Alarm_actuator(1);
}
