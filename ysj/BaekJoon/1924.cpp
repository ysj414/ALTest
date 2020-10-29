#include<iostream>

using namespace std;


enum year
{
	SUN,
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT
};

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

char YEAR[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};


int main(void)
{

	int x,y;

	cin>>x>>y;
	
	int mon=y;
	for(int i=1;i<x;i++)
		mon+=month[i];
	
	cout<<YEAR[mon%7]<<"\n";
}
