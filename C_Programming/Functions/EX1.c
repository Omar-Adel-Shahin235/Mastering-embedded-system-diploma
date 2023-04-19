#include <stdio.h>
#include <stdlib.h>


void Prime_numbers(int n , int m);

int main(void) {

	int n,m;

	printf("Enter two numbers(intervals) :");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&n,&m);
     Prime_numbers(n,m);

	return 0;
}


void Prime_numbers(int n , int m){

	int i,j,prime=0;
	printf("prime numbers between %d and %d are: ",n,m);
	for(i=(n+1);i<m;i++)
	{
		for(j=2;j<=(i/2);j++)
		{
			if((i%j)==0)
			{
				prime=1;
			    break;
			}
		}
		if(prime==0)
			printf("%d ",i);
		prime =0;
	}
}
