#include<iostream>

using namespace std;

char chess[65]="FTFTFTFTTFTFTFTFFTFTFTFTTFTFTFTFFTFTFTFTTFTFTFTFFTFTFTFTTFTFTFTF";

int main(void)
{
	int count=0;

	char temp;
	for(int i=0;i<64;i++)
	{
		cin>>temp;
		if(temp == chess[i])
			count++;
	}

	cout<<count<<"\n";



	return 0;
}
