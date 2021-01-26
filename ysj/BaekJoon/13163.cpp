#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	int N;
	char buf[102];
	char buf2[102];
	char *p = NULL;
	cin>>N;
	getchar();
	while(N--)
	{
		memset(buf,0x0,102);
		memset(buf2,0x0,102);
		strcpy(buf2,"god");

		fgets(buf,102,stdin);
		int len = strlen(buf);
		buf[len-1]='\0';
		len--;


		p = strchr(buf,' ');
		int offset = (int)(p-buf)+1;
		int space=0;
		for(int i=offset; i<len; i++)
		{
			if(buf[i] == ' ')
			{
				space++;
				continue;
			}
			buf2[i-offset-space+3]=buf[i];
		}
		cout<<buf2<<"\n";

	}


	return 0;
}
