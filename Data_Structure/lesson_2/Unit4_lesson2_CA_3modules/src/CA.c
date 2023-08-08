/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "CA.h"

//variables

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


//pointer to function

void (*CA_state)();

void US_set_speed(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold)?(CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
	printf("US-----distance=%d------->CA\n",CA_distance);
}

STAT_define(CA_Waiting)
{
	//state name
	CA_state_id = CA_Waiting;
	printf("CA_waiting state: distance=%d  , speed=%d\n",CA_distance,CA_speed);
	//state action
	CA_speed = 0;
	DC_motor_speed(CA_speed);

}

STAT_define(CA_Driving)
{
	//state name
		CA_state_id = CA_Driving;
		printf("CA_Driving state: distance=%d  , speed=%d\n",CA_distance,CA_speed);
		//state action
		CA_speed = 30;
		DC_motor_speed(CA_speed);

}

