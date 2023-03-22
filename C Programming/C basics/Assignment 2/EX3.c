
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y,z;
	int i;

	for(i=0;i<3;i++)
	{

		printf("Enter three numbers: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f %f %f",&x,&y,&z);

		if(x>y){
			if(x>z)
				printf("largest number = %f\n\n",x);
			else
				printf("largest number = %f\n\n",z);
		}
		else
		{
			if(y>z)
				printf("largest number = %f\n\n",y);
			else
				printf("largest number = %f\n\n",z);
		}

	}
	return EXIT_SUCCESS;
}
