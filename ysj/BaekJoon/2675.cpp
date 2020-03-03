#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{       
        int N;
        char P[200];
        int cnt;
        int len;
        int rotate;
        cin>>N;
        for(int i=0; i<N;i++)
        {
                char S[20];
		int R=0;
          	memset(P,0,sizeof(P));
                cin>>R>>S;
                len=strlen(S);
                rotate=0;

                for(int j=0; j<len;j++)
                {
                        for(int k=0; k<R;k++)
                                P[k+rotate]=S[j];
                        
			rotate=rotate+R;
                }

          cout<<P<<"\n";
        }

        
        
        
        return 0;
}

