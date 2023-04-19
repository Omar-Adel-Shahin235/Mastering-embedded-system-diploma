#include <stdio.h>
#include <stdlib.h>


void Reverse(void);

int main(void) {


	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	Reverse();
	return 0;
}


void Reverse(){

    char a;
	scanf("%c",&a);
	if(a!='\n')
	{
		Reverse();
		printf("%c",a);
	}

}
