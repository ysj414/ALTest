#include<stdio.h>

#define SQAURE_LEN	10

int white_paper[101][101] = {0,};

int main(void)
{
	int N;
	int row, col;
	int i, j = 0;
	int area = 0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d %d", &row, &col);
		for(i = row; i <= row +SQAURE_LEN-1; i++)
		{
			for(j = col; j <= col +SQAURE_LEN-1; j++)
			{
				white_paper[i][j] = 1;
			}
		}
	}

	for(i = 1; i <= 100; i++)
		for(j = 1; j <= 100; j++)
			if(white_paper[i][j])
				area++;

	printf("%d\n",area);


	return 0;
}
