#include <iostream>

using namespace std;

int dice[6]={0,0,0,0,0,0};  // 0 top 1 nor 2 east 3 west 4 sou 5 bot
int map[20][20];
void MoveToDice(int direction)
{
	int tempdice[6]={0,};

	switch(direction)
	{
		case 1:
			tempdice[0]=dice[3];
			tempdice[1]=dice[1];
			tempdice[2]=dice[0];
			tempdice[3]=dice[5];
			tempdice[4]=dice[4];
			tempdice[5]=dice[2];
			break;
		case 2:
			tempdice[0]=dice[2];
			tempdice[1]=dice[1];
			tempdice[2]=dice[5];
			tempdice[3]=dice[0];
			tempdice[4]=dice[4];
			tempdice[5]=dice[3];
			break;
		case 3:
			tempdice[0]=dice[4];
			tempdice[1]=dice[0];
			tempdice[2]=dice[2];
			tempdice[3]=dice[3];
			tempdice[4]=dice[5];
			tempdice[5]=dice[1];
			break;
		case 4:
			tempdice[0]=dice[1];
			tempdice[1]=dice[5];
			tempdice[2]=dice[2];
			tempdice[3]=dice[3];
			tempdice[4]=dice[0];
			tempdice[5]=dice[4];
			break;
		default:
			break;	
	}

	dice[0]=tempdice[0];
	dice[1]=tempdice[1];
	dice[2]=tempdice[2];
	dice[3]=tempdice[3];
	dice[4]=tempdice[4];
	dice[5]=tempdice[5];

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int k;
    int move;
    int N,M;
    int x,y;
    int i,j;
    int swap;
    
    cin>>N>>M>>y>>x>>k;
    for(i=0; i < N ; i++)
        for(j=0; j< M ; j++)
            cin>>map[i][j];

    for(i= 0 ; i < k ; ++i)
    {
        cin>>move;
        if(move == 1)
        {
            
            if( (x+1) > M-1)
                continue;
			x++;
			MoveToDice(1);
        }
        else if(move == 2)
        {
            if((x-1)<0)
                continue;
			x--;
			MoveToDice(2);
        }
        else if(move == 3)
        {
            
            if( (y-1) < 0)
                continue;
			y--;
			MoveToDice(3);
        }
        else if(move == 4)
        {
            if((y+1)>N-1)
                continue;
			y++;
			MoveToDice(4);
               
        }

		if(map[y][x] == 0)
			map[y][x] = dice[5];
		else
		{
			dice[5] = map[y][x];
			map[y][x] = 0;
		}
	
        cout<<dice[0]<<"\n";
    }
    
    

    
	
	return 0;
}
