#include<iostream>
#include<cstring>


using namespace std;


int main(void)
{
	char buf[101];

	cin>>buf;
	int len = strlen(buf);
	int flag =1;
	for(int i = 0; i<(len/2); i++)
	{
		if(buf[i] != buf[len-1-i])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
		cout<<1<<"\n";
	else
		cout<<0<<"\n";

	return 0;
}
