#include<iostream>

#include<iostream>

using namespace std;

int dice[10];
int piece[4]={1,2,3,4};
int diceTopiece[10]={0,};
int MAX=0;
void makepair(int step);
int main(void)
{

        for(int i=0;i<10;i++)
                cin>>dice[i];

        makepair(0);
	for(int i=0;i<10;i++)
		cout<<diceTopiece[i];
        return 0;
}
void makepair(int step)
{
//      int temp_max;
        if(step>=9)
        {
//              temp_max = Getscore();
//              if(temp_max>MAX)
//                      MAX=temp_max;
		  return;
        }
        else
        {
                for(int i=1;i<4;i++)
                {
                  diceTopiece[step]=i;
                  makepair(step+1);
                }
        }


}
