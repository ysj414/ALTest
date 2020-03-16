#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

queue<pair<int,int>> line;

int N,K;
void BFS(int src);
int visit[MAX]={0,};

int main(void)
{
	cin>>N>>K;

	BFS(N);
	cout<<line.front().second<<"\n";
	return 0;
}

void BFS(int src)
{
	int dst;
	int depth=0;
	int back,front,zump;
	line.push({src,depth});
	visit[src]=true;
		
	while(!line.empty())
	{
	  dst=line.front().first;
	  depth=line.front().second;

	  if(dst == K)
		  break;
	  line.pop();

	  back=dst-1;
	  front=dst+1;
	  zump=dst*2;

	  if(back>=0 && !visit[back])
	  {
			  line.push({back,depth+1});
			  visit[back]=true; 
	  }
	  if(front<=MAX && !visit[front] )
	  {
			  line.push({front,depth+1});
			  visit[front]=true;
	  }
	  if(zump<=MAX && !visit[zump])
	  {
			  line.push({zump,depth+1});
			  visit[zump]=true;
	  }
	}
}
