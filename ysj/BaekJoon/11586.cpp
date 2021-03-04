#include<iostream>
#include<cstring>

using namespace std;

char buf[101][101];
int main(void)
{
	int N;
	cin>>N;

	for(int i=0; i<N;i++)
		cin>>buf[i];
	int state;
	cin>>state;

	if(state == 2)
	{
		for(int i=0; i<N;i++)
		{
			for(int j=0;j<N/2;j++)
			{
				char temp=buf[i][j];
				buf[i][j]=buf[i][N-1-j];
				buf[i][N-1-j]=temp;
			}
		}

	}
	else if(state == 3)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N/2; j++)
			{
				char temp=buf[j][i];
				buf[j][i]=buf[N-1-j][i];
				buf[N-1-j][i]=temp;
			}
		}
	}
	for(int i=0;i<N;i++)
		cout<<buf[i]<<"\n";

	return 0;
}
