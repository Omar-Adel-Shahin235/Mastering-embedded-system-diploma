/*
 * FIFO.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Acer
 */


#ifndef FIFO_H_
#define FIFO_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define Dprintf(...)     {fflush(stdin); fflush(stdout); \
							printf(__VA_ARGS__); \
						  fflush(stdin); fflush(stdout);}

#define Name_size 50
typedef struct
{
	char fname[Name_size];
	char lname[Name_size];
	int roll;
	float GPA;
	int cid[10];
} Sstudent;

#define element_type Sstudent

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

//APIs

FIFO_statues FIFO_init(FIFO_buf_t* Fifo,element_type* buf , unsigned int length);
FIFO_statues FIFO_Enqueue (FIFO_buf_t* Fifo ,element_type* buf );
FIFO_statues FIFO_Dequeue (FIFO_buf_t* FIFO , element_type* buf);
FIFO_statues FIFO_is_full(FIFO_buf_t* FIFO);

void add_student_file(FIFO_buf_t* Fifo);
void add_student_manually(FIFO_buf_t* Fifo);
void find_by_roll(FIFO_buf_t* Fifo);
void find_by_first_name(FIFO_buf_t* Fifo);
void find_by_course(FIFO_buf_t* Fifo);
void total_students(FIFO_buf_t* Fifo);
void delete_student(FIFO_buf_t* Fifo);
void update_the_student_by_roll_number(FIFO_buf_t* Fifo);
void show_all_information(FIFO_buf_t* Fifo);
void print_data(element_type *data);

#endif /* FIFO_H_ */

