
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,i;

	for(i=0;i<2;i++)
	{
		printf("Enter an integer you want to check: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&x);

		if((x%2)==0)
			printf("%d is even\n",x);
		else
			printf("%d is odd\n",x);
	}

	return EXIT_SUCCESS;
}
