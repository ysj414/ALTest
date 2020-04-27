#include<iostream>
#include<cstring>

using namespace std;


int N,M,T;  // circle N, numbers in circle M, rotate T
int circle[55][55];
int delnum[55][55];

void rotate(int cir,int dir, int times);
void removenum(int cir);
int main(void)
{
	cin>>N>>M>>T;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>circle[i][j];
//		cout<<circle[i][j];
		}
//		cout<<"\n";
	}

	while(T--)
	{
		int x,d,k; // x : select x greater circle d: clockwise or counter k: k times rot
		cin>>x>>d>>k;
	     for(int i=1;i<=N;i++)
	     {
		     if(i%x==0)    // rotate
		     {
			rotate(i,d,k);
//			for(int j=1;j<=M;j++)
//				cout<<circle[i][j]<<" ";
//			cout<<"rotate\n";
		     }
	     }
			removenum(1);

			for(int j=1;j<=N;j++)
			{
//				for(int k=1;k<=M;k++)
//					cout<<circle[j][k]<<" ";
//				cout<<"\n";
			}
			memset(delnum,0,sizeof(delnum));			

	}
	int score=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			score+=circle[i][j];
	}
	cout<<score<<"\n";
	return 0;
}
void rotate(int cir, int dir, int times)
{
	if(times== 0)
		return;
	else
	{
	    if(dir)
	    {
		int temp=circle[cir][1];	    
		for(int i=1;i<=M-1;i++)
		  circle[cir][i]=circle[cir][i+1];
		circle[cir][M]=temp;
		rotate(cir,dir,times-1);
	    }
	    else
	    {
		int temp=circle[cir][M];
		for(int i=M;i>=2;i--)
		  circle[cir][i]=circle[cir][i-1];
			
		circle[cir][1]=temp;
		rotate(cir,dir,times-1);
	    }
	}
}
void removenum(int cir)
{
	int isremoved=0;
	int dy[4]={-1,1,0,0};
	int dx[4]={0,0,-1,1};

	for(int i=1;i<=N;i++)
	{
		
		for(int j=1;j<=M;j++)
		{
			
			int cur=circle[i][j];
			if(cur == 0)
				continue;
			if(j == 1)
			{
				if(circle[i][j] == circle[i][M])
				{
					delnum[i][j]=1;
					delnum[i][M]=1;
				}
			}

			for(int k=0;k<4;k++)
			{
				int ty=i+dy[k];
				int tx=j+dx[k];
				if(ty == 0 || ty == (N+1) || tx == 0 || tx ==(M+1))
					continue;

				if(circle[ty][tx]==cur)
				{
					delnum[ty][tx]==1;
					delnum[i][j]=1;
				}
			}
		}
	}
	

  //  cout<<"flag:"<<isremoved<<"\n";
 	for(int i=1;i<=N;i++)
	{
		
		for(int j=1;j<=M;j++)
		{
		   if(delnum[i][j]== 1)
		   {
		   	   circle[i][j]=0;	  
			   isremoved++; 
		   }
		}
	}
	     
      if(isremoved==0)
      {
	 float avg=0;
	 int cnt=0;
	 for(int k=1;k<=N;k++)
	 	for(int i=1;i<=M;i++)
		{       if(circle[k][i]!=0)
			{	
		 	avg+=circle[k][i];
			cnt++;
			}
		}
	 if(cnt==0)
	    avg=0;
	 else
	    avg=avg/cnt;
//	 cout<<"avg"<<avg<<"\n";
	for(int k=1;k<=N;k++)
	{
	 for(int i=1;i<=M;i++)
	 {
		 if(circle[k][i]==0)
			 continue;
		 else if((float)circle[k][i]>avg)
			 circle[k][i]--;
		 else if((float)circle[k][i]<avg)
			 circle[k][i]++;
	 }
	}
      }
    
}
