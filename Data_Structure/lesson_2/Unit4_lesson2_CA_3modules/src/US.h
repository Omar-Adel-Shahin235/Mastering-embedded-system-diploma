/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef US_H_
#define US_H_
#include "state.h"

enum{
	US_busy
}US_state_id;

//declare state functios CA
STAT_define(US_busy);

void US_init();

extern void (*US_state)();

#endif /* CA_H_ */
