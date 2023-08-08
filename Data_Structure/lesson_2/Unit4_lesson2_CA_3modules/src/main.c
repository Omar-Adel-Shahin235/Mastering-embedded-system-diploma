/*
 ============================================================================
 Name        : Unit4_lesson2_CA_v1.c
 Author      : omar adel shahin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_sensor DC_driver
	//init blocks
	US_init();
	DC_init();
	//init states pointer for each block
	CA_state = STATE(CA_Waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main(void)
{
	volatile int d;
	setup();

	while(10)
	{
		US_state();
		CA_state();
		DC_state();

		for(d=0 ; d<10000 ; d++);
	}

	return EXIT_SUCCESS;
}
