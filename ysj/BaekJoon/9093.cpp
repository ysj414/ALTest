#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{

	int n;
	cin>>n;
	cin.ignore();
//	getchar();
	while(n--)
	{
	  char buf[1001];	
	  fgets(buf,1001,stdin);
	  char *s1 = buf;
	  char *s2 = strchr(buf,' ');

	  while(s2 != NULL)
	  {
		  char res[21]={0,};
		  int size = (int)(s2-s1);
		  for(int i = 0; i<size; i++)
			  res[i] = s1[size-1-i];
		  s1=s2+1;
		  s2 = strchr(s2+1,' ');
		  cout<<res<<" ";
	  }
	   int size = strlen(s1)-1;
	   s1[size]='\0';
	   for(int i = 0; i<size/2;i++)
	   {
		   char temp = s1[i];
		   s1[i] = s1[size-1-i];
		   s1[size-1-i] = temp;
	   }
	   cout<<s1<<"\n";
	}


	return 0;

}
