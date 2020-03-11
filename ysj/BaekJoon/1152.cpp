#include<iostream>
#include<cstring>

using namespace std;

char str[1000001];

int main(void)
{
	char* ptr;
	int cnt=0;
	fgets(str,1000001,stdin);
	int len = strlen(str);
	

	for(int i=0;i<len;i++)
		if(str[i]==' ')
			cnt++;

	if(str[0]==' ')
	{
		if(len <=2){
			cout<<0<<"\n";
			return 0;
		}
		cnt--;
	}
	if(str[len-2]==' ')
		cnt--;

	cout<<cnt+1<<"\n";
	return 0;
}
