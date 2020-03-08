#include<iostream>
#include<cstring>

using namespace std;

char str[1000001]={0,};
int alphaset[123]={0,}; // ACSII A to z = 65~122

int main(void)
{
    int len=0;
    int AtoI=0;
    char ItoA=' ';
    int max=-1;
    int max_index=0;
    int unique=0;

    cin>>str;
    len = strlen(str);

    for(int i=0; i<len;i++)
    {
        AtoI=(int)str[i];

        if(AtoI>=97)
            AtoI-=32;

        alphaset[AtoI]++;
    }
//  for(int i=65; i<91; i++)
//      cout<<alphaset[i]<<" ";

//  cout<<"\n";
    for(int i=65; i<91; i++)
    {
        if(alphaset[i]>max)
        {
            max=alphaset[i];
            max_index=i;
        }
    }

    for(int i=65; i<91; i++)
        if(alphaset[i] == max)
            unique++;
//  cout<<"unique: "<<unique<<"\n";

    if(unique == 1)
    {
        ItoA=(char)max_index;
        printf("%c\n",ItoA);
    }
    else
        cout<<'?'<<'\n';

    return 0;
}
