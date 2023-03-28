#include <stdio.h>
#include <stdlib.h>


int main(void) {

	char a[100];
	int i;

	printf("Enter a string:");
	fflush(stdin); fflush(stdout);
	gets(a);

	for(i=0 ; a[i]!=0 ; i++);

	printf("Length of string: %d",i);

	return EXIT_SUCCESS;
}
