#include<iostream>
#include<cstring>
#include<queue>

using namespace std;


int map[25][25];
int visit[25][25];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

queue<pair<int,int>> q;
int N;
struct shark
{
        int y;
        int x;
        int size=2;
        int eat=0;
};

struct shark sh;
pair<int,int> fish[400];
int Time=0;

void print(void);
void BFS(void);
int main(void)
{
        cin>>N;
        for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                {
                        cin>>map[i][j];
                        if(map[i][j]==9)
                        {
                                sh.y=i;
                                sh.x=j;
                                q.push({i,j});
                        }
                }
        BFS();

        cout<<Time<<"\n";
        return 0;
}
void print(void)
{
        cout<<"Map\n";
        for(int i=0;i<N;i++)
        {
                for(int j=0;j<N;j++)
                        cout<<map[i][j];
                cout<<"\n";
        }
        cout<<"\n";

        cout<<"visit\n";
        for(int i=0;i<N;i++)
        {
                for(int j=0;j<N;j++)
                        cout<<visit[i][j];
                cout<<"\n";
        }
        cout<<"Time: ";
        cout<<Time<<"\n";
}
void BFS(void)
{
     int cnt=0;
     while(1)
     {
        int y,x;
        while(!q.empty())
        {
                y=q.front().first;
                x=q.front().second;
                q.pop();

                for(int i=0;i<4;i++)
               {
                  int ty=y+dy[i];
                  int tx=x+dx[i];
                  if( ty==-1 || ty==N || tx==-1 || tx==N )
                          continue;
                  if(visit[ty][tx]==0 && map[ty][tx]<=sh.size)
                  {
                          if(map[ty][tx]>=1 && map[ty][tx]<sh.size)
                          {
                                  fish[cnt].first=ty;
                                  fish[cnt].second=tx;
                                  cnt++;
                          }
                          visit[ty][tx]=visit[y][x]+1;
                          q.push({ty,tx});
                  }
                }
        }
//      print();

        if(cnt==0)
          break;
        else if(cnt == 1)
        {
        map[sh.y][sh.x]=0;
        sh.y=fish[0].first;
        sh.x=fish[0].second;
        map[sh.y][sh.x]=9;
        Time+=visit[fish[0].first][fish[0].second];
        map[fish[0].first][fish[0].second]=0;
        cnt=0;
        q.push({sh.y,sh.x});
        sh.eat++;
        if(sh.eat == sh.size)
        {
                sh.size++;
                sh.eat=0;
        }
        }
        else
        {
        int Min=visit[fish[0].first][fish[0].second];
        int index=0;

        for(int i=1;i<cnt;i++)
        {
           if(visit[fish[i].first][fish[i].second]<Min)
           {
                   Min=visit[fish[i].first][fish[i].second];
                   index=i;
           }
           else if(visit[fish[i].first][fish[i].second]==Min)
           {
                   if(fish[i].first<fish[index].first)
                           index=i;
                   else if(fish[i].first==fish[index].first)
                   {
                           if(fish[i].second<fish[index].second)
                                   index=i;
                   }
           }
        }
        map[sh.y][sh.x]=0;
        sh.y=fish[index].first;
        sh.x=fish[index].second;
        map[sh.y][sh.x]=9;
        Time+=visit[fish[index].first][fish[index].second];
        map[fish[index].first][fish[index].second]=0;
        cnt=0;
        q.push({sh.y,sh.x});
        sh.eat++;
        if(sh.eat == sh.size)
        {
                sh.size++;
                sh.eat=0;
        }
        }
//      print();
        memset(visit,0,sizeof(visit));
        memset(fish,0,sizeof(fish));

     }

}
