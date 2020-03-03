#include<iostream>
#include<cstring>

using namespace std;

//97 to 122
int main(void)
{

	char str[100];
	int N;
	int num;
	int i;
	int flag;
	cin>>str;
	N=strlen(str);
	num=97;
	while(num<=122)
	{
	
		flag=0;
		for(i=0;i<N;i++)
		{
	  	  if(num == (int)str[i])
		  {
		  	cout<<i<<" ";
			flag=1;
			break;
		  }
		}
	if(flag==0)
		cout<<-1<<" ";

	num++;

	}
	cout<<"\n";
	return 0;
}

