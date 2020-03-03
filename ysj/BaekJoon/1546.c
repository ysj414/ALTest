#include<stdio.h>

int main(void)
{
	int N;
	float a[1000];
	int i;
	float max=0;
	float answer=0;

	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		scanf("%f",&a[i]);
		if(a[i] > max)
			max=a[i];
	}
	for(i=0;i<N;i++)
	{
		answer+=a[i]/max*100;
	}
	printf("%.2f\n",answer/N);


	return 0;
}
