#include<iostream>
#define MAX_NUM	(100000+5)

using namespace std;

int N,K,L;
int man[MAX_NUM]={0,};

int recursive_tournament(int count, int cur_num);
int main(void)
{
	cin>>N>>K>>L;
	if(K>L)
	{
		int temp=K;
		K=L;
		L=temp;
	}

	man[K]=1;
	man[L]=2;
	
	if(N == 1)
	{
		cout<<-1<<"\n";
		return 0;
	}

	int result=recursive_tournament(1,N);
	cout<<result<<"\n";


	return 0;
}

int recursive_tournament(int count, int cur_num)
{
	if(cur_num%2 == 1)
		cur_num++;


//	for(int i=1; i<=cur_num;i++)
//		cout<<"("<<i<<","<<man[i]<<")";
//	cout<<"\n";


	for(int i=1;i<=cur_num;i=i+2)
	{
		if(man[i] >= 1 && man[i+1] >= 1)
			return count;
		else if(man[i] >= 1 && man[i+1] < 1)
		{
			if(man[i] == 1)
			{
				man[(i+1)/2]=1;
				if( (i+1)/2 != i)
					man[i]=0;
			}
			else
			{
				man[(i+1)/2]=2;
				if( (i+1)/2 != i)
					man[i+1]=0;
			}
		}
		else if(man[i] < 1 && man[i+1] >=1)
		{
			if(man[i+1] == 1)
			{
				man[(i+1)/2]=1;
				if((i+1)/2 != (i+1))
					man[i+1]=0;
			}
			else
			{
				man[(i+1)/2]=2;
				if((i+1)/2 != (i+1))
					man[i+1]=0;
			}
		}
	}
	return recursive_tournament(count+1, cur_num/2);
}

	
