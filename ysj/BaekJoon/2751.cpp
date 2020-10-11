#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;
int N;
int main(void)
{
 cin>>N;
 for(int i=0;i<N;i++)
 {
	int temp;
	cin>>temp;
	arr.push_back(temp);
 }
 sort(arr.begin(),arr.end());
 
 for(int i=0;i<N;i++)
	cout<<arr[i]<<"\n";
 return 0;
}
