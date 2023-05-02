#include <stdio.h>
#include <stdlib.h>

struct Sstudent
{
	char name[20];
	int roll_number;
	float marks;
};


int main() {

	struct Sstudent student[10];
	int i;
	printf("Enter information of students:\n");

	for(i=0;i<10;i++){
	student[i].roll_number=(i+1);

	printf("\nfor roll number %d\n",student[i].roll_number);
	printf("Enter name: ");
	fflush(stdin); fflush(stdout);
	gets(student[i].name);

	printf("Enter marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&student[i].marks);
	}

	//displaying information
	printf("\ndisplaying information of students:\n");

	for(i=0;i<10;i++)
	printf("Roll number: %d\nname: %s\nMarks: %.2f\n\n",student[i].roll_number,student[i].name,student[i].marks);

	return 0;
}
