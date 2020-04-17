#include<iostream>
#include<queue>
using namespace std;

int map[50][50]={0,};
int visit[50][50]={0,};

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
queue<pair<int,int>> q;
int N,M,dir;
void BFS(void);
int size =0;

int main(void)
{
	int y,x;
	cin>>N>>M;
	cin>>y>>x>>dir;
	
	q.push({y,x});

	for(int i=0;i<N;i++)
	    for(int j=0; j<M;j++)
	    	cin>>map[i][j];
	BFS();

	cout<<size<<"\n";

	return 0;
}

void BFS(void)
{
	int cnt=0;
	
	while(!q.empty())
	{
		int y=q.front().first;
		int x=q.front().second;
		visit[y][x]=true;
		q.pop();
		size++;
	 int t_dir=dir;
	 for(int i=0; i < 4; i++)
	 {
		t_dir=(t_dir+3)%4;
		int ty=y + dy[t_dir];
		int tx=x + dx[t_dir];
		if(ty == -1 || ty == N || tx == -1 || tx == M)
		{  
			cnt++;
			continue;
		}
		if(map[ty][tx] == 0 && visit[ty][tx] == 0)
		{
			q.push({ty,tx});
			dir=t_dir;
			cnt=0;
			break;
		}
		else
			cnt++;
	 }
	 if(cnt == 4)
	 {
		int temp_dir= (dir+2)%4;

		int ty=y + dy[temp_dir];
		int tx=x + dx[temp_dir];

		if(ty == -1 || ty == N || tx == -1 || tx == M)  
			break;

		if(map[ty][tx] == 1)
			break;	
		else
		{
		  q.push({ty,tx});
		  size--;
		  cnt=0;
		}		
	 }
	}
}
