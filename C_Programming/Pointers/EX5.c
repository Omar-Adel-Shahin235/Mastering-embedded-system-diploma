#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Semployee
{
	char *Employee_name;
	int Employee_id;
};

int main() {

	struct Semployee emp1={"omar",15} , emp2={"ali",12};

	struct Semployee (*x[])={ &emp1,&emp2 };

	struct Semployee (*(*ptr)[2]) = &x;


	printf("Employee name: %s\n",((*ptr)[1])->Employee_name);

	printf("employee id = %d ",((*ptr)[1])->Employee_id);


    return 0;
}
