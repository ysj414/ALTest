#include<iostream>
#include<cstring>


using namespace std;

int main(void)
{
	int T;
	int alpha1[26]={0,};
	int alpha2[26]={0,};
	char buf1[105], buf2[105];

	cin>>T;
	while(T--)
	{
		memset(buf1,0x0,sizeof(buf1));
		memset(buf2,0x0,sizeof(buf2));
		cin>>buf1>>buf2;
		if(strlen(buf1) != strlen(buf2))
		{
			cout<<buf1<<" & "<<buf2<<" are NOT anagrams."<<"\n";
			continue;
		}

		int flag=1;
		for(int i=0;i<strlen(buf1);i++)
			alpha1[buf1[i]-97]++;

		for(int i=0;i<strlen(buf2);i++)
			alpha2[buf2[i]-97]++;
		for(int i=0;i<26;i++)
		{
			if(alpha2[i] == 0)
				continue;
			else
			{
				if(alpha1[i]!=alpha2[i])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<buf1<<" & "<<buf2<<" are anagrams."<<"\n";
		else
			cout<<buf1<<" & "<<buf2<<" are NOT anagrams."<<"\n";

	}
	return 0;
}

