/*
 * FIFO.c
 *
 *  Created on: Aug 24, 2023
 *      Author: omar adel
 */

#include "FIFO.h"


/*
=================================================================
Fifo initialization
=================================================================
*/
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


/*
=================================================================
Fifo Enqueue
=================================================================
*/
FIFO_statues FIFO_Enqueue (FIFO_buf_t* FIFO , Sstudent* buf)
{
	//check for null
	if(!FIFO->base ||!FIFO->head ||!FIFO->tail)
		return FIFO_NULL;

	//check if fifo is full
	if(FIFO_is_full(FIFO) == FIFO_full)
		return FIFO_full;

	FIFO->count ++;
	*(FIFO->head) = *(buf);  //copy content

	//cicular
	if(FIFO->head == (FIFO->base + FIFO->length * sizeof(element_type)))
		FIFO->head = FIFO->base;
	else
		FIFO->head++;

	return FIFO_no_erorr;
}

/*
=================================================================
Fifo Dequeue
=================================================================
*/
FIFO_statues FIFO_Dequeue (FIFO_buf_t* FIFO , element_type * item)
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


/*
=================================================================
check FIFO is full
=================================================================
*/
FIFO_statues FIFO_is_full(FIFO_buf_t* FIFO)
{
	//check for null
		if(!FIFO->base ||!FIFO->head ||!FIFO->tail)
			return FIFO_NULL;

		if(FIFO->count == FIFO->length)
			return FIFO_full;

		return FIFO_no_erorr;
}


/*
=================================================================
Add student by text file
=================================================================
*/
void add_student_file(FIFO_buf_t* Fifo)
{
	FILE  *txt_file;
	element_type student , *temp=Fifo->tail;
	int i;

	txt_file = fopen("Student_Data.txt","r");

	if(txt_file == NULL)
	{
		Dprintf("\n faild to read the text file");
        return;
	}

	while(!feof(txt_file))
	{

	fscanf(txt_file,"%d",&student.roll);

	//check if roll number is exist
	for(i=0 ; i< Fifo->count ; i++)
		{
			if(temp->roll == student.roll)
			{
				Dprintf("\nyou entered an exist roll number");
				fscanf(txt_file, "%*[^\n]");
				break;
			}
			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}
		
		temp=Fifo->tail;
		
	if( i == Fifo->count)
	{
		fscanf(txt_file, "%s", student.fname);
		fscanf(txt_file, "%s", student.lname);
		fscanf(txt_file, "%f", &student.GPA);
		//for courses
		for(i=0;i<10 ; i++)
		{
		fscanf(txt_file, "%d",&student.cid[i]);
		}

		if(FIFO_Enqueue (Fifo , &student) == FIFO_no_erorr)
		{Dprintf("\n the student data has been added");}
		else
		{Dprintf("\n faild to add new student");}
	}
	else
		continue;
	
	}

	fclose(txt_file);

}


/*
=================================================================
Add student manually
=================================================================
*/
void add_student_manually(FIFO_buf_t* Fifo)
{
	element_type student , *temp=Fifo->tail;
	int i;

	Dprintf("\n======Enter student data======");

	//data entry
	Dprintf("\nEnter roll number: ");
	scanf("%d",&student.roll);

	//check if roll number is exist
	for(i=0 ; i< Fifo->count ; i++)
		{
			if(temp->roll == student.roll)
			{
				Dprintf("you entered an exist roll number");
				return;
			}
			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}

	Dprintf("\nEnter first name: ");
	scanf("%s",student.fname);

	Dprintf("\nEnter last name: ");
	scanf("%s",student.lname);

	Dprintf("\nEnter GPA: ");
	scanf("%f",&student.GPA);

	Dprintf("\nEnter courses ID: ");
	for(i=0 ; i<10 ; i++)
	{
		Dprintf("\nenter course number %d: ",(i+1));
		scanf("%d",&student.cid[i]);
	}

	if(FIFO_Enqueue (Fifo , &student) == FIFO_no_erorr)
		{Dprintf("\n the student data has been added");}
	else
		{Dprintf("\n faild to add new student");}
}


/*
=================================================================
Find student data by roll number of student
=================================================================
*/
void find_by_roll(FIFO_buf_t* Fifo)
{
	if(Fifo->count ==0)
	{
		Dprintf("\nthe data is empty");
		return;
	}

		element_type *temp = Fifo->tail;
		int roll_num , i;


		Dprintf("\n enter the roll number for searching:");
		scanf("%d", &roll_num);

		for(i=0 ; i< Fifo->count ; i++)
		{
			if(temp->roll == roll_num)
				break;

			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}

		if(i == Fifo->count)
			{Dprintf("\n you entered a non exist roll number");}
		else
			{Dprintf("\n======= student data for roll number %d ========",roll_num);}
			print_data(temp);


}


/*
=================================================================
Find student data by searching of the first name
=================================================================
*/
void find_by_first_name(FIFO_buf_t* Fifo)
{
	//chick if empty
	if(Fifo->count == 0)
		{
			Dprintf("\nthe data is empty");
			return;
		}

	element_type *temp = Fifo->tail;
	char f_name[Name_size];
	int i;

		Dprintf("\n enter the first student name for searching:");
		scanf("%s", f_name);

		//searching...
		for(i=0 ; i< Fifo->count ; i++)
		{
			if(strcmp(temp->fname,f_name)==0)
				break;

			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}

		if(i == Fifo->count)
			{Dprintf("\n you entered a non exist first name");}
		else
			{Dprintf("\n======= student data for %s ========",f_name);}
			print_data(temp);
}


