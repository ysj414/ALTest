#include<iostream>

using namespace std;


int main(void)
{
	int a,b,c;
	int e,f;
	int answer=-50;

	cin>>a>>b>>c;
	cin>>e>>f;
	
	if(a>b)
	{
		if(c>b)
			answer+=b;
		else
			answer+=c;
	}
	else
	{
		if(c>a)
			answer+=a;
		else
			answer+=c;
	}

	if(e>f)
		answer+=f;
	else
		answer+=e;

	cout<<answer<<"\n";



}
