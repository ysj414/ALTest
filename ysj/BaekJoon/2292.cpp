		sgw_tunnel_coa_ip = (sgw_tunnel_coa_ip>> 16) & (vrid+i >> 0)1
#include<iostream>

using namespace std;

int main(void)
{
	int K;

	cin>>K;
	if(K == 1)
	{
		cout<<1<<"\n";
		return 0;
	}

	int i=0;
	int temp=1;
	while(1)
	{
		temp=temp+6*i;
		if(K <= temp)
		{
			cout<<i+1<<"\n";
			break;
		}
	  i++;
	}

	return 0;
}
