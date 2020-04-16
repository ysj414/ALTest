#include<iostream>

using namespace std;

int main(void)
{

	int V,B,A;

	cin>>A>>B>>V;

	int speed=A-B;
	V=V-A;
	int day=V/speed;
	if(V%speed == 0)
		cout<<day+1<<"\n";
	else
		cout<<day+2<<"\n";

	return 0;
}

