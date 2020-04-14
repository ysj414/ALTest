#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int T[15];
int P[15];
int N;
int max_profit=0;

int DP(int index)
{
	if(index == N)
		return 0;

	if(T[index]<=N-index)
	{
		return max(DP(index+T[index])+P[index],DP(index+1));
	}
	else
		return DP(index+1);
}

int main(void)
{
	cin>>N;

	for(int i=0; i<N;i++)
		cin>>T[i]>>P[i];

    max_profit=DP(0);

	
	cout<<max_profit<<"\n";
		

	return 0;
}

