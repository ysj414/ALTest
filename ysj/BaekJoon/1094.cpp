#include<iostream>

using namespace std;

int main(void)
{
	int x;
	int X[15]={64,};
	int cnt=0;
	int sum;
	int xsum;
	cin>>x;

	if(x==64)
	{
		cout<<1<<"\n";
		return 0;
	}
	do
	{
		X[cnt]=X[cnt]/2;
		X[cnt+1]=X[cnt];
		cnt++;

		sum=0;
		for(int i=0;i<=cnt;i++)
			sum+=X[i];
		xsum=sum-X[cnt];
//	cout<<"xsum:"<<xsum<<"\n";
		if(xsum>=x)
		{
			X[cnt]=0;
			cnt--;
		}
		else
			xsum+=X[cnt];
//		for(int i=0;i<=cnt;i++)
//			cout<<X[i]<<" ";
//		cout<<"\n";
	}while(xsum>x);
	cout<<cnt+1<<"\n";

	return 0;
}
