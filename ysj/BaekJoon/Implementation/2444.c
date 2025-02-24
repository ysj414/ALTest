#include<stdio.h>

int main(void)
{
	int N = 0;
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++)
	{
		for(j = N-i; j>0; j--)
			printf(" ");
		for(k = 0; k <2*i-1; k++)
			printf("*");
		printf("\n");
	}

	for(i = N-1; i >= 0; i--)
	{
		for(j = i; j <= N-1; j++)
			printf(" ");
		for(k = 0; k <2*i-1; k++)
			printf("*");
		printf("\n");
	}

	return 0;
}
