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

int US_get_distance(int l , int r , int count);

STAT_define(CA_Waiting)
{
	//state name
	CA_state_id = CA_Waiting;
	//state action
	CA_speed = 0;
	//state event
	//US_get_distance
	CA_distance = US_get_distance(45 , 55 , 1 );

	(CA_distance <= CA_threshold)?(CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
	printf("\nCA_waiting state: distance=%d  , speed=%d",CA_distance,CA_speed);
}

STAT_define(CA_Driving)
{
	//state name
		CA_state_id = CA_Driving;
		//state action
		CA_speed = 30;
		//state event
		//US_get_distance
		CA_distance = US_get_distance(45 , 55 , 1 );

		(CA_distance <= CA_threshold)?(CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
		printf("\nCA_Driving state: distance=%d  , speed=%d",CA_distance,CA_speed);
}


int US_get_distance(int l , int r , int count)
{
	int i;
	for(i=0 ; i<count ; i++)
	{
		int rand_num = (rand()%(r-l+1))+45;
		return rand_num;
	}
}


