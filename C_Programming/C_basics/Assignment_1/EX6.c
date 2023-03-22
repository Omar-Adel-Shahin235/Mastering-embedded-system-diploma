

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y,temp;


		printf("Enter value of a:");
fflush(stdin);
fflush(stdout);
		scanf("%f",&x);

		printf("Enter value of b:");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&y);

		//swap
		temp = x;
		x=y;
		y=temp;

		printf("After swapping, value of a = %f \nAfter swapping, value of b = %f",x,y);


	return EXIT_SUCCESS;
}
