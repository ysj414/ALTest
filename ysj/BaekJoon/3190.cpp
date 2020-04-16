
#include<iostream>
#include<queue>

using namespace std;

int map[100][100]={0,};
int N=0;
int K=0;
int L=0;
int time[100];
char rot[100];

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int main(void)
{
	cin>>N;
	cin>>K;
	for(int i=0;i<K;i++)
	{
		int n,m;
		cin>>n>>m;
		map[n-1][m-1]=1;
	}
	int head_y,head_x;
	head_y=0;
	head_x=0;
	map[head_y][head_x]=3;
	int tail_y,tail_x;
	tail_y=0;
	tail_x=0;

	map[0][0]=3;

	cin>>L;
	for(int i=0;i<L;i++)
		cin>>time[i]>>rot[i];

	int current_time=0;
	int temp_L=0;
	/* initial rotation direction */
	int move_y=0;
	int move_x=1;
	while(1)
	{
	  /* rotate by input data */	
          if(temp_L<=L)
	  {		 
	    if(current_time == time[temp_L])
	    {

		
	      temp_L++;
	    }

	    
	  }
	 /* move snake */
	 map[head_y][head_x]--;
	 head_y+=move_y;
	 head_x+=move_x;
	 if(head_y == -1 || head_y == N || head_x == -1 || head_x == N)
		 break;
	 if(map[head_y][head_x] == 1)
		 map[head_y][head_x]=3;
	 else if(map[head_y][head_x] >=2)
		 break;
	 else if(map[head_y][head_x] == 0)
	 {

	 }	 


		

	   current_time++;
	}
	
	

	return 0;
}
