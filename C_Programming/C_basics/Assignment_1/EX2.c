
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	int x;

	printf("Enter an integer:");

	fflush(stdin);
	fflush(stdout);

	scanf("%d",&x);

	printf("You entered: %d",x);

	return 0;
}
