#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		for(int k=0;k<(i%n);k++)
			cout<<" ";
		for(int j=2*i; j<2*n-1;j++)
			cout<<"*";
		cout<<"\n";
	}
	for(int i=1;i<n;i++)
	{
		for(int k=(n-i)-1;k>0;k--)
			cout<<" ";
		for(int j=n-2*i-1;j<n;j++)
			cout<<"*";
		cout<<"\n";
	}	


	return 0;
}
