#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{

	char buf[51];
	int min=0;
	cin>>buf;
	int len =strlen(buf);

	char flag='+';  // 0 : '+' 1 : '-'
	char op = '+';
	for(int i=0; i<len; i++)
	{
		
		if(buf[i] == '+')
		{
			op = '+';
		}
		else if(buf[i] == '-')
		{
			op = '-';
		}
		else
		{
			int j;
			char num[6]={0,};
			int cnt=0;
			for(j=i;j<i+5;j++)
			{
				if((buf[j] != '+') && (buf[j] != '-'))
					num[j-i]=buf[j];
				else
					break;
				cnt++;
			}
			int n = atoi(num);
			if(flag == '+')
			{
				if(op == '+')
					min+=n;
				else
				{
					min-=n;
					flag='-';
				}
			}
			else
			   min-=n;
			i+=cnt-1;
		}
	}
	cout<<min<<"\n";


	return 0;
}
