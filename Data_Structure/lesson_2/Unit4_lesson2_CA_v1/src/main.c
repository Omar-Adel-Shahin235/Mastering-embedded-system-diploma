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

void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_sensor DC_driver
	//init blocks
	//init states pointer for each block
	CA_state = STATE(CA_Waiting);
}

int main(void)
{
	volatile d;
	setup();

	while(10)
	{
		CA_state();
		for(d=0 ; d<10000 ; d++);
	}

	return EXIT_SUCCESS;
}
