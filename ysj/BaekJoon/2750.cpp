#include<iostream>
#define INF 987654321
using namespace std;


int arr[1001];

int main(void)
{

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=0;i<n;i++)
	{
		int min=arr[i];
		int min_idx=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<min)
			{
				min_idx=j;
				min=arr[j];
			}

		}
		int temp=arr[i];
		arr[i]=arr[min_idx];
		arr[min_idx]=temp;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"\n";


	return 0;
}
