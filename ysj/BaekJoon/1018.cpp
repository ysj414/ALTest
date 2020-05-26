#include<iostream>

using namespace std;

char map[52][52];
int N,M;
int main(void)
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		for(int j=0; j<M;j++)
			cin>>map[i][j];
	}

	int MIN=999999;

	for(int i=0;i<N;i++)
	{
		
		if(i+8>N)
			break;

		for(int j=0;j<M;j++)
		{
			if(j+8>M)
				break;
			int cnt=0;
			for(int k=i;k<i+8;k++)
			{

				char current=map[k][j];
				for(int m=j+1;m<j+8;m++)
				{
					if(current == map[k][m])
					{
					   cnt++;
					   if(current=='W')
						   current='B';
					   else
						   current='W';
					}
					else
						current = map[k][m];
				}
			}

			if(cnt<MIN)
				MIN=cnt;
		}
	}


	for(int i=N-1;i>=0;i--)
	{
		if(i-8<-1)
			break;
		int cnt=0;
		for(int j=M-1;j>=0;j--)
		{
			if(j-8<-1)
				break;
			int cnt=0;
			for(int k=i;k>i-8;k--)
			{
				char current=map[k][j];
				for(int m=j-1;m>j-8;m--)
				{
					if(current == map[k][m])
					{
						cnt++;
						if(current=='W')
							current=='B';
						else
							current='W';
					}
					else
						current=map[k][m];
					}
				}

			   if(cnt<MIN)
				   MIN=cnt;
		 }
	}

	cout<<MIN<<"\n";

	return 0;
}

