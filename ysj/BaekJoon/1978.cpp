#include<iostream>

using namespace std;

int arr[101];
int main(void)
{
	int n;
	cin>>n;

	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		int flag=1;
		if(arr[i] == 1)
			flag=0;
		for(int j=2;j<arr[i];j++)
		{

			if(arr[i]%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			cnt++;
	}
	cout<<cnt<<"\n";



	return 0;
}
