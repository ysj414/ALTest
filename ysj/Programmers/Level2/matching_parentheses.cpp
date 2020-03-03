#include<cstring>
#include<iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> str;
    int i=0;
    
    str.push(s[0]);
    if(str.top() == ')')
    {
        answer=false;
        return answer;
    }
    
    for(int j=1; j<s.size();j++)
    {
        if(s[j]==')')
        {
            if(str.empty())
            {
                answer=false;
                return answer;
                
            }
            else
            {
                if(str.top()=='(')
                    str.pop();
            }
        }
        else
        {
            str.push(s[j]);
        }
    }
    if(!str.empty())
        answer=false;

    return answer;
}
