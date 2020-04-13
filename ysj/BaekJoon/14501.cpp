#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int T[15];
int P[15];
int N;
int max_profit=0;

int DP(int index, int capacity)
{
	if(index >= N-1)
	        return 0;
	
	if(T[index]<=capacity)
		return max((DP(index+T[index],capacity-T[index])+P[index]),DP(index+1,capacity));
	else
		return DP(index+1,capacity);
}	

int main(void)
{
	cin>>N;

	for(int i=0; i<N;i++)
		cin>>T[i]>>P[i];
	
	max_profit=DP(0,N);
	
	cout<<max_profit<<"\n";
		

	return 0;
}

