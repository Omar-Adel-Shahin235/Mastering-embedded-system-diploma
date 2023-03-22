
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	char x;

	printf("Enter a character:");

	fflush(stdin);
	fflush(stdout);

	scanf("%c",&x);

	printf("ASCII value of %c = %d",x,x);

	return 0;
}
