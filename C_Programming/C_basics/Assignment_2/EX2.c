
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char x,i;
	for(i=0;i<3;i++){

		printf("Enter an alphabet: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&x);

		switch(x){

		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("%c is a vowel\n",x);
			break;

		default:
			printf("%c is a consonant\n",x);
			break;
		}
	}
	return EXIT_SUCCESS;
}
