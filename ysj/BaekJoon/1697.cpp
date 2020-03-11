#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

queue<int> line;

int N,K;
void BFS(int pos);
int step=0;

int main(void)
{
	cin>>N>>K;

	BFS(N);
	cout<<"\n\n";
	cout<<step<<"\n";
	return 0;
}

void BFS(int src)
{
	int dst;
	int back,front,zump;
	line.push(src);

	cout<<"push first src: "<<src<<"\n";
	
	while(!line.empty())
	{
	  dst=line.front();
	  cout<<dst<<" ";
	  line.pop();

	  if(dst == K)
		  break;

	  back=dst-1;
	  front=dst+1;
	  zump=dst*2;



	}

}
