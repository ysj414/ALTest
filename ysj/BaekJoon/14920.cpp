#include<iostream>

using namespace std;

int main(void)
{

	int N;

	cin>>N;

	int count=1;
	while(N != 1)
	{
		if(N % 2 == 0)
			N=N/2;
		else
			N=3*N+1;
		count++;
	}
	cout<<count<<"\n";


	return 0;
}
