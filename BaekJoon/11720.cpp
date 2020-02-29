#include<iostream>
#include<cstring>
using namespace std;


int main(void)
{
	int n;
	char a[100];
	int sum=0;

	cin>>n;
	cin>>a;

	for(int i = 0; i<n; i++)
	  sum+=(a[i]-48);	
	cout<<sum<<"\n";
		
	return 0;
}

/* 
 * First Idea
 *  Use atoi library function
 *  In this case,however, exceed the limit of int, long, long long type memory
 *  This is a critical problem
 * Second Idea
 *  Use property of ASCII
 *  the string only included number 0 to 9
 *  the value of 0 in the ASCII is 48 
 *  So we can get integer value by substracting 0 in the string
 *
 */


