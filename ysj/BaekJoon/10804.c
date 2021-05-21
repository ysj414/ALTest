#include<stdio.h>

int main(void)
{
	int a[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
	int x,y;
	int temp;
	int i,j;

	for(i=0; i<10; i++)
	{
		scanf("%d %d",&x,&y);
		for(j=x; j<=(x+y)/2; j++)
		{
			temp=a[j];
			a[j]=a[y+x-j];
			a[y+x-j]=temp;
		}
	}

	for(i=1;i<=20;i++)
		printf("%d ",a[i]);

	return 0;
}
