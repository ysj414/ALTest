#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int city[55][55];
int visit[55][55]={0,};
pair<int,int> chic[13];

queue<pair<int,int>> q;
int Pair[15];
vector<int> use;
int MIN=9999999;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int N,M,K;

void mkpair(void);
int BFS(void);
int main(void)
{
	cin>>N>>M;
	K=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>city[i][j];
			if(city[i][j]==2)
			{
				chic[K].first=i;
				chic[K].second=j;
				K++;
			}
		}
	}

	mkpair();
	cout<<MIN<<"\n";
}
void mkpair(void)
{
   int tmp_min=0;
   for(int i=0;i<K;i++)
   {	 if(i<M)
	   use.push_back(true);
	 else
           use.push_back(false);
   }
   sort(use.begin(),use.end());

     do{
//	  for(int c=0;c<K;c++)
//		  cout<<use[c]<<" ";
//	  cout<<"\n";
	  for(int p=0;p<K;p++)
	  {

		if(use[p]==true)
		{
			q.push({chic[p].first,chic[p].second});
//			cout<<"(i-th,i,j)"<<p<<" "<<chic[p].first<<","<<chic[p].second<<"\n";
		}
	  }
	  for(int i=0;i<K;i++)
	  {
		  if(use[i]==false)
		     city[chic[i].first][chic[i].second]=0;
	  }
//	  cout<<"\n";
//	  for(int i=0;i<N;i++)
//	  {
//		  for(int j=0;j<N;j++)
//		  	cout<<city[i][j]<<" ";
//		  cout<<"\n";
//	  }
	  tmp_min=BFS();

	  for(int i=0;i<K;i++)
	  {
		  if(use[i]==false)
		  {
			city[chic[i].first][chic[i].second]=2;
		  }
	  }

//	  for(int i=0;i<N;i++)
//	  {
//		  for(int j=0;j<N;j++)
//		  	cout<<city[i][j]<<" ";
//		  cout<<"\n";
//	  }
	  memset(visit,0,sizeof(visit));

	  if(tmp_min<MIN)
		  MIN=tmp_min;
     }while(next_permutation(use.begin(),use.end()));
	  
}
int BFS(void)
{
	int chicken_load=0;
	
	while(!q.empty())
	{
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int ty=y+dy[i];
			int tx=x+dx[i];
			if(ty==-1 || ty==N ||tx==-1 ||tx==N)
				continue;
			if(city[ty][tx]==1)
			{
				if(visit[ty][tx] == 0)
				{
					visit[ty][tx]=visit[y][x]+1;
					q.push({ty,tx});
				}
				else
				{
					if((visit[y][x]+1)<visit[ty][tx])
					    visit[ty][tx]==visit[y][x]+1;
				}
			}
			if(visit[ty][tx]==0 && city[ty][tx]==0)
			{
				visit[ty][tx]=visit[y][x]+1;
				q.push({ty,tx});
			}

		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(city[i][j] ==1)
				chicken_load+=visit[i][j];
//		   cout<<visit[i][j]<<" ";
		}
//		  cout<<"\n";
	}
//	cout<<"local min: "<<chicken_load<<"\n";	
	return chicken_load;
}
