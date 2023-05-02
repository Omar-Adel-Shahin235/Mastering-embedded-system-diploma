#include <stdio.h>
#include <stdlib.h>

struct complex
{
	float real;
	float imj;
}sum;

void add_complex(struct complex sum , struct complex complex_number[2])
{
	    sum.real = complex_number[0].real+complex_number[1].real;
		sum.imj = complex_number[0].imj+complex_number[1].imj;

		printf("sum= %.1f+%.1fi",sum.real,sum.imj);
}

int main() {

	struct complex complex_number[2];
	int i;

	for(i=0;i<2;i++)
	{
		printf("enter information of %d distance",(i+1));
		printf("\nEnter real and imaginary respectively: ");
		fflush(stdin); fflush(stdout);
		scanf("%f %f",&complex_number[i].real,&complex_number[i].imj);
	}

	add_complex(sum,complex_number);

	return 0;
}
