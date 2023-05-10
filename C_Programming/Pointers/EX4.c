#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int string[15]={3, 2 , 1 , 5 ,4} , size;
	int *ptr = string;

	printf("the number of elements is : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);

	/* get the data */
	int i;
	for(i=0 ; i<size ; i++ , ptr++)
	{
		printf("element-%d :",(i+1));
		fflush(stdin); fflush(stdout);
		scanf("%d",ptr);
	}

	printf("\nelements of reverse order are:\n");
	/* print the data */
	for(i=(size-1) ; i>=0 ; i--)
		printf("element-%d : %d\n",(i+1),*(--ptr));




    return 0;
}
