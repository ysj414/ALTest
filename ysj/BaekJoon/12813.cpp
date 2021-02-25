#include<iostream>
#include<cstring>

using namespace std;

char buf1[100002];
char buf2[100002];
char result[100002];

char AND(char a, char b);
char OR(char a, char b);
char XOR(char a, char b);
char NOT(char a);

int main(void)
{
	cin>>buf1>>buf2;

	for(int i=0; i<strlen(buf1); i++)	
		result[i]=AND(buf1[i],buf2[i]);	
	cout<<result<<"\n";
	memset(result,0x0,sizeof(result));

	for(int i=0; i<strlen(buf1); i++)
		result[i]=OR(buf1[i],buf2[i]);
	cout<<result<<"\n";
	memset(result,0x0,sizeof(result));

	for(int i=0; i<strlen(buf1); i++)
		result[i]=XOR(buf1[i],buf2[i]);
	cout<<result<<"\n";
	memset(result,0x0,sizeof(result));

	for(int i=0; i<strlen(buf1); i++)
		result[i]=NOT(buf1[i]);
	cout<<result<<"\n";

	memset(result,0x0,sizeof(result));
	for(int i=0; i<strlen(buf2); i++)
		result[i]=NOT(buf2[i]);
	cout<<result<<"\n";

	return 0;
}

char AND(char a, char b)
{
	if(a=='1' && b=='1')
		return '1';
	else
		return '0';
}

char OR(char a, char b)
{
	if(a=='1' || b=='1')
		return '1';
	else
		return '0';
}

char XOR(char a, char b)
{
	if((a=='1' && b=='0')||(a=='0' && b=='1'))
		return '1';
	else
		return '0';
}

char NOT(char a)
{
	if(a=='0')
		return '1';
	else
		return '0';
}

