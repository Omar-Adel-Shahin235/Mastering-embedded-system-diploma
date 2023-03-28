
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a[2][2] , b[2][2] , sum[2][2];
	int i,j;

	printf("Enter the elements of first matrix\n");
	for(i=0 ;i<2; i++){
		for(j=0 ;j<2;j++){
			printf("Enter a%d%d :",(i+1),(j+1));
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}

	printf("Enter the elements of second matrix\n");
	for(i=0 ;i<2; i++){
		for(j=0 ;j<2;j++){
			printf("Enter b%d%d :",(i+1),(j+1));
			fflush(stdin); fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}



	printf("sum of matrix\n");
	for(i=0 ;i<2; i++){
		for(j=0 ;j<2;j++){
			sum[i][j]=a[i][j];
			//display
			printf("%.2f\t",sum[i][j]);
		}
		printf("\n");
	}

	return 0;
}
