/*
 ============================================================================
 Name        : main.c
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

	FIFO_buf_t FIFO_data;
	element_type students[50];

	if(FIFO_init(&FIFO_data,students,50) == FIFO_no_erorr)
		printf("Fifo init done");

	int choose;

	while(1)
	{
		Dprintf("\n =================");
		Dprintf("\nchoose any task want to implement");
		Dprintf("\n 1- Add Student Manually");
		Dprintf("\n 2- Add Students From Text File");
		Dprintf("\n 3- Find Student by Roll Number");
		Dprintf("\n 4- Find Student by First Name");
		Dprintf("\n 5- Find Students of Course by ID");
		Dprintf("\n 6- Find The Total Students Number");
		Dprintf("\n 7- Delete Student Details by Roll Number");
		Dprintf("\n 8- Update Student Details by Roll Number");
		Dprintf("\n 9- Show All Information");
		Dprintf("\n 10-Exit\n");
		Dprintf("\n========choose task : ");
		scanf("%d",&choose);

		Dprintf("\n\n=============================");

		switch(choose)
		{
			case 1:
			add_student_manually(&FIFO_data);
			break;

		case 2:
			add_student_file(&FIFO_data);
			break;

		case 3:
			find_by_roll(&FIFO_data);
			break;

		case 4:
			find_by_first_name(&FIFO_data);
			break;

		case 5:
			find_by_course(&FIFO_data);
			break;

		case 6:
			total_students(&FIFO_data);
			break;

		case 7:
			delete_student(&FIFO_data);
			break;

		case 8:
			update_the_student_by_roll_number(&FIFO_data);
			break;

		case 9:
			show_all_information(&FIFO_data);
			break;

		case 10:
			exit(0);
			break;

		default:
			Dprintf("\n\nYou entered a wrong choise , please try again");
			break;
		}
	}


	return EXIT_SUCCESS;
}


