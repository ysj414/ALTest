#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


int main(void)
{

	int T;
	char buf[55];
	cin>>T;

	while(T--)
	{

		memset(buf,0,sizeof(buf));
		cin>>buf;
		int len=strlen(buf);
		stack<char> st;
		int flag = 1;

		for(int i=0; i<len; i++)
		{
			if(buf[i] == '(')
				st.push(buf[i]);
			else
			{
				if(st.empty())
				{
					flag = 0;
					break;
				}
				if(st.top() != '(')
				{
					flag = 0;
					break;
				}
				st.pop();
			}	
		}
		

		if(flag == 1)
		{
		   if(st.empty())
			   cout<<"YES"<<"\n";
		   else
			   cout<<"NO"<<"\n";
		}
		else
			cout<<"NO"<<"\n";
	}

	return 0;
}
