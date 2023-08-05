/*
 * LIFO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: omar
 */
#include "LIFO.h"

LIFO_statues LIFO_Add_item (LIFO_Buf_t* LIFO_buf , unsigned int item)
{
	//check if LIFO is valid
	if(!LIFO_buf->Base || !LIFO_buf->Head)
		return LIFO_NULL;

	//check if LIFO is full
	if(LIFO_buf->Count == LIFO_buf->Length)
		return LIFO_Full;

	*(LIFO_buf->Head) = item;
	LIFO_buf->Head++;
	LIFO_buf->Count++;

	return LIFO_no_erorr;
}

LIFO_statues LIFO_Get_item (LIFO_Buf_t* LIFO_buf , unsigned int* item)
{
	//check if LIFO is valid
		if(!LIFO_buf->Base || !LIFO_buf->Head)
			return LIFO_NULL;

	//check if embty
		if(LIFO_buf->Count == 0)
			return LIFO_Empty;

		LIFO_buf->Head--;
		*item =  *(LIFO_buf->Head);
		LIFO_buf->Count--;

		return LIFO_no_erorr;
}

LIFO_statues LIFO_init (LIFO_Buf_t* LIFO_buf , unsigned int* buf , unsigned int length)
{
	if(buf == NULL)
		return LIFO_NULL;

	LIFO_buf->Base = buf;
	LIFO_buf->Head = buf;
	LIFO_buf->Length = length;
	LIFO_buf->Count = 0;

	return LIFO_no_erorr;
}

