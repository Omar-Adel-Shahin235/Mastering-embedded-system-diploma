#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

	char a[100];
	int i,len;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(a);

    len = strlen(a);

	printf("reverse string is : ");
	for(i=(len-1) ; i>=0 ; i--)
	printf("%c",a[i]);

	return EXIT_SUCCESS;
}
