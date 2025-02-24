#include<stdio.h>

int matA[100][100] = {0,};
int matB[100][100] = {0,};
int result[100][100] = {0,};

int main(void)
{
	int N, M;
	int i, j;

	scanf("%d %d", &N, &M);
	for(i = 0; i< N; i++)
	{
		for(j = 0; j < M; j++)
		{
			scanf("%d", &matA[i][j]);
		}
	}

	for(i = 0; i< N; i++)
	{
		for(j = 0; j < M; j++)
		{
			scanf("%d", &matB[i][j]);
		}
	}

	for(i = 0; i< N; i++)
	{
		for(j = 0;  j < M; j++)
		{
			result[i][j] = matA[i][j]+matB[i][j];
		}
	}

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
}
