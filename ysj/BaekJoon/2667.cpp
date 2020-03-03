#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[26][26]={0,};
int visit[26][26]={0,};
int total=0;
int visit_num[26*26];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};

void DFS(int y, int x);

int main(void)
{
	int N;
	char buf[26];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>buf;
		for(int j=0;j<N;j++)
		{
			map[i][j]=(int)(buf[j]-'0');
		}
	}
/*
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<map[i][j]<<" ";
	cout<<"\n";
	}
*/

	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(map[i][j]!=0 && visit[i][j]==0)
			{
				total++;
				DFS(i,j);
			}
		}	
/*	
	cout<<"Map\n";
	for(int i=0; i<N;i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Visit\n";
	for(int i=0; i<N;i++)
	{
		for(int j=0; j<N;j++)
		{
			cout<<visit[i][j]<<" ";
		}
		cout<<"\n";
	}
*/

	sort(visit_num+1,visit_num+1+total);
	cout<<total<<"\n";
	for(int i=1; i<=total;i++)
		cout<<visit_num[i]<<"\n";


	return 0;
}

void DFS(int y, int x)
{
	int tx,ty;

	if(visit[y][x])
		return;
	
	visit[y][x]=true;
	visit_num[total]++;

	for(int i=0; i<4;i++)
	{
		ty=y+dy[i];
		tx=x+dx[i];
		if(ty == -1 || ty == 26 || tx==-1 || tx==26)
			continue;

		if(map[ty][tx]==1 && visit[ty][tx]==0)
			DFS(ty,tx);
	}
}
