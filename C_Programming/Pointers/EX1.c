#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int m = 29;
	int *ab;

	printf("Address of m: %x\nvalue of m=%d\n\n",&m,m);

	ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab:%x\ncontent of pointer ab=%d\n\n",ab,*ab);

	m=34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab:%x\ncontent of pointer ab=%d\n\n",ab,*ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m:%x\nvalue of m=%d",&m,m);


    return 0;
}
