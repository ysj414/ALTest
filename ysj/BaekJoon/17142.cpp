#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int map[55][55];
int visit[55][55]={0,};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

queue<pair<int,int>> q;

pair<int,int> vir[12];
vector<int> pr;
int N,M,K;

int mkpair(int step);
void BFS(void);
void print(void);
int main(void)
{
	K=0;
	cin>>N>>M;
	int no_space=0;
	for(int i=0; i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==2)
			{
				vir[K].first=i;
				vir[K].second=j;
				K++;
			}
			else if(map[i][j]==0)
				no_space++;
		}
	}
	if(no_space==0)
	{
		cout<<0<<"\n";
		return 0;
	}
	else
	{
	int result=mkpair(1);
	if(result>=99999)
	   cout<<-1<<"\n";
	else
	   cout<<result<<"\n";
	}
	return 0;
}

int mkpair(int step)
{
	int res=999999;
	for(int i=0;i<M;i++)
		pr.push_back(1);
	for(int i=M;i<K;i++)
		pr.push_back(0);

	sort(pr.begin(),pr.end());
	
	do{
         for(int i=0;i<K;i++)
	     {
		     if(pr[i]==true)
			     q.push({vir[i].first,vir[i].second});
			 else
				 map[vir[i].first][vir[i].second]=0;
	     }
	BFS();
		 for(int i=0;i<K;i++)
		 {
			 if(pr[i]==false)
				 map[vir[i].first][vir[i].second]=2;
		 }
//print();
    int local_max=-1;
    for(int i=0;i<N;i++)
    {
	    for(int j=0;j<N;j++)
	    {
		    if(map[i][j]==0 && visit[i][j]==0)
			{
			    local_max=99999;
				break;
			}
		    if(map[i][j]==0 && visit[i][j]>local_max)
		    {
			    local_max=visit[i][j];
		    }
	    }
    }
	if(local_max<res)
		res=local_max;

	memset(visit,0,sizeof(visit));
	}while(next_permutation(pr.begin(),pr.end()));
   return res;
}

void BFS(void)
{
	while(!q.empty())
	{  int y,x;
	   y=q.front().first;
	   x=q.front().second;
	   q.pop();
	   for(int i=0;i<4;i++)
	   {
	     int ty,tx;
	     ty=y+dy[i];
	     tx=x+dx[i];
	     if(ty==-1 || ty == N || tx == -1 |tx == N)
	     	continue;
	     if(map[ty][tx]==0 && visit[ty][tx]==0)
	     {
	     	visit[ty][tx]=visit[y][x]+1;
		q.push({ty,tx});
	     }
	   }
	}
}


void print(void)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<map[i][j]<<" ";
		cout<<"\n";
	}

	cout<<"visit \n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<visit[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
