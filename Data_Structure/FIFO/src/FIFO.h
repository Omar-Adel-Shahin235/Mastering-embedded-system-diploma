/*
 * FIFO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//User configuration

//select element type
#define element_type uint8_t

//select width
#define width 5

element_type Uart_buffer[width];

typedef struct
{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buf_t;

typedef enum
{
	FIFO_no_erorr,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_statues;

//AIPs

FIFO_statues FIFO_init(FIFO_buf_t* Fifo,element_type* buf , unsigned int length);
FIFO_statues FIFO_Enqueue (FIFO_buf_t* FIFO , unsigned int item);
FIFO_statues FIFO_Dequeue (FIFO_buf_t* FIFO , unsigned int* item);
FIFO_statues FIFO_is_full(FIFO_buf_t* FIFO);
void FIFO_print(FIFO_buf_t* FIFO);



#endif /* FIFO_H_ */
