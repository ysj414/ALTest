#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	int digit[4];
	int a,b;
	int len=0;
	cin>>a>>b;

	int temp=a;
	for(int i=0;i<4;i++)
	{
		len++;
	    if((temp<10))
		{
			digit[i]=temp;
			break;
		}
		else
		{
			digit[i]=temp%10;
			temp=temp/10;
		}
	}

//	cout<<"len:"<<len<<"\n";
//	for(int i=0;i<len;i++)
//		cout<<digit[i]<<"\n";
	if(len*a<=b)
	{
		for(int i=0;i<a;i++)
			cout<<a;
		cout<<"\n";
	}
	else
	{
		int cnt = b/len;
		int frag = b%len;
		for(int i=0;i<cnt;i++)
			cout<<a;
		for(int j=0;j<frag;j++)
			cout<<digit[len-1-j];
		cout<<"\n";
	}

	return 0;
}
