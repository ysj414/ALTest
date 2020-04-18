#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int matrix[21][21];

int main(void)
{
	int N;
	cin>>N;
	int score1,score2;
	int MIN=99999999;

	for(int i=0; i<N;i++)
	    for(int j=0;j<N;j++)
		    cin>>matrix[i][j];
	
	vector<int> vec;
	for(int i=0 ; i<N;i++)
		vec.push_back(i);

	vector<int> com;
	for(int i=0; i<N/2;i++)
		com.push_back(0);
	for(int i=0; i<N/2;i++)
		com.push_back(1);
	
	sort(com.begin(),com.end());


	do{
	    score1=0;
	    score2=0;

	    vector<int> team1,team2;
	    for(int i=0; i<N;i++)
	    {
		    if(com[i]==1)
			  team1.push_back(vec[i]);
		    else
			  team2.push_back(vec[i]);
	    }
/*	    
	    vector<int> score;
	    score.push_back(-1);
//	    if(N/2 == 2)
//		 score.push_back(-2);
//	    else
	    	 score.push_back(-1);

	    for(int i=0;i<(N/2-2);i++)
		    score.push_back(i);

	    sort(score.begin(),score.end());
	
	   vector<int> idx;
	    do
	    {
	      for(int i=0; i<N/2;i++)
	      {
	        if(score[i] <= -1)
	          idx.push_back(i);
		
	      }
	       score1+=matrix[team1[idx[0]]][team1[idx[1]]];
	       score2+=matrix[team2[idx[0]]][team2[idx[1]]];
	       cout<<"i,j"<<team1[idx[0]]<<","<<team1[idx[1]]<<"score:"<<matrix[team1[idx[0]]][team1[idx[1]]]<<"\n";
	       for(int k=0;k<N/2;k++)
		       cout<<score[k]<<" ";
	       cout<<"\n";
	    }while(next_permutation(score.begin(),score.end()));
*/

	   for(int i=0; i<N/2;i++)
	   {
		   for(int j=0; j<N/2;j++)
		   {
			   if(i==j)
			     continue;
		      score1+=matrix[team1[i]][team1[j]];
		      score2+=matrix[team2[i]][team2[j]];
		   }
	   }

	    int diff;
            if(score1>=score2)
	    	diff=score1-score2;
	    else
	    	diff=score2-score1;
	    if(diff<MIN)
	      MIN=diff;
	
	}while(next_permutation(com.begin(),com.end()));

	cout<<MIN<<"\n";

	return 0;
}
