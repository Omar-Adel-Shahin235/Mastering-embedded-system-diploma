
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char x;
	int i;

	for(i=0;i<3;i++)
	{

		printf("Enter a character: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&x);

		if((x>='A' && x<='Z') || (x>='a' && x<='z'))
			printf("%c is an alphabet\n",x);

		else
			printf("%c is not an alphabet\n",x);
	}

	return EXIT_SUCCESS;
}
