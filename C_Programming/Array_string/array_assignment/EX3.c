#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i,j,row,column;

	printf("Enter rows and column of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&row,&column);

	int a[row][column];

	printf("Enter elements of matrix\n");

	for(i=0 ; i<row ; i++)
	{
		for(j=0 ; j<column ; j++)
		{
			printf("Enter elements a%d%d: ",(i+1),(j+1));
			fflush(stdin); fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Entered Matrix:\n");
	for(i=0 ; i<row ; i++)
		{
			for(j=0 ; j<column ; j++)
			{
				printf("%d\t",a[i][j]);
			}

		    printf("\n");
		}

	printf("Transpose of matrix:\n");

			for(j=0 ; j<column ; j++)
				{
					for(i=0 ; i<row ; i++)
					{
						printf("%d\t",a[i][j]);
					}

				    printf("\n");
				}

	return EXIT_SUCCESS;
}
