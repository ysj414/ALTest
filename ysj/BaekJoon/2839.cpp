#include<iostream>

using namespace std;

int main(void)
{
	int N;
	int cnt=0;
	int div;
	int mod;
	cin>>N;

	int TN=N;

	while(TN>=3)
	{
		div=TN/5;
		mod=TN%5;
		if(mod == 0)
		{
			cnt+=div;
			cout<<cnt<<"\n";
			return 0;
		}
		TN-=3;
		cnt++;
	}
	div=N/3;
	mod=N%3;
	if(mod == 0)
	  cout<<div<<"\n";
	else
	  cout<<-1<<"\n";

	return 0;
}
