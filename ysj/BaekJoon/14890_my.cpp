#include<iostream>
using namespace std;

int map[100][100];

int main(void)
{
	int N;
	int L;
	int cnt=0;

	cin>>N>>L;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>map[i][j];

	for(int i=0;i<N;i++)
	{
		int x1,x2;
		int flat=1;
		for(int j=0; j<N;j++)
		{
			x1=j;
			int all_flat=1;
			for(int k=x1+1;k<N;k++)
			{
				x2=k;
				if(map[i][x1]!=map[i][x2])
				{
					all_flat=0;
					break;
				}
			}
			cout<<i<<":("<<x1<<","<<x2<<")\n";
			if(!all_flat)
			{
				if((map[i][x1]-map[i][x2])>1 || (map[i][x1]-map[i][x2])<-1)
				{
					cout<<map[i][x1]<<" "<<map[i][x2]<<"1\n";
					flat=0;
					break;
				}
			else
			{
			  int diff=x2-x1;
			  cout<<"diff:"<<diff<<"\n";
			  if(map[i][x1]<map[i][x2])
			  {	  
				if(diff<L)
				{   
					cout<<"2\n";
					flat=0;
					break;
				}
				else
				{
					if(diff % L != 0 && diff %(2*L-1) != 0)
					{
					  cout<<"3\n";
					  flat=0;
					  break;
					}
				}
			  }
			}
			j=x2-1;
			}
			else
				break;
			
		}
		cout<<i<<"th road: "<<flat<<"\n";
		if(flat)
			cnt++;
	}

	for(int i=0;i<N;i++)
	{
		int y1,y2;
		int flat=1;
		for(int j=0;j<N;j++)
		{
			y1=j;
			
			int all_flat=1;
			for(int k=y1+1;k<N;k++)
			{
				y2=k;
				if(map[y1][i]!=map[y2][i])
				{
					all_flat=0;
					break;
				}
			}
			cout<<"("<<y1<<","<<y2<<")\n";
			if(!all_flat)
			{
			if((map[y1][i]-map[y2][i])>1 || (map[y1][i]-map[y2][i])<-1)
			{
				cout<<"1\n";
				flat=0;
				break;
			}
			else
			{
			  int diff=y2-y1;
			  if(map[y1][i]<map[y2][i])
			  {	  
				if(diff<L)
				{
					cout<<"2\n";
					flat=0;
					break;
				}
				else
				{
					if(diff % L != 0 && diff %(2*L-1) != 0)
					{
					  cout<<"3\n";
					  flat=0;
					  break;
					}
				}
			  }
			}
			j=y2-1;
			}
			else
				break;
		}
		
		cout<<i<<"th road: "<<flat<<"\n";
		if(flat)
			cnt++;
	}	


	cout<<cnt<<"\n";

	return 0;
}

