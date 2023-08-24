/*
 * state.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

//automatic state function generated
#define STAT_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

//states connection
void set_pressure_val(int Pval);
void High_pressure_detected();
void start_alarm();
void stop_alarm();

#endif /* STATE_H_ */
