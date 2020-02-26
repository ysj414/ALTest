#include<iostream>

using namespace std;

int IsConstructor(int num);

int main(void)
{

	int i;
	int ans;

	for(i=1; i<=10000; i++)
	{
		ans = IsConstructor(i);
		if(!ans)
			cout<<i<<"\n";
	}



	return 0;
}

int IsConstructor(int num)
{
	int temp_num = num;
	int digit[5];
	int i;
	
	for(i=1; i<= 45; i++)
	{
		--temp_num;
		if(temp_num < 1)
			return false;
		
		digit[0] = temp_num/10000;
		digit[1] = (temp_num/1000)%10;
		digit[2] = (temp_num/100)%10;
		digit[3] = (temp_num/10)%10;
		digit[4] = temp_num%10;

		if( (temp_num + digit[0]+digit[1]+digit[2]+digit[3]+digit[4]) == num )
			return true;
		
	}
	
	return false;


}


