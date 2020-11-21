#include<iostream>
#include<cstring>

#define MIN	0

using namespace std;

int main(void)
{
	char A[51];
	char B[51];
	char C[51];

	cin>>A>>B;
	int len = strlen(B)-strlen(A)+1;	
//	cout<<"len:"<<len<<"\n";
	int min = strlen(A);
	for(int i=0; i<len; i++)
	{
	  int count = 0;
	  memset(C,0,sizeof(C));
	  for(int j=0; j<strlen(A); j++)
	  {
		C[j]=B[j+i];
		if(C[j] != A[j])
			count++;
	  }
//	  cout<<"count:"<<count<<"\n";
	  if(count < min)
	  {
		min = count;
		if(min == MIN)
			break;
	  }
	}	
	cout<<min<<"\n";

	return 0;
}
