#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

queue< pair<pair<int,int>,int> > q;
int map[1000][1000];
int visit[1000][1000][2];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N,M;

int BFS(void);

int main(void)
{
	cin>>N>>M;

	for(int i=0; i<N;i++)
	{
		for(int j=0; j<M;j++)
			scanf("%1d",&map[i][j]);
	}

	cout<<BFS()<<"\n";

	return 0;
}

int BFS(void)
{
	q.push({{0,0},1});
	visit[0][0][1]=true;

	while(!q.empty())
	{
	 int y=q.front().first.first;
	 int x=q.front().first.second;
	 int block = q.front().second;
	 q.pop();

	 if( y == N-1 && x == M-1)
		 return visit[y][x][block];

		for(int i=0; i<4;i++)
		{
			int ty=y+dy[i];
			int tx=x+dx[i];
			if(ty == -1 || ty == N || tx == -1 || tx == M)
				continue;
	
			if(map[ty][tx] == 1 && block == 1)
			{
				visit[ty][tx][block-1]= visit[y][x][block]+1;
				q.push({{ty,tx},block-1});
			}
			else if(map[ty][tx] == 0 && visit[ty][tx][block] == 0)
			{
		        visit[ty][tx][block] = visit[y][x][block]+1;
				q.push({{ty,tx},block});
			}
		}

	}
	return -1;
}
