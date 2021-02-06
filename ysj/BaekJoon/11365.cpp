#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{

	while(1)
	{
		char buf[501]={0,};
		fgets(buf,501,stdin);
		int len = strlen(buf);
		buf[len-1]='\0';
		len--;

		if(strcmp(buf,"END") == 0)
			break;
		for(int i=0; i<(len/2); i++)
		{
			char temp = buf[i];
			buf[i] = buf[len-1-i];
			buf[len-1-i] = temp;
		}
		cout<<buf<<"\n";
	}
	return 0;
}
