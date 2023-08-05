/*
 ============================================================================
 Name        : FIFO.c
 Author      : omar adel shahin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void) {

	FIFO_buf_t FIFO_Uart;
	element_type i , temp;
	if(FIFO_init(&FIFO_Uart,Uart_buffer,5) == FIFO_no_erorr)
		printf("Fifo init done");


	for(i=0 ; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_Enqueue(&FIFO_Uart,i) == FIFO_no_erorr)
			printf("Fifo enqueue done \n");
		else
			printf("Fifo enqueue failed \n");
	}

		FIFO_print(&FIFO_Uart);
		if( FIFO_Dequeue(&FIFO_Uart,&temp) == FIFO_no_erorr)
			printf("FIFO Dequeue (%x) \n",temp);
		if( FIFO_Dequeue(&FIFO_Uart,&temp) == FIFO_no_erorr)
			printf("FIFO Dequeue (%x) \n",temp);
		FIFO_print(&FIFO_Uart);

	return EXIT_SUCCESS;
}

