#include<iostream>
#define PIXEL	8
using namespace std;

char map[52][52];

char Wfirst[9][9]={"WBWBWBWB","WBWBWBWB","WBWBWBWB","WBWBWBWB","WBWBWBWB","WBWBWBWB","WBWBWBWB","WBWBWBWB"};
char Bfirst[9][9]={"BWBWBWBW","BWBWBWBW","BWBWBWBW","BWBWBWBW","BWBWBWBW","BWBWBWBW","BWBWBWBW","BWBWBWBW"};
int N,M;
int main(void)
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		for(int j=0; j<M;j++)
			cin>>map[i][j];
	}

	int MIN=999999;
	
	int NewN=N-PIXEL;
	int NewM=M-PIXEL;

	for(int i=0; i<NewN; i++)
	{
		int TEMP_WMIN=0,TEMP_BMIN=0;
		for(int j=0; j<NewM; j++)
		{
			for(int k=i; k<i+PIXEL; k++)
			{
				for(int m=j; m<j+PIXEL; m++)
				{
					if(map[k][m] != Wfirst[k-i][m-j])
						TEMP_WMIN++;
					if(map[k][m] != Bfirst[k-i][m-j])
						TEMP_BMIN++;
				}
				
				if(TEMP_WMIN < TEMP_BMIN)
				{
					if(TEMP_WMIN > MIN)
						MIN=TEMP_WMIN;
				}
				else
				{
					if(TEMP_BMIN > MIN)
						MIN=TEMP_BMIN;
				}
			}
		}
	}

	cout<<MIN<<"\n";

	return 0;
}

