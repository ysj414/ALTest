#include<stdio.h>

int main(void)
{
	int bucket[110]={0,};
	int N,M;
	int i,j,k,m,n;
	
	scanf("%d %d",&N, &M);
	for(m=0; m<M; m++)
	{
		scanf("%d %d %d",&i,&j,&k);
		for(n=i; n<=j; n++)
			bucket[n]=k;
	}

	for(i=1;i<=N;i++)
		printf("%d ",bucket[i]);


	return 0;
}
