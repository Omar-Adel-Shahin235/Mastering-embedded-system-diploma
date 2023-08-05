/*
 ============================================================================
 Name        : LIFO.c
 Author      : omar adel shahin
 Version     :
 Copyright   : Your copyright notice
 Description : LIFO
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

//static memory allocation
unsigned int buffer_1[5];    //constrains : the type of variable is unsigned int


int main(void)
{
	int i , temp=0;
	LIFO_Buf_t Uart_lifo , I2C_lifo;


	LIFO_init(&Uart_lifo , buffer_1 , 5);

	//dynamic memory allocation
	unsigned int *buffer_2=(unsigned int*)malloc(5*sizeof(unsigned int));
	LIFO_init(&I2C_lifo , buffer_2 , 5);

	for(i=0 ; i<5 ; i++)s
	{
		if (LIFO_Add_item(&Uart_lifo , i) == LIFO_no_erorr )
		printf("\n Uart add item : %d",i);
	}

	for(i=0 ; i<5 ; i++)
		{
			if (LIFO_Get_item(&Uart_lifo , &temp) == LIFO_no_erorr )
			printf("\n Uart get item : %d",temp);
		}
	return EXIT_SUCCESS;
}
