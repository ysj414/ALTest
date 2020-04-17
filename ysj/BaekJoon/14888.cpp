#include<iostream>

using namespace std;

int N;
int num[11];
char str[10];
int max_val=-999999999;
int min_val=999999999;
void swap(char *a, char *b);
void calculate();
void permutation(int K);
int main(void)
{
	cin>>N;
	int a,b,c,d;

	for(int i=0;i<N;i++)
	 cin>>num[i];

	cin>>a>>b>>c>>d;
	for(int j=0;j<a;j++)
		str[j]='+';
	for(int j=a;j<a+b;j++)
		str[j]='-';
	for(int j=a+b;j<a+b+c;j++)
		str[j]='*';
	for(int j=a+b+c;j<a+b+c+d;j++)
		str[j]='/';

	permutation(N-1);
	cout<<max_val<<"\n"<<min_val<<"\n";
	return 0;
}
void swap(char *a, char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void calculate()
{
	int a=num[0];
	for(int i=1; i<N;i++)
	{
		int tmp_n=num[i];
		char tmp_str=str[i-1];
		if(tmp_str =='+')
			a+=tmp_n;
		else if(tmp_str =='-')
			a-=tmp_n;
		else if(tmp_str =='*')
			a*=tmp_n;
		else if(tmp_str =='/')
		{
			if(a < 0)
			{
				a=-a;
				a=a/tmp_n;
				a=-a;				
			}
			else
				a=a/tmp_n;
		}
	}
	if(a>max_val)
		max_val=a;
	if(a<min_val)
		min_val=a;

}
void permutation(int K)
{
	if(K == 0)
		calculate();
	for(int i=0; i<K; i++)
	{
		swap(&str[i],&str[K-1]);
		permutation(K-1);
		swap(&str[i],&str[K-1]);
	}

}
