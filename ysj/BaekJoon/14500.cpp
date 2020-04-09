#include<iostream>

using namespace std;

int N,M;
int map[500][500];
int visit[500][500]={0,};
int Dmax=0;
int Tmax=0;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void DFS(int y, int x,int step, int sum);
void Tsum(int y,int x);
int main(void)
{
	
	cin>>N>>M;

	for(int i=0; i<N;i++)
		for(int j=0;j<M;j++)
			cin>>map[i][j];

	for(int i=0; i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
		  visit[i][j]=true;
		  DFS(i,j,1,map[i][j]);
		  visit[i][j]=false;
		  Tsum(i,j);
		}	
	}

	if(Dmax>Tmax)
		cout<<Dmax<<"\n";
	else
		cout<<Tmax<<"\n";

	return 0;
}
void DFS(int y,int x, int step, int sum)
{
	int ty,tx;
	
	if(step == 4)
	{
		if(sum>Dmax)
			Dmax=sum;
		return;
	}

	for(int i=0; i<4; i++)
	{
		ty=y+dy[i];
		tx=x+dx[i];
		if(ty == N || ty == -1 || tx == M || tx == -1)
			continue;
		if(visit[ty][tx] == 0)
		{
			visit[ty][tx]=true;
			DFS(ty,tx,step+1,sum+map[ty][tx]);
			visit[ty][tx]=false;
		}
	}


}
void Tsum(int y, int x)
{
	int sum;

	int hx=x+1;
	int Hx=x+2;
	int lx=x-1;
    int Lx=x-2;

	int hy=y+1;
	int Hy=y+2;
	int ly=y-1;
	int Ly=y-2;


	// 1
	if( hy<N && Hx<M)
	{
		sum=map[y][x]+map[y][hx]+map[y][Hx]+map[hy][hx];
		if(sum>Tmax)
			Tmax=sum;
	}
    //2
    if(ly>=0 && Hx<M)
    {
        sum=map[y][x]+map[y][hx]+map[y][Hx]+map[ly][hx];
        if(sum>Tmax)
            Tmax=sum;
    }
	//3
	if(Ly>=0 && hx < M)
	{
		sum=map[y][x]+map[ly][x]+map[Ly][x]+map[ly][hx];
		if(sum>Tmax)
			Tmax=sum;
	}
	//4
	if(Ly>=0 && lx >=0)
	{
		sum=map[y][x]+map[ly][x]+map[Ly][x]+map[ly][lx];
		if(sum>Tmax)
			Tmax=sum;
	}
	//5
 	if(hy<N && Lx>=0)
	{
		sum=map[y][x]+map[y][lx]+map[y][Lx]+map[hy][lx];
		if(sum>Tmax)
			Tmax=sum;
	}
    //6
    if(ly >=0 && Lx>=0)
    {
        sum=map[y][x]+map[y][lx]+map[y][Lx]+map[ly][lx];
        if(sum>Tmax)
            Tmax=sum;
    }
	//7
	if(Hy<N && lx>=0)
	{
		sum=map[y][x]+map[hy][x]+map[Hy][x]+map[hy][lx];
		if(sum>Tmax)
			Tmax=sum;
	}
    //8
    if(Hy<N && hx<M)
    {
        sum=map[y][x]+map[hy][x]+map[hy][hx]+map[Hy][x];
        if(sum>Tmax)
            Tmax=sum;
    }

}

