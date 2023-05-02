#include <stdio.h>
#include <stdlib.h>

struct Sinch_feet
{
	float inch;
	float feet;
}sum;

float after_point(float sum_of_inch)
{
	int i,pos;
	float sum=0;
	for(i=10;i<10000;i*=10)
	{
		pos = sum_of_inch*i;
		sum += ((pos%10)/(float)i);
	}
	return sum;
}

int main() {

	struct Sinch_feet distance[2];
	int i;

	for(i=0;i<2;i++)
	{
		printf("enter information of %d distance",(i+1));
		printf("\nEnter feet:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&distance[i].feet);

		printf("Enter inch:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&distance[i].inch);
	}

	sum.feet = distance[0].feet+distance[1].feet;
	sum.inch = distance[0].inch+distance[1].inch;

	int feet_1= (sum.inch)/12;
	sum.feet+=feet_1;

	sum.inch=after_point(sum.inch);  // if sum.inch=4.523 the return will be 0.523

	printf("sum of distances= %.2f'+%.2f\"",sum.feet,sum.inch);
	return 0;
}
