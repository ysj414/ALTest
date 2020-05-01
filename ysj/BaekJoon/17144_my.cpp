#include<iostream>
using namespace std;


int room[55][55];

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int ans=0;

int R,C,T;
int cl;
int main(void)
{
   cin>>R>>C>>T;


   for(int i=0;i<R;i++)
   {
           for(int j=0;j<C;j++)
           {
                cin>>room[i][j];

                if(room[i][j] == -1)  //save air conditioner
                        cl=i;
           }
   }
	   }
   }
   cl--;  // why?

   while(T--)
   {
     //model spread nano dust
     int tmp[55][55]={0,};
     for(int i=0;i<R;i++)
     {
	     for(int j=0;j<C;j++)
	     {
		     if(room[i][j]<=0)  // no dust
			     continue;
		    for(int k=0;k<4;k++)
		    {
			    int ty=i+dy[k];
			    int tx=j+dx[k];
			    if(ty == -1 || ty == R || tx == -1 || tx == C || room[ty][tx] == -1)
				    continue;
			    tmp[ty][tx]+=room[i][j]/5;
			    tmp[i][j]-=room[i][j]/5;
		    }

	     }
     }   
     for(int i=0;i<R;i++)
     {
	     for(int j=0;j<C;j++)
		     room[i][j]+=tmp[i][j];
     } 

     //debug
//     cout<<"after dust model"<<"\n";
//    for(int i=0;i<R;i++)
//     {
//	     for(int j=0;j<C;j++)
//		     cout<<room[i][j]<<" ";
//	     cout<<"\n";     
//    }

     for(int i=cl-1; i>=1;i--)
     	  room[i][0]=room[i-1][0];
     for(int i=0;i<C-1;i++)
	   room[0][i]=room[0][i+1];
     for(int i=0;i<cl;i++)
	    room[i][C-1]=room[i+1][C-1];
     for(int i=C-1;i>=1;i--)
	     room[cl][i]=room[cl][i-1];
      
     room[cl][1]=0;

     for(int i=cl+2;i<R-1;i++)
	     room[i][0]=room[i+1][0];
     for(int i=0;i<C-1;i++)
	     room[R-1][i]=room[R-1][i+1];
     for(int i=R-1;i>cl+1;i--)
	     room[i][C-1]=room[i-1][C-1];
     for(int i=C-1;i>=1;i--)
	     room[cl+1][i]=room[cl+1][i-1];

     room[cl+1][1]=0;
     

      //debug
//     cout<<"after aircontion model"<<"\n";
//     for(int i=0;i<R;i++)
//     {
//	     for(int j=0;j<C;j++)
//		     cout<<room[i][j]<<" ";
//	     cout<<"\n";
//    }
     
 
   }




   //sum
   for(int i=0;i<R;i++)
   {
	   for(int j=0;j<C;j++)
	   {
		   ans+=room[i][j];
		//   cout<<room[i][j];
	   }
//	   cout<<"\n";
   }
   cout<<ans+2<<"\n";

  return 0;
}

