#include<stdio.h>
#include<string.h>
int main(void)
{
	int A,B,C;
	int answer;
	int len=0;
	int temp;
	int a[10]={0,};
	int i,cnt;
	scanf("%d",&A);
	scanf("%d",&B);
	scanf("%d",&C);
	
	answer = A*B*C;
	cnt =1;
	while(answer > cnt)
	{
		cnt *=10;
		len++;

	}
	for(i=0;i<len;i++)
	{
		temp = answer%10;

		switch(temp)
		{
			case 0:
				a[0]++;
				break;
			case 1:
				a[1]++;
				break;
			case 2:
				a[2]++;
				break;
			case 3:
				a[3]++;
				break;
			case 4:
				a[4]++;
				break;
			case 5:
				a[5]++;
				break;
			case 6:
				a[6]++;
				break;
			case 7:
				a[7]++;
				break;
			case 8:
				a[8]++;
				break;
			case 9:
				a[9]++;
				break;
			deafult:
				break;

		}
	   answer = answer/10;

	}
	for(i=0; i< 10 ; i++)
		printf("%d\n",a[i]);


	return 0;}
