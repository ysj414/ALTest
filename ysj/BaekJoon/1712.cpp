#include<iostream>

using namespace std;

int main(void)
{
	long A,B,C;
	long long D;
	cin>>A>>B>>C;
	
	if(C-B<=0)
	{
		cout<<-1<<"\n";
		return 0;
	}
	D=A/(C-B);
	cout<<D+1<<"\n";

	return 0;
}
