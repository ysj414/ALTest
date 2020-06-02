#include<iostream>

#define ZERO 0
#define INF 987654321
#define ENDL "\n"
using namespace std;


int main(void)
{
	int M,N;
	int sum=ZERO;
	int init=ZERO;

	cin>>M>>N;
	if(M==1)
		M++;

	for(int i=M;i<=N;i++)
	{
		int flag=1;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;

			}
		}
		if(flag)
		{
			sum+=i;
			if(!init)
				init=i;
		}
	}
	if(sum==0)
	   	cout<<-1<<ENDL;
	else
	{	   
			cout<<sum<<ENDL;
			cout<<init<<ENDL;
	}
	return 0;
}
