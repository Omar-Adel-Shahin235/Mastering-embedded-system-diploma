
#include"pressure_sensor.h"

int Pval = 0;
int Psensor_pull = 100;

//difintion of pointer to function
void (*PS_state)();

void PS_init()
{
	//printf("pressure sensor init");
}



STAT_define(PS_Waiting)
{
	
	//STATE_name
	PS_state_id = PS_Waiting;
	
	//STATE_action
	Delay(Psensor_pull);
	
	//reading state
	PS_state = STATE(PS_READING);
	
}


STAT_define(PS_READING)
{
	//STATE_name
	PS_state_id = PS_READING;
	
	//STATE_action
	
	//Get pressure value
	Pval = getPressureVal();
	
	//Set pressure value
	set_pressure_val(Pval);
	
	//waiting state
	PS_state = STATE(PS_Waiting);
}