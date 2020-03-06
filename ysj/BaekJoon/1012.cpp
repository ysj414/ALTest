#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int map[50][50]={0,};
int visit[50][50]={0,};
int total=0;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void DFS(int y, int x);

int main(void)
{
	int T;
	int N,M,K;
	int y,x;

	cin>>T;
	for(int i=0; i<T; i++)
	{
		cin>>M>>N>>K;
		for(int j=0; j<K; j++)
		{
			cin>>x>>y;
			map[y][x]=true;
		}
		for(int k=0; k<N ; k++)
		{
			for(int l=0; l<M;l++)
			{
				if(map[k][l] == true && visit[k][l] == false )
				{
					DFS(k,l);
					total++;
				}
			}
		}
		cout<<total<<"\n";
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		total=0;
	}

	return 0;
}

void DFS(int y, int x)
{
	int ty,tx;

	if(visit[y][x])
		return;
	visit[y][x]=true;

	for(int i=0 ; i<4 ; i++)
	{
		ty=y+dy[i];
		tx=x+dx[i];
		
		if(ty== -1 || ty == 50 || tx== -1 || tx==50)
			continue;

		if(map[ty][tx]==1 && visit[ty][tx] ==0)
			DFS(ty,tx);
	}
}
