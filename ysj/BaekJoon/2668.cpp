#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> num[101];
vector<int> answer;
int main(void)
{
	int N;
	int val;
	int a;
	int set=0;
	cin>>N;
	
	for(int i=1; i<=N; i++)
	{	
		cin>>val;
		num[i].push_back(val);
	}

	for(int j=1; j<=N; j++)
	{
		a=num[j][0];
		for(int k=1; k<=N; k++)
		{
			
		if(num[a][0] == j)
		{
			answer.push_back(a);
			set++;
			break;
		}
		else
		{
			a=num[a][0];
		}		
		}
	}
	
	sort(answer.begin(),answer.end());
	cout<<set<<'\n';

	for(int i=0; i<answer.size();i++)
		cout<<answer[i]<<'\n';


	return 0;
}
