
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y;
	char symbol;


	printf("Enter operator either + or - or * or divide: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&symbol);

	printf("Enter two operands: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&x,&y);

	switch(symbol)
	{
	case '+':
		printf("%f + %f = %f",x,y,(x+y));
		break;

	case '-':
		printf("%f + %f = %f",x,y,(x-y));
		break;

	case '*':
		printf("%f + %f = %f",x,y,(x*y));
		break;

	case '/':
		printf("%f + %f = %f",x,y,(x/y));
		break;
	}


	return EXIT_SUCCESS;
}
