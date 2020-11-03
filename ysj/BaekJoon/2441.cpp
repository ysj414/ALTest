#include<iostream>

using namespace std;

int main(void)
{

	int N;
	cin>>N;
	for(int i=N; i>0; i--)
	{
		for(int j=i;j<N; j++)
			cout<<" ";
		for(int k=1;k<=i;k++)
			cout<<"*";
		cout<<"\n";
	}




	return 0;
}
