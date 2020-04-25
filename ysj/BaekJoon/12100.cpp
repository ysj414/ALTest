#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int board[20][20]={0,};
int sboard[20][20]={0,};

// 0123 up down left right
int Pair[5];

int N;
int MAX=0;

void makePair(int step);
void Moveboard(int dir);

int main(void)
{
	cin>>N;
	if(N==1)
	{
          int a;
           cin>>a;
	   cout<<a<<"\n";
	   return 0;
	}
	else
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			       cin>>board[i][j];
	}
	
	makePair(0);
	cout<<MAX<<"\n";

	return 0;
}

void makePair(int step)
{

	if(step==5)
	{
		for(int i=0;i<N;i++)
		   for(int j=0;j<N;j++)
			sboard[i][j]=board[i][j];

		for(int k=0;k<5;k++)
		{
			Moveboard(Pair[k]);
//			cout<<"Dir"<<Pair[k]<<"\n";
//			for(int y=0;y<N;y++)
//			{
//				for(int x=0;x<N;x++)
//					cout<<sboard[y][x]<<" ";
//				cout<<"\n";
//			}

		}
		for(int a=0;a<N;a++)
			for(int b=0;b<N;b++)
			{
				if(sboard[a][b]>MAX)
					MAX=sboard[a][b];
			}
		memset(sboard,0,sizeof(sboard));
		return;	
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			Pair[step]=i;
			makePair(step+1);
		}
	}
}

void Moveboard(int dir)
{
	stack<int> bfblock;

	if(dir == 0)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=N-1;j>=0;j--)
			{  if(sboard[j][i]>=2)
			    {
			    	bfblock.push(sboard[j][i]);
				sboard[j][i]=0;
			    }
			}
		     int k=0;
		      while(!bfblock.empty())
		      {
			      int add= bfblock.top();
			      bfblock.pop();
			      if(bfblock.empty())
			      {
				   sboard[k][i]=add;
				   k++;
				   break;
			      }
		   	      else
			      {
				      if(add==bfblock.top())
				      {
					      add=add*2;
					      bfblock.pop();
				      }
					      sboard[k][i]=add;
					      k++;
			      }	      
			      
		      }
//	      	      for(int p=k;k<N;k++)
//				sboard[k][i]=0;	      
		}
	}
	else if(dir == 1)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{   if(sboard[j][i]>=2)
				{
			    	bfblock.push(sboard[j][i]);
			    	sboard[j][i]=0;
				}
			}
		     int k=N-1;
		      while(!bfblock.empty())
		      {
			      int add= bfblock.top();
			      bfblock.pop();
			      if(bfblock.empty())
			      {
				   sboard[k][i]=add;
				   k--;
				   break;
			      }
		   	      else
			      {
				      if(add==bfblock.top())
				      {
					      add=add*2;
					      bfblock.pop();
				      }

					      sboard[k][i]=add;
					      k--;
			      }	      
			      
		      }
//		      for(int p=k;k>=0;k--)
//			      sboard[k][i]=0;
			
		}
	
	}
	else if(dir == 2)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=N-1;j>=0;j--)
			{
			   if(sboard[i][j]>=2)
			   {
			    bfblock.push(sboard[i][j]);
			    sboard[i][j]=0;
			   }
			}
		     int k=0;
		      while(!bfblock.empty())
		      {
			      int add= bfblock.top();
			      bfblock.pop();
			      if(bfblock.empty())
			      {
				   sboard[i][k]=add;
				   k++;
				   break;
			      }
		   	      else
			      {
				      if(add==bfblock.top())
				      {
					      add=add*2;
					      bfblock.pop();
				      }
				 
				      sboard[i][k]=add;
				      k++;
			      }	      
			      
		      }
//		      for(int p=k;p<N;p++)
//			      sboard[i][p]=0;
			
		}
	

	}
	else if(dir == 3)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{  if(sboard[i][j]>=2)
			    {
			    bfblock.push(sboard[i][j]);
			    sboard[i][j]=0;
			    }
			}
		     int k=N-1;
		      while(!bfblock.empty())
		      {
			      int add= bfblock.top();
			      bfblock.pop();
			      if(bfblock.empty())
			      {
				   sboard[i][k]=add;
				   k--;
				   break;
			      }
		   	      else
			      {
				      if(add==bfblock.top())
				      {
					      add=add*2;
					      bfblock.pop();
				      }
					      sboard[i][k]=add;
					      k--;
			      }	      
			      
		      }
//		      for(int p=k;k>=0;k--)
//			      sboard[i][k]=0;
		}
	
	}















}




