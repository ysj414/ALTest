#include<iostream>
#include<queue>
using namespace std;


char board[10][10];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int N,M;
int cnt=0;
void DFS(int ry,int rx, int by, int bx, int step);

int main(void)
{

	cin>>N>>M;
	int y1,y2,x1,x2;
	for(int i=0;i<N;i++)
	   for(int j=0;j<M;j++)
	   {
	        cin>>board[i][j];
		if(board[i][j]='R')
		{
			y1=i;
			x1=j;
		}
		if(board[i][j]='L')
		{
			y2=i;
			x2=j;
		}
	   }

	DFS(y1,x1,y2,x2,0);
	cout<<cnt<<"\n";

	return 0;
}

void DFS(int ry,int rx,int by,int bx, int step)
{
     if(step == 11)
     {
	     cnt=-1;
	     return;
     }	     
     
     for(int i=0;i<4;i++)
     {
	int nry= ry+dy[i];
	int nrx= rx+dx[i];
	int nby= by+dy[i];
	int nbx= bx+dx[i];
	char pos;

	/*modeling for movement of bid*/

	while(board[nby][nbx]!='#')
	{
		if(board[nby][nbx] =='O')
			return;
		else if(board[nby][nbx] =='R')
			break;

		nby=nby+dy[i];
		nbx=nbx+dx[i];
	}
	while(board[nry][nrx]!='#')
	{
		if(board[nry][nrx] =='O')
		{
			cnt=step;
			return;
		}
		else if(board[nry][nrx] =='B')
			break;
		nry=nry+dy[i];
		nrx=nrx+dx[i];
	}
	
	/*go to next postion of bid*/
	pos=board[ry][rx];
	board[ry][rx]=board[nry][nrx];
	board[nry][nrx]=pos;

	pos=board[by][bx];
	board[by][bx]=board[nby][nbx];
	board[nby][nbx]=pos;

	DFS(nry,nrx,nby,nbx,step+1);

	pos=board[ry][rx];
	board[ry][rx]=board[nry][nrx];
	board[nry][nrx]=pos;

	pos=board[by][bx];
	board[by][bx]=board[nby][nbx];
	board[nby][nbx]=pos;
     }

}
