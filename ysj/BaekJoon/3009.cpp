#include<iostream>

using namespace std;


int main(void)
{
	int a[3][2];
	int ans1,ans2;

	for(int i=0;i<3;i++)
		cin>>a[i][0]>>a[i][1];

	int temp1=a[0][0],temp2=a[0][1];
	int sameon1=false,sameon2=false;
	for(int i=1;i<3;i++)
	{
		if(temp1 == a[i][0])
			sameon1=true;
		else
			ans1=a[i][0];
		if(temp2 == a[i][1])
			sameon2=true;
		else
			ans2=a[i][1];
	}

	if(sameon1)
	{
		cout<<ans1<<" ";
		if(sameon2)
			cout<<ans2<<"\n";
		else
			cout<<temp2<<"\n";
	}
	else
	{
		cout<<temp1<<" ";
		if(sameon2)
			cout<<ans2<<"\n";
		else
			cout<<temp2<<"\n";
	}

	return 0;
}
