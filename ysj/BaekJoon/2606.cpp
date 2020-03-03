#include<iostream>
#include<queue>
#include<algorithm>


using namespace std;

vector<int> graph[101];
int visit[101]={0,};
int cnt=0;

void DFS(int start);

int main(void)
{

	int vtx,edge;
	int e1,e2;

	cin>>vtx;
	cin>>edge;
	for(int i=0; i<edge; i++)
	{
		cin>>e1>>e2;
		graph[e1].push_back(e2);
		graph[e2].push_back(e1);
	}

	DFS(1);
	cout<<cnt-1<<"\n";
	
	return 0;
}

void DFS(int start)
{
	
	if(visit[start])
		return;

	visit[start]=true;
	cnt++;
//	cout<<start<<" ";
	for(int i=0; i<graph[start].size(); i++)
	{
		int x=graph[start][i];
		DFS(x);
	}

}
