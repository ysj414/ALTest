#include<iostream>

using namespace std;


int main(void)
{

	int day, car,count=0;

	cin>>day;
	for(int i = 0; i<5; i++)
	{
		cin>>car;
		if(car == day)
			count++;
	}
	cout<<count<<"\n";


	return 0;
}
