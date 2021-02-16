#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char buf[1005];
	cin>>buf;
	int len = strlen(buf);
	memset(buf,0x0,sizeof(buf));
	cin>>buf;
	int len2= strlen(buf);
	(len>=len2)?cout<<"go\n":cout<<"no\n";

	return 0;
}
