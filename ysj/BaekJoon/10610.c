#include<stdio.h>
#include<string.h>

char buf[100005];
int main(void)
{
	int num[11]={0,};
	int check=0;
	int len=0;
	int i,j;
	int index;
	char temp;
	int cnt=0;
//	printf("%d %d\n",a,b); 48:0 57:9
	scanf("%s",buf);
	len=strlen(buf);
	for(i=0; i<len;i++)
	{
		if(buf[i]=='0')
			cnt++;
		check+=(buf[i]-48);
		num[buf[i]-48]++;
	}
	if(check % 3 != 0 || cnt == 0)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		for(i=9;i>=0;i--)
		{
			for(j=0;j<num[i];j++)
				printf("%d",i);
		}
		printf("\n");
	}
	return  0;
}
