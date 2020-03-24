#include<iostream>
#include<cstring>
using namespace std;



int main(void)
{
	char str[101];
	cin>>str;
	int sum=1;
	int len = strlen(str);

	for(int i=1; i<len; i++)
	{
		if(str[i]=='=')
		{
			if(str[i-1] == 'c' || str[i-1] == 's')
				continue;
			else if(str[i-1] =='z')
			{
				if(i-2>=0)
				{
				  if(str[i-2] =='d')
					  sum--;
				  else
					  continue;
				}
				else
					continue;

			}
			else
				sum++;
		}
		else if(str[i]=='-')
		{
			if(str[i-1]=='c' || str[i-1] =='d')
				continue;
			else
				sum++;
		}
		else if(str[i]=='j')
		{
			if(str[i-1] == 'n' || str[i-1] =='l')
				continue;
			else
				sum++;
		}
		else
			sum++;
	
	}
	cout<<sum<<"\n";



	return 0;

}

