#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{
	char buf1[101];
	char buf2[101];
	char result[201];
	char _operator;

	cin>>buf1;
	cin>>_operator;
	cin>>buf2;


	if(_operator == '*')
	{
		strcpy(result,buf1);
		int len1=strlen(buf1);
		int len2=strlen(buf2);

		for(int i=len1;i<(len1+len2-1);i++)
			result[i]='0';
	}
	else
	{
		int len1=strlen(buf1);
		int len2=strlen(buf2);
		if(len1<len2)
		{
			strcpy(result,buf2);
			result[len2-len1]='1';
		}
		else if(len1 == len2)
		{
			strcpy(result,buf1);
			result[0]='2';
		}
		else
		{
			strcpy(result,buf1);
			result[len1-len2]='1';
		}
	}

	cout<<result<<"\n";

	return 0;
}
