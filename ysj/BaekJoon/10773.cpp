#include<iostream>
#include<stack>



using namespace std;

int main(void)
{

	int K;
	long sum=0;
	stack<int> st;
	
	cin>>K;

	while(K--)
	{
		int temp;
		cin>>temp;
		if(temp != 0)
			st.push(temp);
		else
			st.pop();		
	}

	while(!st.empty())
	{
		sum+=st.top();
		st.pop();
	}
	cout<<sum<<"\n";


	return 0;
}
