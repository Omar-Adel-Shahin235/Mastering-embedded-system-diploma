


#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"
#include "driver.h"

enum{
	PS_Waiting,
	PS_READING
}PS_state_id;

STAT_define(PS_Waiting);
STAT_define(PS_READING);

void PS_init();

extern void (*PS_state)();

#endif /* PRESSURE_SENSOR */