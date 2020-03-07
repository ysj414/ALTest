#include<iostream>

using namespace std;
int map[101][101]={0,};

int main(void)
{
	int Lx,Ly,Rx,Ry;
	int sum=0;
	int Mx=0;
	int My=0;
	for(int i=0;i<4;i++)
	{
		cin>>Lx>>Ly>>Rx>>Ry;
		if(Rx>Mx)
			Mx=Rx;
		if(Ry>My)
			My=Ry;

		for(int j=Ry-1;j>=Ly;j--)
		{
			for(int k=Lx;k<Rx;k++)
				map[j][k]=1;
		}
	}
	for(int i=Ry;i>=0;i--)
	{
		for(int j=0;j<=Rx;j++)
		{
			if(map[i][j] == 1)
				sum++;
//			cout<<map[i][j]<<" ";
		}
//		cout<<'\n';
	}

	cout<<sum<<'\n';
	return 0;
}
