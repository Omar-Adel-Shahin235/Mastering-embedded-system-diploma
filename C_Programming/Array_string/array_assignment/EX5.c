#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,i,n,search,a[10];


    printf("Enter no of elements: ");
	fflush(stdin); fflush(stdout);
    scanf("%d",&x);

    for(i=0 ; i<x ; i++)
	{
	    a[i]=(i+1);
	    printf("%d\t",a[i]);
	}

	for(n=0 ; n<2 ; n++)
	{
	    //searching
	    printf("\nEnter the elements to be searched : ");
	    fflush(stdin); fflush(stdout);
	    scanf("%d",&search);

	    for(i=0 ; i<x ; i++)
	    {
	    	if(a[i]==search)
			break;
	    }

	    if(i!=5)
	    	printf("number found at the location = %d",(i+1));
	    else
	    	printf("number not found");
	}
	return EXIT_SUCCESS;
}
