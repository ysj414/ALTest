#include<iostream>

using namespace std;

#define NOMATCH		"PREDAJA"
int str[125]  = {0,};

int main(void)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char buf[32]={0,};
		cin>>buf;
		int a= (int)buf[0];
		str[a]++;		
	}
	int flag = 0;
	for(int i=97; i<=122; i++)
	{
		if(str[i] >= 5)
		{
			char ok = (char)i;
			cout<<ok;
			flag = 1;
		}
	}
	if(flag == 0)
		cout<<NOMATCH;
	cout<<"\n";

	return 0;
}
