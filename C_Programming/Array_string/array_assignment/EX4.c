#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,i,insert,loc, a[10];

	printf("Enter no of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	for(i=0 ; i<x ; i++){
		a[i]=(i+1);
		printf("%d",a[i]);
	}

	//takes the insert number
	printf("\nEnter the element to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&insert);

	//takes the location
	printf("Enter the location: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&loc);

	//shifting the array from location
	for(i= x ; i>=loc ; i--)
	{
		a[i]=a[i-1];
	}

	a[(loc-1)]=insert;

	//print the result
	for(i=0 ; i<(x+1) ; i++)
	{
		printf("%d",a[i]);
	}

	return EXIT_SUCCESS;
}
