#include<stdio.h>


int main(void)
{
	int N,M,L;
	int a[1001]={0,};

	scanf("%d %d %d",&N,&M,&L);
	int toss=1;
	a[1]=1;
	int count=0;
	while(1)
	{
		if(a[toss] == M)
		{
			printf("%d\n",count);
			break;
		}
//		printf("%d toss ->",toss);
		if(a[toss] % 2 == 0)
		{
			if(toss-L<=0)
				toss=toss+N-L;
			else
				toss-=L;
		}
		else
		{
			if(toss+L>N)
				toss=(toss+L)%N;
			else
				toss+=L;
		}
		a[toss]++;
//		printf("%d, M:%d\n",toss,a[toss]);
		count++;
	}


	return 0;
}
