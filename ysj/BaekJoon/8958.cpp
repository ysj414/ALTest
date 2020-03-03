#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{

	char ox[80];
	int N;
	int answer;
	cin>>N;
	for(int i=0; i< N; i++)
	{
		cin>>ox;
		answer=0;
		int len = strlen(ox);
		for(int j=0; j<len; j++)
		{
			if(ox[j]== 'O')
			{
				int cnt=1;
				for(int k=j+1; k<len; k++)
				{
					if(ox[k] == 'X')
						break;
					cnt++;
				}
				answer+=cnt*(cnt+1)/2;
				j=j+(cnt-1);
			}
		}
		cout<<answer<<"\n";
		memset(ox,0,sizeof(ox));
	}



	return 0;
}
