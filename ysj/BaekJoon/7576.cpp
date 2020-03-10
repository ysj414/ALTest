#include<iostream>
#include<queue>

using namespace std;

int N,M;
int map[1000][1000];
queue<pair<int,int>> q;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};


void BFS();

int main(void)
{
	int max=0;
	cin>>M>>N;
	
	for(int i=0; i<N;i++)
		for(int j=0; j<M;j++)
		{
			cin>>map[i][j];
			if(map[i][j] == 1)
				q.push({i,j});
		}	
	BFS();
	
	for(int i=0;i<N;i++)
		for(int j=0; j<M;j++)
		{
			if(map[i][j] == 0)
			{
				cout<<-1<<"\n";
				return 0;
			}
			if(map[i][j]>max)
				max=map[i][j];
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
	int y,x;

	while(!q.empty())
	{
		y=q.front().first;
		x=q.front().second;
		q.pop();

		int ty,tx;
		for(int i=0; i<4; i++)
		{
			ty=y+dy[i];
			tx=x+dx[i];
		  if(tx == -1 || tx == M || ty == -1 || ty == N)
			  continue;

		  if(map[ty][tx]==0)
		  {
			  q.push({ty,tx});
			  map[ty][tx] = map[y][x]+1;
		  }
		}
	}
}
