#include<iostream>
using namespace std;

int main(void)
{
	int a,b;


	cin>>a>>b;

	if(a>0)
	{
		if(b>0)
			cout<<1<<"\n";
		else
			cout<<4<<"\n";
	}
	else
	{
		if(b>0)
			cout<<2<<"\n";
		else
			cout<<3<<"\n";
	}


	return 0;
	
}
