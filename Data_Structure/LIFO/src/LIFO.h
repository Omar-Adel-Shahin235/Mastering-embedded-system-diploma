/*
 * LIFO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omar
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef LIFO_H_
#define LIFO_H_

//type definitions

typedef struct
{
	unsigned int Length;
	unsigned int Count;
	unsigned int* Base;
	unsigned int* Head;
}LIFO_Buf_t;

typedef enum
{
	LIFO_no_erorr,
	LIFO_Full,
	LIFO_Empty,
	LIFO_NULL
}LIFO_statues;

//API
LIFO_statues LIFO_Add_item (LIFO_Buf_t* LIFO_buf , unsigned int item);
LIFO_statues LIFO_Get_item (LIFO_Buf_t* LIFO_buf , unsigned int* item);
LIFO_statues LIFO_init (LIFO_Buf_t* LIFO_buf , unsigned int* buf , unsigned int length);

#endif /* LIFO_H_ */
