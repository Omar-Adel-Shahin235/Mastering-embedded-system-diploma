#include <stdio.h>
#include <stdlib.h>

struct Sstudent
{
	char name[20];
	int roll_number;
	float marks;
};


int main() {

	struct Sstudent student1;

	printf("Enter information of student:");
	printf("\n\nEnter name: ");
	fflush(stdin); fflush(stdout);
	gets(student1.name);

	printf("Enter roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&student1.roll_number);


	printf("Enter marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&student1.marks);

	//displaying information
	printf("\ndisplaying information:\n");
	printf("name: %s\nRoll: %d\nMarks: %.2f",student1.name,student1.roll_number,student1.marks);

	return 0;
}
