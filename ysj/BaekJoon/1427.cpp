#include<iostream>
#include<cstring>
using namespace std;

int cnt[20]={0,};

int main(void)
{
	
	char temp[102];
	char *ch=temp;
	while(1)
	{
		memset(temp,0x0,102);
		ch=fgets(temp,102,stdin);
		if(ch ==NULL || temp[0]=='\n')
			break;
		int len = strlen(temp);
		temp[len-1]='\0';
		len--;
		for(int k=0;k<len;k++)
			cnt[temp[k]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<cnt[i];j++)
			cout<<i;
	}	
	cout<<"\n";

	return 0;
}
