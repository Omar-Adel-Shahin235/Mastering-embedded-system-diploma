
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y;

		printf("Enter value of a:");
        fflush(stdin);
        fflush(stdout);
		scanf("%f",&x);

		printf("Enter value of b:");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&y);

		//swap
		x*=y;
		y=x/y;
		x/=y;

		//another swap method
		/*
		 * x+=y;
		 * y=x-y;
		 * x-=y;
		 */
		printf("After swapping, value of a = %f \nAfter swapping, value of b = %f",x,y);

	return EXIT_SUCCESS;
}