/*
=================================================================
Find students data by course ID
=================================================================
*/
void find_by_course(FIFO_buf_t* Fifo)
{
	if(Fifo->count == 0)
		{
			Dprintf("\nthe data is empty");
			return;
		}

	element_type *temp_data = Fifo->tail , *temp_num = Fifo->tail;
	float course_id;
	int i,j,student_num=0;

	Dprintf("\n enter the course id for searching:");
	scanf("%f", &course_id);

	for(i=0 ; i< Fifo->count ; i++)
	{
		for(j=0 ; j<10 ; j++)
		{
			if(temp_num->cid[j] == course_id)
			student_num ++;
		}

		if( temp_num == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp_num = Fifo->base;

			else
				temp_num++;
	}

	Dprintf("\n the total number of students that have this course --> %d",student_num);

	if(student_num !=0)
	{
		for(i=0 ; i< Fifo->count ; i++)
		{
			for(j=0 ; j<10 ; j++)
			{
				if(temp_data->cid[j] == course_id)
				print_data(temp_data);
			}

			if( temp_data == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
				temp_data = Fifo->base;

				else
					temp_data++;
		}
	}

	else
	{
		Dprintf("there is no student is this cource id");
	}


}


/*
=================================================================
Find number of total students
=================================================================
*/
void total_students(FIFO_buf_t* Fifo)
{
	Dprintf("\ntotal number of students == %d",Fifo->count);
}


/*
=================================================================
Delete student data
=================================================================
*/
void delete_student(FIFO_buf_t* Fifo)
{
	if(Fifo->count == 0)
		{
			Dprintf("\nthe data is empty");
			return;
		}

	element_type *temp = Fifo->tail;
	int roll , i;

	Dprintf("\n enter the roll number of student for deleting:");
		scanf("%d", &roll);

	//check the roll number

	for(i=0 ; i< Fifo->count ; i++)
		{
			if(temp->roll == roll)
				break;

			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}

	if(i == (Fifo->count) )
		{Dprintf("\nyou eneterd a non exist roll number for deleting");}
	else
	{
		if(FIFO_Dequeue(Fifo ,temp) == FIFO_no_erorr)
			{Dprintf("\nthe student has been deleted");}
		else
			{Dprintf("\n faild to delete the student");}
	}

}


/*
=================================================================
Update student data
=================================================================
*/
void update_the_student_by_roll_number(FIFO_buf_t* Fifo)
{
	if(Fifo->count == 0)
		{
			Dprintf("\nthe data is empty");
			return;
		}

	element_type *temp = Fifo->tail;
	int roll , choise , i;

	Dprintf("\n enter the roll number of student for updating:");
		scanf("%d", &roll);

	//check the roll number

	for(i=0 ; i< Fifo->count ; i++)
		{
			if(temp->roll == roll)
				break;

			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}

	if(i == Fifo->count )
		{Dprintf("\nyou eneterd a non exist roll number for updating");}
	else
	{
		Dprintf("\n=====Enter what is the type of data want to update=====");
		Dprintf("\n (1)updating the first name \n (2)updating the last name \n (3)updating the GPA \n (4)updating course id : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1:
				Dprintf("\nEnter the new first name:");
				scanf("%s",temp->fname);
				break;

			case 2:
				Dprintf("\nEnter the new last name:");
				scanf("%s",temp->lname);
				break;

			case 3:
				Dprintf("\nEnter the new GPA:");
				scanf("%f",&temp->GPA);
				break;

			case 4:
				Dprintf("\n====Enter the new cources id====");
				for(i=0 ; i<10 ; i++)
        	{
				Dprintf("\nenter course number %d : ",(i+1));
				scanf("%d",&temp->cid[i]);
	        }
				break;
			default:
				Dprintf("You entered a wrong choise");

		}
	}
	Dprintf("\n The student data has been updated");
}

/*
=================================================================
Show all information of all students
=================================================================
*/
void show_all_information(FIFO_buf_t* Fifo)
{
	if(Fifo->count == 0)
		{
			Dprintf("\nthe data is empty");
			return;
		}

	element_type *temp = Fifo->tail;
	int i;

	for(i=0 ; i< Fifo->count ; i++)
		{
			print_data(temp);

			if( temp == (Fifo->base + Fifo->length * sizeof(element_type)))    //alert here
			temp = Fifo->base;

			else
				temp++;
		}
}

/*
=================================================================
print the student data by pointer to structure
=================================================================
*/
void print_data(element_type *data)
{
		int i;
		Dprintf("\n=====================");
		Dprintf("\nRoll number : %d" , data->roll);
		Dprintf("\nFirst Name:%s",data->fname);
		Dprintf("\nLast Name:%s",data->lname);
		Dprintf("\nGPA:%0.1f",data->GPA);
		for (i=0 ; i<10 ; i++)
		{
			Dprintf("\nCourse number (%d) --> ID=%d",(i+1),data->cid[i]);
		}

		Dprintf("\n=====================");
}

