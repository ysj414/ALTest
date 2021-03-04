#include<iostream>
#include<cstring>


using namespace std;

int gcd(int a, int b);
int main(void)
{
	int a,b;

	scanf("%d:%d",&a,&b);
	int g=gcd(a,b);
	a=a/g;
	b=b/g;

	printf("%d:%d\n",a,b);

	return 0;
}

int gcd(int a, int b)
{
	int ret=1;
	int len;
	len = (a>b)?b:a;
	for(int cnt=1; cnt<=len; cnt++)
	{
		if((a%cnt == 0) && (b%cnt == 0))
			ret=cnt;
	}
	return ret;
}
