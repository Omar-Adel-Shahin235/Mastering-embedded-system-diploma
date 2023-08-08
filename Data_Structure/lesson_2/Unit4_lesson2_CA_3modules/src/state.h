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
void US_set_speed(int distance);
void DC_motor_speed(int speed);

#endif /* STATE_H_ */
