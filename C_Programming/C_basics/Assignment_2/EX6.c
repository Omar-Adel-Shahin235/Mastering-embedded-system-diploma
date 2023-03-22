
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,i,sum=0;

	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&x);

	if(x>0)
	{


		for(i=0;i<x;i++)
		{
			sum+=(i+1);
		}

		printf("Sum = %d",sum);
	}
	else
		printf("you entered a non natural number");

	return EXIT_SUCCESS;
}
