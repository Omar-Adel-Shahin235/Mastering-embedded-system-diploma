#include <stdio.h>
#include <stdlib.h>
#define AREA(R) (3.14*(R)*(R))


int main() {


	float radius;

	printf("Enter the radius: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&radius);


	printf("Area = %.2f",AREA(radius));

	return 0;
}
