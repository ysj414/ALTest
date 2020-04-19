#include<iostream>
#include<queue>
using namespace std;


char board[10][10];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int N,M;
int cnt=99999;
void DFS(int ry,int rx, int by, int bx, int step);

int main(void)
{

	cin>>N>>M;
	int y1,y2,x1,x2;
	for(int i=0;i<N;i++)
	   for(int j=0;j<M;j++)
	   {
	        cin>>board[i][j];
		if(board[i][j]=='R')
		{
			y1=i;
			x1=j;
		}
		if(board[i][j]=='B')
		{
			y2=i;
			x2=j;
		}
	   }
	cout<<y1<<x1<<y2<<x2<<"\n";
	DFS(y1,x1,y2,x2,0);
	cout<<cnt<<"\n";

	return 0;
}

void DFS(int ry,int rx,int by,int bx, int step)
{
     if(step == 11)
     {
	     return;
     }	     
     
     for(int i=0;i<4;i++)
     {
	int nry= ry+dy[i];
	int nrx= rx+dx[i];
	int nby= by+dy[i];
	int nbx= bx+dx[i];



	cout<<"before loop:"<<ry<<rx<<by<<bx<<"\n";
	cout<<"step:"<<cnt<<"\n";
	if(board[nby][nbx]=='#')
	{
		nby=by;
		nbx=bx;
	}
	else
	{
	while(1)
	{
		if(board[nby][nbx] =='O')
			return;
		else if(board[nby][nbx] =='R')
			break;
		else if(board[nby][nbx] =='#')
		{
			nby=nby-dy[i];
			nby=nby-dx[i];
			break;
		}
		nby=nby+dy[i];
		nbx=nbx+dx[i];
	}
	}
	if(board[nry][nrx]=='#')
	{
		nry=ry;
		nrx=rx;
	}
        else
	{	
	while(1)
	{
		if(board[nry][nrx] =='O')
		{
			if(step<cnt)
			   cnt=step;
			return;
		}
		else if(board[nry][nrx] =='B')
			break;
		else if(board[nry][nrx] =='#')
		{
			nry=nry-dy[i];
			nrx=nrx-dx[i];
			break;
		}
		nry=nry+dy[i];
		nrx=nrx+dx[i];
	}
	}
	if(nry==ry && nrx==rx && nby==by && nbx ==bx)
		continue;

	cout<<"after loop:"<<nry<<nrx<<nby<<nbx<<"\n";
	
	/*go to next postion of bid*/
	board[ry][rx]='.';
	board[nry][nrx]='R';

	board[by][bx]='.';
	board[nby][nbx]='B';
	DFS(nry,nrx,nby,nbx,step+1);
	board[ry][rx]='.';
	board[nry][nrx]='R';

	board[by][bx]='.';
	board[nby][nbx]='B';
	
     }

}
