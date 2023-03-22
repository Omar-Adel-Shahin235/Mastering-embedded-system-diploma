
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x;
	int i;

	for(i=0;i<3;i++)
	{

		printf("Enter a number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&x);

		if(x>0)
			printf("%f is positive\n",x);

		else if(x<0)
			printf("%f is negative\n",x);

		else

			printf("You entered zero.\n");

	}


	return EXIT_SUCCESS;
}
