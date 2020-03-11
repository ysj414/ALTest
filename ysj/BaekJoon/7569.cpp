#include<iostream>
#include<queue>

using namespace std;

int N,M,H;
int map[100][100][100];
queue<pair<pair<int,int>,int>> q;
int dx[6]={0,0,-1,1,0,0};
int dy[6]={-1,1,0,0,0,0};
int dz[6]={0,0,0,0,-1,1};


void BFS();

int main(void)
{
	int max=0;
	cin>>M>>N>>H;
	
  for(int k=0; k<H;k++)
  {	  
	for(int i=0; i<N;i++)
	{
		for(int j=0; j<M;j++)
		{
				cin>>map[i][j][k];
				if(map[i][j][k] == 1)
					q.push({{i,j},k});
		}
	}	
  }
	BFS();
	
	for(int i=0;i<N;i++)
		for(int j=0; j<M;j++)
		{
		  for(int k=0; k<H;k++)
		  {
			if(map[i][j][k] == 0)
			{
				cout<<-1<<"\n";
				return 0;
			}
			if(map[i][j][k]>max)
				max=map[i][j][k];
		  }
		}
	cout<<max-1<<"\n";

/*
	for(int i=0; i<N; i++)
	{
		for(int j=0;j<M;j++)
			cout<<map[i][j];
		cout<<"\n";
	}
*/


	return 0;
}

void BFS()
{
	int y,x,z;

	while(!q.empty())
	{
		y=q.front().first.first;
		x=q.front().first.second;
		z=q.front().second;
		q.pop();

		int ty,tx,tz;
		for(int i=0; i<6; i++)
		{
			ty=y+dy[i];
			tx=x+dx[i];
			tz=z+dz[i];

		  if(tx == -1 || tx == M || ty == -1 || ty == N || tz == -1 || tz == H)
			  continue;

		  if(map[ty][tx][tz]==0)
		  {
			  q.push({{ty,tx},tz});
			  map[ty][tx][tz] = map[y][x][z]+1;
		  }
		}
	}
}
