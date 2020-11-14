#include<iostream>

using namespace std;

int main(void)
{
	
  int N;
  cin>>N;
  int is_cute=0;
  for(int i=0; i<N; i++)
  {
   int cute;
   cin>>cute;
   if(cute)
     is_cute++;
   else
     is_cute--;
  }
  if(is_cute > 0)
	  cout<<"Junhee is cute!"<<"\n";
  else
	  cout<<"Junhee is not cute!"<<"\n";


return 0;
}
