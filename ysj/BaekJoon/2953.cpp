#include<iostream>

using namespace std;

int main(void)
{

	int max = 0;
	int index;
	for(int i=0;i<5;i++)
	{
		int sum=0;
		for(int j=0;j<4;j++)
		{
			int num;
			cin>>num;
			sum+=num;
		}
		if(sum>max)
		{
			max = sum;
			index = i;
		}
	}
	cout<<++index<<" "<<max<<"\n";

	return 0;
}
