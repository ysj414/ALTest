#include<iostream>
#include<cstring>
#define MAX 100000000
#define FIRST 1
using namespace std;
 
int map[4][4];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
 
char buf[MAX];
void mkpair(int i, int j, int step, int num);
int cnt;
int main(void)
{
    int T;
    cin>>T;
    for(int i=1; i<=T;i++)
    {
        for(int j=0;j<4;j++)
           for(int k=0;k<4;k++)
               cin>>map[j][k];
        cnt=0;
        memset(buf,0,sizeof(buf));
        for(int a=0; a<4; a++)
        {
            for(int b=0; b<4;b++)
                mkpair(a,b,FIRST,map[a][b]);
        }
        cout<<"#"<<i<<" "<<cnt<<"\n";
    }
     
    return 0;
}
 
void mkpair(int y, int x, int step,int num)
{
    if(step>6)
    {
        if(!buf[num])
        {
 //          cout<<num<<"\n";
            buf[num]=1;
            cnt++;
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        int ty=y+dy[i];
        int tx=x+dx[i];
        if(ty == -1 || ty == 4 || tx == -1 || tx == 4)
            continue;
        int next=num*10+map[ty][tx];
  //      cout<<next<<"\n";
 //       cout<<"di:"<<map[ty][tx]<<"\n";
        mkpair(ty,tx,step+1,next);
    }
}
