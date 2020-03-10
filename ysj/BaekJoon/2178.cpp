#include<iostream>
#include<queue>
using namespace std;


int map[100][100];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N=0;
int M=0;
queue<pair<int,int>> q;
void BFS(int y,int x);
int main(void)
{
	cin>>N>>M;
	for(int i=0; i<N;i++)
		for(int j=0; j<M;j++)
			scanf("%1d",&map[i][j]);
/*	
	for(int i=0; i<N;i++)
		for(int j=0; j<M;j++)
			cout<<map[i][j]<<" ";
*/

	BFS(0,0);
	cout<<map[N-1][M-1]<<"\n";

	return 0;
}

void BFS(int y,int x)
{
	q.push({y,x});


	while(!q.empty())
	{
		y=q.front().first;
		x=q.front().second;
		q.pop();
	
		int tx,ty;
		for(int i=0; i<4; i++)
		{
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx == -1 || tx == M || ty == -1 || ty == N)
				continue;

			if(map[ty][tx]==1)
			{
				q.push({ty,tx});
				map[ty][tx]=map[y][x]+1;
				
			}

		}
	}
}
