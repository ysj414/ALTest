#include<stdio.h>
#include<string.h>

int main(void)
{
	int num;
	scanf("%d",&num);
	int count=0;

	while(num/10 >= 1)
	{
		int tnum=1;
		int digit;
		while(num/10>=1)
		{
			digit=num%10;
			tnum*=digit;
			num/=10;
		}
		tnum*=num;
		num=tnum;
//		printf("%d\n",num);
		count++;
	}
	printf("%d\n",count);
	return 0;
}
