#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char str1[1001];
	char str2[1001];
	char check[1001]={0,};
	int result=0;

	cin>>str1;
	cin>>str2;
	int len1 =strlen(str1);
	int len2 =strlen(str2);


	int cursor=0;
	for(int i=0; i<len1; i++)
	{
		int walker = 0;
		int flag =0;
		for(int j=cursor;j<len2;j++)
		{
			if(str1[i] == str2[j])
			{
				flag = 1;
				cout<<str2[j]<<"\n";
				result++;
				cursor += walker;
				break;
			}
			walker++;
		}
		if(flag)
		  cursor++;
		cout<<"cursor:"<<cursor<<"\n";
	}

	cout<<result<<"\n";
	return 0;
}
