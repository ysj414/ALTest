#include<iostream>

using namespace std;

int IsHanNum(int num);

int main(void)
{
	int N;
	int cnt=0;
	
	cin>>N;
	for(int i=N ; i>=1 ; i--)
	{
		if(IsHanNum(i))
			cnt++;
	}
	cout<<cnt<<"\n";

	return 0;
}


int IsHanNum(int num)
{
	int bak;
	int sip;
	int il;

	bak = num/100;
	if(bak != 0)
	{
		sip = (num/10)%10;
		il = num %10;
		if( (bak - sip) == (sip - il))
			return true;
		else
			return false;	
	}

	return true;

}
