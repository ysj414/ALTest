#include<iostream>
#define PIXEL	8
using namespace std;

char map[52][52];

char Wfirst[9][9]={"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
char Bfirst[9][9]={"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
int N,M;
int main(void)
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		   cin>>map[i][j];
	}
/*
	cout<<"debug"<<"\n";
	for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++)
		cout<<map[i][j];
	    cout<<"\n";
	}
	cout<<"debug"<<"\n";
	for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++)
		cout<<Wfirst[i][j];
	    cout<<"\n";
	}
	cout<<"debug"<<"\n";
	for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++)
		cout<<Bfirst[i][j];
	    cout<<"\n";
	}
*/


	int MIN=999999;
	
	int NewN=N-PIXEL;
	int NewM=M-PIXEL;
//	cout<<NewN<<" "<<NewM<<"\n";
	for(int i=0; i<=NewN; i++)
	{
		for(int j=0; j<=NewM; j++)
		{
		int TEMP_WMIN=0,TEMP_BMIN=0;
			for(int k=i; k<i+PIXEL; k++)
			{
				for(int m=j; m<j+PIXEL; m++)
				{
//				    cout<<"M(i,j) W(i,j) B(i,j)"<<"("<<k<<","<<m<<" "<<map[k][m]<<" "<<Wfirst[k-i][m-j]<<" "<<Bfirst[k-i][m-j]<<"\n";
					if(map[k][m] != Wfirst[k-i][m-j])
						TEMP_WMIN++;
					if(map[k][m] != Bfirst[k-i][m-j])
						TEMP_BMIN++;
				}
			}
					if(TEMP_WMIN < MIN)
						MIN=TEMP_WMIN;
					if(TEMP_BMIN < MIN)
						MIN=TEMP_BMIN;
			
//			cout<<"WMIN: "<<TEMP_WMIN<<"BMIN: "<<TEMP_BMIN<<"\n";
//			cout<<"**"<<"\n";
		}
	}

	cout<<MIN<<"\n";

	return 0;
}

