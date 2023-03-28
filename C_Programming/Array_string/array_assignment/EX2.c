#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int inputs,i;
    float sum=0,avg,k;

    printf("enter the numbers of data: ");
    fflush(stdin); fflush(stdout);
    scanf("%d",&inputs);

	for(i=0 ; i<inputs ; i++)
	{
		printf("%d. enter a number:",(i+1));
		fflush(stdin); fflush(stdout);
		scanf("%f",&k);
		sum+=k;
	}

	avg = sum/(i);
	printf("\nAverage = %.2f",avg);

	return EXIT_SUCCESS;
}
