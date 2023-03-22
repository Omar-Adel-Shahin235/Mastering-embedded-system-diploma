
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,i,n,fact=1;

	for(n=0;n<3;n++)
	{

		printf("Enter an integer: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&x);

		if(x>=0)
		{
			if(x>0){
				for(i=x;i>0;i--)
				{
					fact*=i;
				}
			}
			else
				fact =1;
			printf("Fctorial = %d\n",fact);
		}
		else
			printf("Erorr!!! factorial on negative number doesn't exist\n");

	}
	return EXIT_SUCCESS;
}
