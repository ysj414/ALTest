#include<iostream>
#include<cstring>

using namespace std;

void rev(char *str, int len);
int main(void)
{
	char buf1[10],buf2[10];
	char buf3[10]={0,};
	int a;

	scanf("%s %s",buf1,buf2);
	rev(buf1,strlen(buf1));
	rev(buf2,strlen(buf2));
	a = atoi(buf1)+atoi(buf2);

	for(int i=0;i<5;i++)
	{
		int digit = a%10;
		buf3[i]=digit+48;
		a=a/10;
		if(a == 0)
			break;
	}
	a = atoi(buf3);
	printf("%d\n",a);


	return 0;
}

void rev(char *str, int len)
{
	for(int i=0; i<(len/2); i++)
	{
		char temp=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=temp;
	}
}
