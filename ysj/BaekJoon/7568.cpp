#include<iostream>

using namespace std;

int man[55][3];
int N;

int main(void)
{

	cin>>N;

	for(int i=0;i<N;i++)
		cin>>man[i][0]>>man[i][1]; // man[i][0] : weight, man[i][1] : height
	for(int i=0;i<N;i++)
	{
		man[i][2]=1;          // initial rank is 1
		
		for(int j=0;j<N;j++)
		{
			if(i == j)
				continue;
			if( (man[i][0] < man[j][0]) && (man[i][1] < man[j][1]) )
				man[i][2]++;
		}
	}

	for(int i=0;i<N;i++)
		cout<<man[i][2]<<" ";

	return 0;
}

