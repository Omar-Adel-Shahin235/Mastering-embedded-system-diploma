/*
 * DC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "DC.h"

//variables

int DC_speed = 0;

//pointer to function

void (*DC_state)();

void DC_init()
{
	printf("DC_init\n");
}

void DC_motor_speed(int speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("CA-----speed=%d------->DC\n",DC_speed);
}

STAT_define(DC_idle)
{
	//state name
	DC_state_id = DC_idle;
	//state action


	printf("\nDC_idle state:speed=%d",DC_speed);
}

STAT_define(DC_busy)
{
	//state name
		DC_state_id = DC_busy;

		DC_state = STATE(DC_idle);
		printf("\nDC_busy state:speed=%d",DC_speed);
}


