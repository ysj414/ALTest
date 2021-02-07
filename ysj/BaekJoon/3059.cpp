#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{
	int Alpha[26]={0,};
	char buf[1005];
	int T;

	cin>>T;
	while(T--)
	{
		memset(buf,0x0,sizeof(buf));
		memset(Alpha,0x0,26*4);
		cin>>buf;
		for(int i=0;i<strlen(buf);i++)
			Alpha[buf[i]-65]=1;
		int sum=0;
		for(int i=0;i<26;i++)
		{
			if(Alpha[i] == 0)
				sum+=(i+65);
		}
		cout<<sum<<"\n";
	}


	return 0;

}
