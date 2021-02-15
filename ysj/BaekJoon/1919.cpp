#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	int alpha1[26]={0,};
	int alpha2[26]={0,};
	char buf[1005];

	cin>>buf;
	for(int i=0; i<strlen(buf); i++)
		alpha1[buf[i]-97]++;
	memset(buf,0x0,sizeof(buf));
	cin>>buf;
	for(int i=0; i<strlen(buf); i++)
		alpha2[buf[i]-97]++;

	int sum=0;
	for(int j=0; j<26; j++)
	{
		if(alpha1[j] > alpha2[j])
			sum+=(alpha1[j]-alpha2[j]);
		else if(alpha1[j] < alpha2[j])
			sum+=(alpha2[j]-alpha1[j]);
	}
	cout<<sum<<"\n";


	return 0;
}
