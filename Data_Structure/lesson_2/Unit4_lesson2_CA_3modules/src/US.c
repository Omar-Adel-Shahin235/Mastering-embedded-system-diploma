/*
 * US.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "US.h"

//variables

int US_distance = 0;

//pointer to function

void (*US_state)();

void US_init()
{
	//init US driver
	printf("US_init \n");
}

int US_get_distance(int l , int r , int count);

STAT_define(US_busy)
{
	//state name
	US_state_id = US_busy;
	//state action
	US_distance = US_get_distance(45 , 55 , 1 );

	printf("\nUS_busy state: distance=%d",US_distance);
	US_set_speed(US_distance);
	US_state = STATE(US_busy);
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


