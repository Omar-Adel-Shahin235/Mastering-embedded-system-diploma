

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"
#include "driver.h"

enum {
    AA_alarm_off, 
    AA_alarm_on,
}AA_state_id;

STAT_define(AA_alarm_off);
STAT_define(AA_alarm_on);

void AA_init();

extern void (*AA_state)();

#endif /* ALARM_ACTUATOR */

