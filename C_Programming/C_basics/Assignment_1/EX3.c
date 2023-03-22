
#include <stdio.h>
#include <stdlib.h>


int main(void) {

	int x,y;

	printf("Enter TWO Integers: ");

	fflush(stdin);
	fflush(stdout);

	scanf("%d %d",&x,&y);

	printf("sum: %d",x+y);

	return 0;
}
