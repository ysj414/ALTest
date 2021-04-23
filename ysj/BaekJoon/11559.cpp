#include<iostream>
#include<queue>
#include<cstring>
#include<unistd.h>
using namespace std;

#define RED "R"
#define GRN "G"
#define BLU "B"
#define PUP "P"
#define YEL "Y"
#define DOT '.'


char field[14][7];
int visit[14][7];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int is_chain(int x, int y);
void remove_puyo(int x, int y);
void move_field(int x, int y);

void print_field(void)
{
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<6; j++)
		{
			cout<<field[i][j];
		}
		cout<<"\n";
	}

}
int main(void)
{

	char buf[8];
	int result=0;

	for(int i=0; i<12; i++)
	{
	  memset(buf,0x0,sizeof(buf));
 	  fgets(buf,8,stdin);
	  strncpy(field[i],buf,7);
	}
	print_field();

	while(1)
	{
		int chain=0;
		for(int i=0; i<6; i++)
		{
		 int ret = is_chain(11,i);
		 if(ret)
		 {
//			 remove_puyo(11,i);
			 printf("remove puyo\n");
			 print_field();

			 for(int t=0; t<6; t++)
			 	move_field(11,t);
			 printf("change puyo\n");
			 print_field();
			 if(chain < 1)
				 chain++;

		 }
		}
		result+=chain;
		if(chain == 0)
			break;		
	}
	cout<<result<<"\n";

	return 0;
}

int is_chain(int x, int y)
{
	queue<pair<int,int>> q;
	int check_chain=1;

	if(field[x][y] == DOT)
		return false;
	q.push({x,y});

	for(int i=0; i<12; i++)
		for(int j=0; j<6; j++)
			visit[i][j]=0;

	while(!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx = tx+dx[i];
			int ny = ty+dy[i];
			if(nx > 12 || nx < 0 || ny > 6 || ny < 0)
				continue;
			if( field[nx][ny] == field[x][y] && visit[nx][ny] == 0)
			{
				printf("%d %d\n",nx,ny);
				q.push({nx,ny});
				visit[nx][ny]=1;
				check_chain++;
			}
		}
	}

	if(check_chain>=4)
	{
		for(int i=0; i<12; i++)
			for(int j=0; j<6; j++)
				if(visit[i][j] == 1)
					field[i][j]=DOT;
		return true;
	}
	else
		return false;

}

/*void remove_puyo(int x, int y)
{
	char puyo = field[x][y];
	queue<pair<int,int>> q;

	q.push({x,y});
	field[x][y]= DOT;
	while(!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for(int i=0; i<4; i++)
		{
		  int nx = tx+dx[i];
		  int ny = ty+dy[i];
		  if(nx > 12 || nx < 0 || ny > 6 || ny < 0)
			  continue;
		  if(field[nx][ny] == puyo)
		  {
			  q.push({nx,ny});
			  field[nx][ny]=DOT;
		  }
		}
	}
}*/

void move_field(int x, int y)
{
		int count=0;
		if(field[x][y] != DOT)
			return;

		for(int j=11; j>=0; j--)
		{
			if(field[j][y] != DOT)
				count++;
		}
		printf("count:%d",count);
		if(count == 12)
			return;

		while(count--)
		{
			for(int j=11; j>0; j--)
				field[j][y]=field[j-1][y];
		}
}
