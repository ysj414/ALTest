#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N,M;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int map[8][8];
int visit[8][8]={0,};
int max_area=0;
queue<pair<int,int>> q;

void BFS(void);

int main(void)
{
	cin>>N>>M;


	for(int i=0; i<N;i++)
	    for(int j=0; j<M;j++)
		cin>>map[i][j];


	int y1,y2,y3,x1,x2,x3;

	for(int i=0;i<N*M;i++)
	{
		y1=i/M;
		x1=i%M;	
	  for(int j=i+1; j<N*M;j++)
	  {	
		  y2=j/M;
		  x2=j%M;
		for(int k=j+1;k<N*M;k++)
		{
			y3=k/M;
			x3=k%M;	
			if(map[y1][x1] == 0 && map[y2][x2] == 0 && map[y3][x3] == 0)
			{
				map[y1][x1]=1;
				map[y2][x2]=1;
				map[y3][x3]=1;
				for(int n=0; n<N;n++)
				{
					for(int m=0; m<M;m++)
					{
						if(map[n][m]==2)
							q.push({n,m});
						else if(map[n][m]==1)
							visit[n][m]= 1;
					}
				}
				BFS();
				memset(visit,0,sizeof(visit));
				map[y1][x1]=0;
				map[y2][x2]=0;
				map[y3][x3]=0;
			}
		}
	   }			
	}		
		
	


	cout<<max_area<<"\n";

	return 0;
}

void BFS(void)
{
	int ty,tx;
	int y,x;
	int temp_area=0;

	while(!q.empty())
	{
		y=q.front().first;
		x=q.front().second;
		visit[y][x]=true;
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			ty=y+dy[i];
			tx=x+dx[i];
			if(ty == -1 || ty == N || tx == -1 || tx ==M)
				continue;

			if(map[ty][tx] == 0 && visit[ty][tx] == 0)
			{
				q.push({ty,tx});
			}
		}

	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{	
			if(visit[i][j] == 0)
				temp_area++;
		}
	}

	if(temp_area>max_area)
		max_area=temp_area;
}
