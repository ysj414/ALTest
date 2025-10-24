#include<stdio.h>
#include<string.h>


int main(void)
{
	char A[10005];
	char B[10005];
	int gugu[10][10];
	int len1,len2;
	int i,j;
	long long sum=0;

	scanf("%s %s",A,B);
	
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			gugu[i][j]=i*j;

	len1=strlen(A);
	len2=strlen(B);
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			printf("%d\n",gugu[A[i]-48][B[j]-48]);
			sum+=gugu[A[i]-48][B[j]-48];
		}
	}
	printf("%lld\n",sum);

	return 0;
}

