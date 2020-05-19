#include<iostream>
#include<queue>

using namespace std;

int arr[105];
int main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,x;
		int cnt=0;
		queue<int> q;
		cin>>n>>x;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			q.push(i);
		}
		int flag=1;
		while(flag)
		{
		int high=0;
		for(int i=0;i<n;i++)
			if(arr[i]>=high)
				high=arr[i];
		while(1)
		{
		
			int idx=q.front();
			q.pop();
			if(arr[idx] >= high)
			{
				arr[idx]=0;
				cnt++;
				if(idx == x)
					flag=0;
				break;
			}
			else
			{
				q.push(idx);
			}
		}
		}
		cout<<cnt<<"\n";
	}

	return 0;
}

