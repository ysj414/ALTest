#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	while(1)
	{
	  char buf[100000];
	  cin>>buf;
	  if(buf[0] == '0')
		break;
	  int len = strlen(buf);
	  int flag = 1;
	  for(int i=0;i<len/2;i++)
	  {
		 if(buf[i] != buf[len-1-i])	
		 {
			flag = 0;
			break;	
         }
	  }
	 if(flag)
	  cout<<"yes"<<"\n";
     else
	  cout<<"no"<<"\n";
	}

	return 0;
}
