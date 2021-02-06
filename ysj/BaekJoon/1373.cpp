#include<iostream>
#include<cstring>

using namespace std;

#define BUF_SIZE 1000002
char bin[BUF_SIZE];

int main(void)
{
	
	fgets(bin,BUF_SIZE,stdin);
	int len = strlen(bin);
	int result=0;

	bin[len-1]='\0';
	len--;
	
	int loop = len/3;
	int fin = len%3;
	int cnt =0;
	int decimal = 1;
	for(int i=(len-1); i>0; i=i-3)
	{
		if(cnt == loop)
			break;
		int val = 0;
		if(bin[i] == '1')
		{
			val+=1;             // case 
			if(bin[i-1] =='1')
			{
				val+=2;
				if(bin[i-2] =='1') // case 
					val+=4;
				
			}
			else
			{
				if(bin[i-2] =='1') // case 
					val+=4;
			}
		}
		else
		{
			if(bin[i-1] == '1')
			{
				val+=2;           // case 
				if(bin[i-2] == '1') // case 
					val+=4;
			}
			else
			{	
				if(bin[i-2] == '1') // case 
					val+=4;
				else
					val=0;  // case 
			}
		}
		cout<<"val:"<<val<<"\n";
		cout<<"dec:"<<decimal<<"\n";
		if(decimal == 1)
			result+=val;
		else
			result+=decimal*val;
		cnt++;
		decimal*=10;
	}

	if(fin == 2)
	{
		if(bin[1] == '1')
		{
			if(bin[0] == '1')
				result+=decimal*3;
			else
				result+=decimal*1;
		}
		else
		{
			if(bin[0] =='1')
				result+=decimal*2;
		}
	}
	else if(fin == 1)
	{
		if(bin[0] == '1')
			result+=decimal*1;
	}
	else
		result+=decimal*0;
		
	cout<<result<<"\n";

	return 0;
}
