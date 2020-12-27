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
		stack<char> st;


/*	 문제가 되는 부분	
		scanf("%c", &buf[0]);
		if(buf[0] == '.')
			break;
		for(int i = 1 ; i< 100; i++)
		{
			scanf("%c",&buf[i]);
			if(buf[i] == '.')
					break;
		}
*/
	    while(1)
		{
		  char buf2[101]={0,};
		  fgets(buf2,101,stdin);
		  int len = strlen(buf2);
		  if(buf2[0] == '.')
			return 0;

		  buf2[len-1]='\0'; 
		  if(buf2[len-2] == '.')
		  {
			strncat(buf,buf2,len);
			break;
		  } 
	      else
			strcat(buf,buf2);
		}

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
