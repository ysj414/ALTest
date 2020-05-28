#include<iostream>
#include<cstring>
using namespace std;
 
char pool[100002];
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        char* answer=NULL;
        int ans=1;
        memset(pool,0,sizeof(pool));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            if(!pool[temp])
                pool[temp]=true;
            else
            {
                ans=0;
            }
        }
         
        if(ans)
            answer="Yes";
        else
            answer="No";
         
        cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
