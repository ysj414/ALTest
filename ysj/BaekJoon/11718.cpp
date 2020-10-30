#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char buf[101];

	
	while(fgets(buf,101,stdin))
	{
		cout<<buf;
		memset(buf,0,sizeof(buf));
	}
	cout<<"\n";

	return 0;
}
