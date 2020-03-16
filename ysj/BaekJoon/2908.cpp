#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{
        int a,b;
        char temp;
        char c[4];
        char d[4];

        cin>>c;
        cin>>d;

        temp=c[2];
        c[2]=c[0];
        c[0]=temp;

        temp=d[2];
        d[2]=d[0];
        d[0]=temp;

        a=atoi(c);
        b=atoi(d);

        if(a>b)
           cout<<a<<"\n";
        else
           cout<<b<<"\n";

        return 0;
}
