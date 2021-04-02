#include<stdio.h>

int main(void)
{
	int bucket[110];
	int N,M;
	int i,j,k;
	int temp;
	scanf("%d %d", &N, &M);
	for(i=1; i<=N; i++)
		bucket[i]=i;
	for(i=0; i<M; i++)
	{
		scanf("%d %d",&j,&k);
		temp =bucket[j];
		bucket[j]=bucket[k];
		bucket[k]=temp;
	}
	for(i=1; i<=N; i++)
		printf("%d ",bucket[i]);



	return 0;

}
