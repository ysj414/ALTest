#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int main(void)
{

	while(1)
	{
		char buf[101];
		memset(buf,0,sizeof(buf));
		fgets(buf,100,stdin);
		stack<char> st;
		if(buf[0] == '.')
			break;
		int len = strlen(buf);
		int flag = 1;
		for(int i=0; i<len; i++)
		{
			if(buf[i] == '(' || buf[i] == '[')
				st.push(buf[i]);
			else if(buf[i] == ')')
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
			else if(buf[i] == ']')
			{
				if(st.empty())
				{
					flag = 0;
					break;
				}
				if(st.top() != '[')
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
				cout<<"yes"<<"\n";
			else
				cout<<"no"<<"\n";
		}
		else
			cout<<"no"<<"\n";

	}
	return 0;
}
