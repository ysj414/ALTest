#include<iostream>
#include<cstring>


using namespace std;


int main(void)
{
	char buf[5][16]={0,};
	
	for(int i = 0; i<5; i++)
		cin>>buf[i];
	
	for(int i = 0; i<15;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(buf[j][i] == 0)
				continue;
			cout<<buf[j][i];
		}
	}
	cout<<"\n";



	return 0;
}
