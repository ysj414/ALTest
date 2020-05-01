#include<iostream>

using namespace std;

int main(void)
{
	int T,H,W,N;

	cin>>T;
	while(T--)
	{
	cin>>H>>W>>N;
	
	int floor=N%H*100;
	int ho;
	if(floor == 0)
	{
		floor=H*100;
		ho=N/H;
	}
	else
	   ho=N/H+1;
	
	int ans=floor+ho;
	cout<<ans<<"\n";

	}


	return 0;

}
