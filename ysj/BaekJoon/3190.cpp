#include<iostream>
#include<queue>

using namespace std;

int map[100][100]={0,};
int N=0;
int K=0;
int L=0;

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
pair <int, char> dir_change[100];
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
	queue<pair<int,int>> snake;
	pair<int,int> head={0,0};
	snake.push(head);

	cin>>L;
	for(int i=0;i<L;i++)
		cin>>dir_change[i].first>>dir_change[i].second;

	int current_time=0;
	int temp_L=0;
	/* initial rotation direction */
	int dir=0;
	while(1)
	{
	  current_time++;
	  int move_y = head.first  + dy[dir];
	  int move_x = head.second + dx[dir];
	  /* move snake */ 
	  if(move_y == -1 || move_y == N || move_x == -1 || move_x == N)
		  break;
	  else if(map[move_y][move_x] == -1)
		  break;
	  else if(map[move_y][move_x] != 1)
	  {
		  pair<int,int> tail=snake.front();
//		  cout<<"(i,j)"<<tail.first<<tail.second<<"\n";
		  snake.pop();
		  map[tail.first][tail.second]=0;
	  }
	  head= {move_y,move_x};
	  snake.push(head);
	  map[move_y][move_x]= -1;
	  
	  /* rotate by input data */	
//	  cout<<temp_L<<" "<<"current_time"<<current_time<<" "<<dir_change[temp_L].first<<" "<<dir_change[temp_L].second<<"\n";
      if(temp_L<L)
	  {		 
	    if(current_time == dir_change[temp_L].first )
	    {
		  if(dir_change[temp_L].second =='L')
		  {
			dir=(dir+3)%4;
		  }
		  else
		  {
			dir=(dir+1)%4; 
		  }

	      temp_L++;		  
	    }	    
	  }

	}
	
  cout<<current_time<<"\n";	

	return 0;
}
