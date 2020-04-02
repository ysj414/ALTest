#include<iostream>
#include<cstring>

using namespace std;


char str[101];
int a[123];

int main(void)
{

	int N;
	cin>>N;
	int sum=0;
	int isgroup;

	for(int i=0;i<N;i++)
	{
		memset(str,0,sizeof(str));
		memset(a,0,sizeof(a));
		cin>>str;
		int len=strlen(str);

		for(int j=0;j<len;j++)
		{
			if(!a[str[j]])
			{
				a[str[j]]=true;
				while(str[j]==str[j+1])
				{
					j++;
				}
			  isgroup=1;	  	
			}
			else
			{
				isgroup=0;
				break;
			}
		}
		sum+=isgroup;
	}

	cout<<sum<<"\n";

	return 0;

}
