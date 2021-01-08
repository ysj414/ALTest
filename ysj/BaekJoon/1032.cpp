#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{

  int n;
  cin>>n;
  char result[51]={0,};

  cin>>result;
  n--;
 
  while(n--)
  {
	char input[51];
	cin>>input;
    int len = strlen(input);
	for(int i=0; i<len; i++)
	{
      if(result[i] != input[i])
		result[i]  = '?';
    }
  }

  cout<<result<<"\n";

return 0;
}
