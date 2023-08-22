
#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include"state.h"
#include"driver.h"

enum {
    AM_alarm_off, 
    AM_alarm_on,
    AM_Waiting 
}AM_state_id;

STAT_define(AM_Waiting);
STAT_define(AM_alarm_off);
STAT_define(AM_alarm_on);

void AM_init();

extern void (*AM_state)();

#endif /* ALARM_MONITOR */