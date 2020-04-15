#include<iostream>

using namespace std;

int map[50][50];

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int main(void)
{
	int x,y,dir;
	int N,M;

	cin>>N>>M;
	cin>>y>>x>>dir;
	
	map[y][x]=2;

	for(int i=0;i<N;i++)
	    for(int j=0; j<M;j++)
	    	cin>>map[i][j];

	int check_pos=0;
	int dir_pos=0;

	while(1)
	{
	 // already cleaned or enclosed by wall
	 if(dir_pos==4)
	 {
	 int yy[4];
	 int xx[4];
	 for(int i=0; i<4; i++)
	 {
		 yy[i]=y+dy[i];
		 xx[i]=x+dx[i];
		 if(yy[i] == -1 || yy[i] == N || xx[i] == -1 || xx[i] == M)
		 {
			 check_pos++;
			 continue;
		 }
		 if(map[yy[i]][xx[i]] == 1)
			 check_pos++;
		 else if(map[yy[i]][xx[i]] == 2)
		 {
			 if(dir == 0)
			 {
			   if(yy[i]==(y+dy[2])&&xx[i]==(x+dx[2]))
			   {
				   y=yy[i];
				   x=xx[i];
				   check_pos=0;
			   }
			   
			 }
			 else if(dir == 1)
		   	{
			   if(yy[i]==(y+dy[3])&&xx[i]==(x+dx[3]))
                           {
                                   y=yy[i];
                                   x=xx[i];
				   check_pos=0;
                           }

			}
			 else if(dir == 2)
			 {
			   if(yy[i]==(y+dy[0])&&xx[i]==(x+dx[0]))
                           {
                                   y=yy[i];
                                   x=xx[i];
				   check_pos=0;
                           }


			 }
			 else if(dir == 3)
			 {
		           if(yy[i]==(y+dy[1])&&xx[i]==(x+dx[1]))
                           {
                                   y=yy[i];
                                   x=xx[i];
				   check_pos=0;
                           }
			 }
		 }
	 }
	 if(check_pos == 4)
		 break;
	}
	 //
	int ty,tx; 
	 if(dir == 0)
	 {
	    ty=y+dy[3];
	    tx=x+dx[3];
	  if(ty == -1 || ty == N || tx == -1 || tx == M)
	  {
		  dir=3;
		  dir_pos++;
	  }
	  else
	  { 
	    if(map[ty][tx] == 0)
	    {
		    y=ty;
		    x=tx;
		    dir=3;
		    map[y][x]=2;
		    dir_pos=0;
	    }
	    else
	    {
		    dir=3;
		    dir_pos++;
	    }
	  }
	 }
	 if(dir == 1)
	 {
	    ty=y+dy[0];
	    tx=x+dx[0];
	  if(ty == -1 || ty == N || tx == -1 || tx == M)
	  {
		  dir=0;
		  dir_pos++;
	  }
	  else
	  { 
	    if(map[ty][tx] == 0)
	    {
		    y=ty;
		    x=tx;
		    dir=0;
		    map[y][x]=2;
		    dir_pos=0;
	    }
	    else
	    {
		    dir=0;
		    dir_pos++;
	    }
	  }
	
	 }
	 if(dir == 2)
	 {
	    ty=y+dy[1];
	    tx=x+dx[1];
	  if(ty == -1 || ty == N || tx == -1 || tx == M)
	  {
		  dir=1;
		  dir_pos++;
	  }
	  else
	  { 
	    if(map[ty][tx] == 0)
	    {
		    y=ty;
		    x=tx;
		    dir=1;
		    map[y][x]=2;
		    dir_pos=0;
	    }
	    else
	    {
		    dir=1;
		    dir_pos++;
	    }
	  }
	
	 }
	 if(dir == 3)
	 {
	    ty=y+dy[2];
	    tx=x+dx[2];
	  if(ty == -1 || ty == N || tx == -1 || tx == M)
	  {
		  dir=2;
		  dir_pos++;
	  }
	  else
	  { 
	    if(map[ty][tx] == 0)
	    {
		    y=ty;
		    x=tx;
		    dir=2;
		    map[y][x]=2;
		    dir_pos=0;
	    }
	    else
	    {
		    dir=2;
		    dir_pos++;
	    }
	  }
	
	 }

	}


	int size=0;
	for(int i=0; i<N;i++)
		for(int j=0;j<M;j++)
			if(map[i][j]==2)
				size++;
	
	cout<<size<<"\n";

	return 0;
}
