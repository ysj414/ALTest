#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{

	char buf[101];
	int cnt[123]= {0,};

	cin>>buf;
	int len = strlen(buf);

	for(int i=0; i<len; i++)
	{
		int a = (int)buf[i];
		cnt[a]++;
	}
	for(int i=97;i<=122;i++)
		cout<<cnt[i]<<" ";


	return 0;
}
