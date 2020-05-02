#include<iostream>

using namespace std;
int calnum(int n,int k)
{ 
    if(k==1)
	return 1;
    if(n==0)
        return k;

    return (calnum(n-1,k)+calnum(n,k-1));
    
}
int main(void)
{
    int T,n,k;
    
    cin>>T;
    
    while(T--)
    {
      cin>>n;
      cin>>k;
      int ans=calnum(n,k);
      cout<<ans<<"\n";
    }
    
   
    return 0;
}
