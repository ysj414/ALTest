#include<iostream>
#include<queue>

using namespace std;


queue<int> q;


int main(void)
{
	
	int N;
	cin>>N;

	for(int i=1;i<=N;i++)
		q.push(i);

	while(q.size()>1)
	{
		q.pop();
		int back=q.front();
		q.pop();
		q.push(back);
	}
	cout<<q.front()<<"\n";
}
