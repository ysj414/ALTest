#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	int N;


	cin>>N;
	getchar();
	while(N--)
	{
		char buf[32]={0,};
		fgets(buf,32,stdin);
		int len = strlen(buf);
		buf[len-1]='\0';
		len--;
		if(buf[0]>=97)
			buf[0]-=32;
		cout<<buf<<"\n";

	}

	return 0;
}
