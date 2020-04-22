#include<iostream>

using namespace std;

int fac(int num);
int main(void)
{

	int n;
	int result=0;
	cin>>n;
	result=fac(n);
	cout<<result<<"\n";

	return 0;
}
int fac(int num)
{
	if(num==0)
	{
		return 1;
	}
	else
		return num*fac(num-1);
}
