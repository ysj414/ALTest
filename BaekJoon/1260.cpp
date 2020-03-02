#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>

using namespace std;

int visit[1001]={0,};
vector<int> graph[1001];
queue<int> q;

void DFS(int start);
void BFS(int start);

int main(void)
{
	int vtx,edge,st;
	int e1,e2;
	memset(graph,0,sizeof(graph));
	cin>>vtx>>edge>>st;
	for(int i=0; i<edge; i++)
	{
		cin>>e1>>e2;
		graph[e1].push_back(e2);
		graph[e2].push_back(e1);

	}

	for(int i=1; i<=vtx;i++)
		sort(graph[i].begin(),graph[i].end());
/*
	for(int i=0; i<=vtx;i++)
	{
		cout<<"graph"<<i<<"\n";
		for(int j=0; j<graph[i].size() ;j++)
			cout<<graph[i][j]<<" ";
		cout<<"\n";
	}
    cout<<"\n";	
*/
	
	DFS(st);
	cout<<"\n";
	memset(visit,0,sizeof(visit));
	BFS(st);
	cout<<"\n";






	return 0;
}

void DFS(int start)
{
	if(visit[start])
		return;

	visit[start]=true;
	cout<<start<<" ";
	for(int i=0;i<graph[start].size();i++)
	{
		int x= graph[start][i];
		DFS(x);
	}

}

void BFS(int start)
{

	q.push(start);
	visit[start]=true;

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout<<x<<" ";
		
		for(int i=0; i<graph[x].size();i++)
		{	
			int y = graph[x][i];
			if(!visit[y])
			{	
				q.push(y);
				visit[y]=true;
			}
		}
	}


}
