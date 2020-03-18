#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

queue<pair<int,int>> q;
int map[1000][1000];
int visit[1000][1000]={0,};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N,M;

void BFS(void);

int main(void)
{
	queue<pair<int,int>> wall;
	int a,b;
	int min=99999;
	cin>>N>>M;


	for(int i=0; i<N;i++)
	{
		for(int j=0; j<M;j++)
		{
			scanf("%1d",&map[i][j]);
			if(map[i][j] == 1)
				wall.push({i,j});
		}
	}

	BFS();

	if(visit[N-1][M-1] != 0)
		min=visit[N-1][M-1];

//	cout<<"no wall crash:\n";
//	cout<<min<<"\n";
	memset(visit,0,sizeof(visit));

	while(!wall.empty())
	{
	  a=wall.front().first;
	  b=wall.front().second;
	  map[a][b]=0;
	  BFS();
//	  cout<<"wall(y,x):"<<a+1<<b+1<<"\n";
//	  cout<<visit[N-1][M-1]<<"\n";
	  if(visit[N-1][M-1] != 0)
	  { 
	  if(min>visit[N-1][M-1])
		  min=visit[N-1][M-1];
	  }
	  memset(visit,0,sizeof(visit));
	  map[a][b]=1;
	  wall.pop();
	}

	if(min==99999)
		cout<<-1<<"\n";
	else
		cout<<min<<"\n";

	return 0;
}

void BFS(void)
{
	q.push({0,0});
	visit[0][0]=true;

	while(!q.empty())
	{
	 int y=q.front().first;
	 int x=q.front().second;
		q.pop();

		for(int i=0; i<4;i++)
		{
			int ty=y+dy[i];
			int tx=x+dx[i];
			if(ty == -1 || ty == N || tx == -1 || tx == M)
				continue;
			if(visit[ty][tx]==0 && map[ty][tx] == 0)
			{
				q.push({ty,tx});
				visit[ty][tx]=visit[y][x]+1;
			}
		}

	}
}
