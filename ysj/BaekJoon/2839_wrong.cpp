#include<iostream>

using namespace std;

int main(void)
{
    int N;
    int cnt=0;
    int div;
    int mod;
    cin>>N;

    div = N/5;
    mod = N%5;
    if(mod == 0)
    {
        cout<<div<<"\n";
        return 0;
    }
    else
    {
        mod = mod%3;
        if(mod == 0)
        {
            cout<<div+1<<"\n";
            return 0;
        }
    }

    div = N/8;
    mod = N%8;
    if(mod == 0)
    {
        cout<<div*2<<"\n";
        return 0;
    }
    else
    {
        if(mod % 5 == 0)
        {
          mod=mod/5;
          cnt=div*2+mod;
          cout<<cnt<<"\n";
          return 0;
        }
        else if( mod % 3 == 0)
        {
            mod = mod/3;
            cnt = div*2+mod;
            cout<<cnt<<"\n";
            return 0;
        }
    }
    div = N/3;
    mod = N%3;
    if(mod == 0)
    {
        cout<<div<<"\n";
        return 0;
    }

    cout<<-1<<"\n";





    return 0;
}
