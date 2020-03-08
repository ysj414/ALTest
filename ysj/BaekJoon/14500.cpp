#include<iostream>

using namespace std;

int map[500][500];

int block[2][4][4]=
{
	{
	 {1,1,1,1},
	 {0,0,0,0},
	 {0,0,0,0},
	 {0,0,0,0}
	},

	{
	 1,1,1,0,
	 0,0,1,0,
	 0,0,0,0,
	 0,0,0,0
	}

};


int main(void)
{
	int N,M;
/*
	cin>>N>>M;

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>map[i][j];
*/
	for(int i=0; i<2;i++)
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++)
				printf("%d ",block[i][j][k]);
			cout<<endl;
		}






}
