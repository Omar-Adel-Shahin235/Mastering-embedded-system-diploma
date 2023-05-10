#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	char x = 'A';
	char *ptr = &x;

	int i;
	for(i=0 ; i<26 ; i++)
		printf("%c ",(*ptr)+i);

    return 0;
}
