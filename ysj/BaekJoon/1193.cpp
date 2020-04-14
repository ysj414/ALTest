#include<iostream>

using namespace std;


int main(void)
{
	int N;
	
	cin>>N;	
	int k=1;
	while(1)
	{
		if(N<=k*(k+1)/2)
			break;
		else
			k++;
	}
	int K=k*(k+1)/2;

	int i,j;
	if(k%2==0)
	{
		i=k;
		j=1;
		while((K-N)>0)
		{
			i--;
			j++;
			N++;
		}
	}
	else
	{
		i=1;
		j=k;
		while((K-N)>0)
		{
			i++;
			j--;
			N++;
		}
	}
	cout<<i<<"/"<<j<<"\n";

	return 0;
}
