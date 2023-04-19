#include <stdio.h>
#include <stdlib.h>


unsigned long long Factorial(int num);


int main(void) {

	int n;

	printf("Enter the number to find factorial :");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	if(n>=0)
	{
		printf("the factorial of %d is %llu",n,Factorial(n));
	}
	else
	printf("You entered a negative number");

	return 0;
}


unsigned long long Factorial(int num){

	if(num>0)
	{

		return (num*Factorial(num-1));
	}
	else
		return 1;
}
