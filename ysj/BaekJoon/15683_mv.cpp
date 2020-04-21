#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int room[8][8];
vector<int> cctv;
vector<pair<int,int>> cctvxy;
vector<int> cv;
int a[8];
int main(void)
{
	int MIN=9999999;

	cin>>N>>M;
	
	for(int i=0;i<N;i++)
	  for(int j=0;j<M;j++)
	  {
		  cin>>room[i][j];
		  if(room[i][j]>0 && room[i][j]<6)
		  {
			  cctv.push_back(room[i][j]);
			  cctvxy.push_back({i,j});
		  }
	  }


	for(int i=0;i<cctv.size();i++)
	{
		for(int j=1;j<=4;j++)
		{
		 cv.push_back(4*i+j);
		}
	}
	do
	{
		int temp_min;
		for(int i=0;i<cv.size();i++)
			a[i]=cv[4*i]%4;
		temp_min=cal_area();
		if(temp_min<MIN)
			temp_min=MIN;

	}while(next_permutation(cv.begin(),cv.end());

	cout<<MIN<<"\n";
	return 0;
}

int cal_area()
{

   for(int i=0;i<cctv.size();i++)
   {
   	
   }

}
