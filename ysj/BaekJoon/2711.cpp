#include<iostream>
#include<cstring>


using namespace std;

int main(void)
{
	int T;
	cin>>T;
	char buf[85];
	while(T--)
	{
		int pos;
		memset(buf,0x0,sizeof(buf));
		cin>>pos>>buf;
		for(int i=(pos-1); i<strlen(buf); i++)
			buf[i]=buf[i+1];
		cout<<buf<<"\n";
	}
}
