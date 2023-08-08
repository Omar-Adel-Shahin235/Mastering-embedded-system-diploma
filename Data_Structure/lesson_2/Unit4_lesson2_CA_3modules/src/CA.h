/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

enum{
	CA_Waiting,
	CA_Driving
}CA_state_id;

//declare state functios CA
STAT_define(CA_Waiting);
STAT_define(CA_Driving);

extern void (*CA_state)();

#endif /* CA_H_ */
