#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	char buf[101];
	
	cin>>buf;
	int len=strlen(buf);
	for(int i=0;i<len;i++)
		if(buf[i] >= 65 && buf[i] <= 90)
			cout<<buf[i];
	cout<<"\n";


	return 0;
}
