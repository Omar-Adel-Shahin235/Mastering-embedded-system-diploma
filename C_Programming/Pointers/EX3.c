#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	char string[]="w3resource";

	char *ptr=string;

	int size=strlen(string),i;

	for(i=(size-1), ptr+=i ; i>=0 ; i-- )
	{
		printf("%c",*(ptr));
		ptr--;
	}


    return 0;
}
