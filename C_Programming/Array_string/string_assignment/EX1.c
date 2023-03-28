#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char a[100],b,counter;
	int i;

	printf("Enter a string:");
	fflush(stdin); fflush(stdout);
	gets(a);

	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&b);

	//searching
	for(i=0 ; i<(strlen(a)) ; i++){
		if(a[i]==b)
			counter++;
	}

	printf("Frequency of %c = %d",b,counter);

	return EXIT_SUCCESS;
}
