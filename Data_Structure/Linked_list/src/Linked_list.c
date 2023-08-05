/*
 ============================================================================
 Name        : Linked_list.c
 Author      : omar adel shahin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Dprintf(...)     {fflush(stdin); fflush(stdout); \
							printf(__VA_ARGS__); \
						  fflush(stdin); fflush(stdout);}


//effictive data
struct SData
{
	int ID;
	char Name[40];
	float height;

};

//linked list
struct Sstudents
{
	struct SData student;
	struct Sstudents* P_next_Student;
};
struct Sstudents* P_first_student = NULL;



void Add_Student()
{
	struct Sstudents* P_new_student;
	struct Sstudents* P_last_student;

	//check if empty
	if(P_first_student == NULL)
	{
		P_new_student = (struct Sstudents*)malloc(sizeof(struct Sstudents));

		P_first_student = P_new_student;
    }
	else
	{
		P_last_student = P_first_student;
				while(P_last_student->P_next_Student!=NULL)
					P_last_student= P_last_student->P_next_Student;

		P_new_student = (struct Sstudents*)malloc(sizeof(struct Sstudents));

		P_last_student->P_next_Student = P_new_student;
    }

			//fill data
			Dprintf("\n Enter the ID:");
			scanf("%d" , &(P_new_student->student.ID));

			Dprintf("\n Enter name :");
			gets(P_new_student->student.Name);

			Dprintf("\n Enter the Height:");
			scanf("%f" , &(P_new_student->student.height));

			//set next pointer of new student to null
			P_new_student->P_next_Student = NULL;
}


int Remove_Student()
{
	int id;
	Dprintf("\nenter the selected student ID to remove:");
	scanf("%d",&id);

	//check in not empty
	if(P_first_student != NULL)
	{
	struct Sstudents* P_selected_student = P_first_student;
	struct Sstudents* P_previous_student = NULL;

	while(P_selected_student != NULL)
	{
		if(P_selected_student->student.ID == id)
		{
			if(P_previous_student != NULL)
			{
				P_previous_student->P_next_Student = P_selected_student->P_next_Student;
			}else
			{
				P_first_student =P_selected_student->P_next_Student;
			}
			free(P_selected_student);
			return 1;
		}
		P_previous_student = P_selected_student;
		P_selected_student = P_selected_student->P_next_Student;
	}
	Dprintf("\ncan't find student id");
	return 0;
	}
	Dprintf("\nthe liked list is empty");
}


void view_students()
{
	struct Sstudents* P_current_student = P_first_student;
	int count=0;

	if(P_current_student != NULL)
	{
		while(P_current_student)
		{
			Dprintf("\nrecord number : %d",count+1);
			Dprintf("\n\t student id : %d",P_current_student->student.ID);
			Dprintf("\n\t student name : %s",P_current_student->student.Name);
			Dprintf("\n\t student height : %f",P_current_student->student.height);
			P_current_student = P_current_student->P_next_Student;
			count++;
		}
	}
	else
	{
		Dprintf("\nemprty list");
	}


}


void remove_all()
{

	struct Sstudents* P_current_student = P_first_student;

		if(P_current_student != NULL)
		{
			while(P_current_student)
			{
				struct Sstudents* P_temp_student = P_current_student;
				P_current_student = P_current_student->P_next_Student;
				free(P_temp_student);
			}
			P_first_student = NULL;
		}
		else
		{
			Dprintf("emprty list");
		}

}

int GetNth()
{
	int index , count=1;
	Dprintf("\nEnter the index number:");
	scanf("%d",&index);

	struct Sstudents* P_temp_student=P_first_student;

	//check if empty
	while(P_temp_student)
	{
		if(count == index)
		{
			Dprintf("\n\t student id : %d",P_temp_student->student.ID);
			Dprintf("\n\t student name : %s",P_temp_student->student.Name);
			Dprintf("\n\t student height : %f",P_temp_student->student.height);
			return 1;
		}
		else
		{
			P_temp_student=P_temp_student->P_next_Student;
			count++;
		}
	}
	Dprintf("\nErorr: the index is out of list");
	return 0;
}


int Linked_list_length()
{
	int linked_counter=0;
	struct Sstudents* P_temp_student=P_first_student;

	while(P_temp_student)
		{
			P_temp_student=P_temp_student->P_next_Student;
			linked_counter++;
		}
	Dprintf("\nLength of list = %d",linked_counter);
	return linked_counter;
}


int Node_from_end()
{
	int node;
		Dprintf("\nEnter the node number (from end):");
		scanf("%d",&node);

	struct Sstudents* P_ref=P_first_student;
	struct Sstudents* P_main=P_first_student;


	if(P_ref)
	{
		if(node>Linked_list_length())
		{
			Dprintf("\nSo node is out from the list");
			return 0;
		}

		int i;
		for(i=0 ; i<node; i++)
			P_ref=P_ref->P_next_Student;


		//shift
		while(P_ref)
		{
		P_ref=P_ref->P_next_Student;
		P_main=P_main->P_next_Student;
		}

		//print

		Dprintf("\n\t student id : %d",P_main->student.ID);
					Dprintf("\n\t student name : %s",P_main->student.Name);
					Dprintf("\n\t student height : %f",P_main->student.height);
					return 1;
	}
	Dprintf("\nEmpty list");
	return 2;
}

int main(void) {

 char text[40];
    while(1){
	Dprintf("\n===================");
	Dprintf("\nOptions:");
	Dprintf("\n1.Add student");
	Dprintf("\n2.Remove student");
	Dprintf("\n3.View student");
	Dprintf("\n4.remove all");
	Dprintf("\n5.Get Nth node");
	Dprintf("\n6.Length of list");
	Dprintf("\n7.Node from end");
	Dprintf("\nenter your option: ");
	gets(text);
	Dprintf("\n===================");
	switch(atoi(text))
	{
	case 1:
		Add_Student();
		break;

	case 2:
			Remove_Student();
			break;

	case 3:
			view_students();
			break;

	case 4:
			remove_all();
			break;

	case 5:
			GetNth();
			break;

	case 6:
			Linked_list_length();
			break;

	case 7:
		    Node_from_end();
			break;

	default:
		Dprintf("\nWrong option");
	}

    }
	return EXIT_SUCCESS;
}
