#include<iostream>

using namespace std;

int main(void)
{

	int max=0;
	int in,out;
	int train=0;

	for(int i=0;i<4;i++)
	{
		cin>>out>>in;
		train-=out;
		train+=in;
		if(train>max)
			max=train;
//		cout<<train<<"\n";
	}
	cout<<max<<"\n";


	return 0;
}
