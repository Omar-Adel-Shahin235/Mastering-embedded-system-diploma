/*
 * FIFO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "FIFO.h"

FIFO_statues FIFO_init(FIFO_buf_t* Fifo,element_type* buf , unsigned int length)
{
	if(buf == NULL)
		return FIFO_NULL;

	Fifo->base = buf;
	Fifo->head = buf;
	Fifo->tail = buf;
	Fifo->length = length;
	Fifo->count = 0;

	return FIFO_no_erorr;
}
FIFO_statues FIFO_Enqueue (FIFO_buf_t* FIFO , unsigned int item)
{
	//check for null
	if(!FIFO->base ||!FIFO->head ||!FIFO->tail)
		return FIFO_NULL;

	//check if fifo is full
	if(FIFO_is_full(FIFO) == FIFO_full)
		return FIFO_full;

	FIFO->count ++;
	*(FIFO->head) = item;

	//cicular
	if(FIFO->head == (FIFO->base + FIFO->length * sizeof(element_type)))
		FIFO->head = FIFO->base;
	else
		FIFO->head++;

	return FIFO_no_erorr;
}
FIFO_statues FIFO_Dequeue (FIFO_buf_t* FIFO , unsigned int* item)
{
	//check for null
		if(!FIFO->base ||!FIFO->head ||!FIFO->tail)
			return FIFO_NULL;

	//check if FIFO is empty
	if(FIFO->count == 0)
		return FIFO_empty;

	*item = *(FIFO->tail);
	FIFO->count --;

	FIFO->length = 5;

	if(FIFO->tail == (FIFO->base + FIFO->length * sizeof(element_type)))
			FIFO->tail = FIFO->base;
		else
			FIFO->tail++;

	return FIFO_no_erorr;

}

FIFO_statues FIFO_is_full(FIFO_buf_t* FIFO)
{
	//check for null
		if(!FIFO->base ||!FIFO->head ||!FIFO->tail)
			return FIFO_NULL;

		if(FIFO->count == FIFO->length)
			return FIFO_full;

		return FIFO_no_erorr;
}
void FIFO_print(FIFO_buf_t* FIFO)
{
	element_type* temp;
	int i;

	if(FIFO->count == 0)
		printf("FIFO is empty");
	else
	{
	temp = (FIFO->tail);
	printf("--FIFO print--");
	for(i=0 ; i<(FIFO->count) ; i++)
	{
		printf("\n%x",(*temp));
		temp++;
	}
	printf("\n----\n");
	}
}
