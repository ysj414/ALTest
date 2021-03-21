#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char buf[105];
	cin>>buf;
	for(int i=0; i<strlen(buf); i++)
	{
		if(buf[i]<97)
			buf[i]+=32;
		else
			buf[i]-=32;
	}
	cout<<buf<<"\n";

	

	return 0;
}
