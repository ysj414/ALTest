#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{

	for(int i=0; i<3; i++)
	{
		char buf[10]={0,};
		cin>>buf;
	
		int max=1,t_max=1;
		for(int i=0;i<7;i++)
		{
			if(buf[i] == buf[i+1])
				t_max++;
			else
			{
				if(t_max>max)
					max=t_max;
				t_max=1;
			}
		}

		if(t_max>max)
			max=t_max;

		cout<<max<<"\n";
	}

	return 0;
}
