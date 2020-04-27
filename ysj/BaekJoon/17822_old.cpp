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
			for(int j=1;j<=M;j++)
				cout<<circle[i][j]<<" ";
			cout<<"rotate\n";
		     }
	     }
			removenum(1);

			for(int j=1;j<=N;j++)
			{
				for(int k=1;k<=M;k++)
					cout<<circle[j][k]<<" ";
				cout<<"\n";
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
	
     for(cir=1;cir<=N;cir++)
     {	     
	if(cir == 1)
	{
	  for(int i=2; i<=M-1;i++)
	  {
		  int cur=circle[cir][i];
		  if(cur==0)
			continue;
		  if(circle[cir][i-1] == cur)
		  {
			  delnum[cir][i-1]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir][i+1] ==cur)
		  {
			  delnum[cir][i+1]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir+1][i] == cur)
		  {
			  delnum[cir+1][i]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
	  }
	  //first 
	  int cur=circle[cir][1];
	  if(cur!=0)
	  {
	  if(cur == circle[cir][2])
	  {
		  delnum[cir][2]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir+1][1])
	  {
		  delnum[cir+1][1]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir][M])
	  {
		  delnum[cir][M]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  }
	  //last
	  cur = circle[cir][M];
	  if(cur!=0)
	  {
	  if(cur == circle[cir][M-1])
	  {
		  delnum[cir][M-1]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir+1][M])
	  {
		  delnum[cir+1][M]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  }
	}
	else if(cir == N)
	{
	  for(int i=2; i<=M-1;i++)
	  {
		  int cur=circle[cir][i];
		  if(cur==0)
			continue;
		  if(circle[cir][i-1] == cur)
		  {
			  delnum[cir][i-1]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir][i+1] ==cur)
		  {
			  delnum[cir][i+1]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir-1][i] == cur)
		  {
			  delnum[cir-1][i]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
	  }
	
	  //first 
	  int cur=circle[cir][1];
	  if(cur!=0)
	  {
	  if(cur == circle[cir][2])
	  {
		  delnum[cir][2]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir-1][1])
	  {
		  delnum[cir-1][1]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir][M])
	  {
		  delnum[cir][M]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  }
	  //last
	  cur = circle[cir][M];
	  if(cur!=0)
	  {
	  if(cur == circle[cir][M-1])
	  {
		  delnum[cir][M-1]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir-1][M])
	  {
		  delnum[cir-1][M]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  }
	
	}
	else
	{

		for(int i=2;i<=M-1;i++)
		{
			  int cur=circle[cir][i];
			  if(cur==0)
			      continue;
		  if(circle[cir][i-1] == cur)
		  {
			  delnum[cir][i-1]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir][i+1] ==cur)
		  {
			  delnum[cir][i+1]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir-1][i] == cur)
		  {
			  delnum[cir-1][i]=true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		  else if(circle[cir+1][i] == cur)
		  {
			  delnum[cir+1][i] == true;
			  delnum[cir][i]=true;
			  isremoved++;
		  }
		}
          //first 
	  int cur=circle[cir][1];
	  if(cur!=0)
	  {
	  if(cur == circle[cir][2])
	  {
		  delnum[cir][2]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir-1][1])
	  {
		  delnum[cir-1][1]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir+1][1])
	  {
		  delnum[cir+1][1]=true;
		  delnum[cir][1]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir][M])
	  {
		  delnum[cir][1]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  }
	  //last
	  cur = circle[cir][M];
	  if(cur!=0)
	  {
	  if(cur == circle[cir][M-1])
	  {
		  delnum[cir][M-1]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir-1][M])
	  {
		  delnum[cir-1][M]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  else if(cur == circle[cir+1][M])
	  {
		  delnum[cir+1][M]=true;
		  delnum[cir][M]=true;
		  isremoved++;
	  }
	  }
	}
     } 

  //  cout<<"flag:"<<isremoved<<"\n";
    for(cir=1;cir<=N;cir++)
    {
      if(isremoved>=1)
      {
     
       if(cir==1)
       {
	for(int j=0;j<=1;j++)
	{	
	for(int i=1;i<=M;i++)
	{
		if(delnum[cir+j][i]==1)
			circle[cir+j][i]=0;	
	}
	}

       }
       else if(cir == N)
       {
		for(int j=-1;j<=0;j++)
	{	
	for(int i=1;i<=M;i++)
	{
		if(delnum[cir+j][i]==1)
			circle[cir+j][i]=0;	
	}
	}
       
       }
       else
       {

	for(int j=-1;j<=1;j++)
	{	
	for(int i=1;i<=M;i++)
	{
		if(delnum[cir+j][i]==1)
			circle[cir+j][i]=0;	
	}
	}
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
	 cout<<"avg"<<avg<<"\n";
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
