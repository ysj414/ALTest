#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{

	char input[110];
	cin>>input;

	int cnt=0;
	for(int i=0; i<strlen(input); i++)
		if(input[i] == 'a'|| input[i] == 'e' || input[i] == 'o' || input[i] == 'i' || input[i] == 'u')
			cnt++;
	cout<<cnt<<"\n";



	return 0;
}
