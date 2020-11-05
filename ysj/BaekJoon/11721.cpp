#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char buf[101];
	char result[11];

	cin>>buf;
	int len = strlen(buf);

	for(int i=0; i<len; i=i+10)
	{
		strncpy(result,buf+i,10);
		cout<<result<<"\n";
		memset(result,0,sizeof(result));
	}




	return 0;
}

