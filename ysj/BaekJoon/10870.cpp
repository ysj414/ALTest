#include<iostream>

using namespace std;

int Fibo(int num);
int main(void)
{
	int n;
	cin>>n;

	int result=Fibo(n);
	cout<<result<<"\n";

	return 0;
}
int Fibo(int num)
{
	if(num == 0)
		return 0;
	else if(num == 1)
		return 1;
	else
	{
		return (Fibo(num-1)+Fibo(num-2));
	}

}
