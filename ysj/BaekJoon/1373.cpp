#include<iostream>
#include<cstring>

using namespace std;

#define BUF_SIZE 1000002
char bin[BUF_SIZE];
char octt[BUF_SIZE];
char result[BUF_SIZE];

int main(void)
{
	
	fgets(bin,BUF_SIZE,stdin);
	int len = strlen(bin);

	bin[len-1]='\0';
	len--;
	
	int loop = len/3;
	int fin = len%3;
	int cnt =0;
	for(int i=(len-1); i>0; i=i-3)
	{
		if(cnt == loop)
			break;
		int val = 0;
		char ch = '0';
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
	
		switch(val)
		{
			case 0:
			ch='0';
			break;
			case 1:
			ch='1';
			break;
			case 2:
			ch='2';
			break;
			case 3:
			ch='3';
			break;
			case 4:
			ch='4';
			break;
			case 5:
			ch='5';
			break;
			case 6:
			ch='6';
			break;
			case 7:
			ch='7';
			break;
			default:
			break;
		}
//		cout<<"val:"<<val<<"\n";
//		cout<<"ch:"<<ch<<"\n";
//		cout<<"cnt:"<<cnt<<"\n";
		octt[cnt]=ch;
		cnt++;
	}
    char ch;
	if(fin == 2)
	{
		if(bin[1] == '1')
		{
			if(bin[0] == '1')
			{
				ch='3';
				octt[cnt]=ch;
			}
			else
			{
				ch='1';
				octt[cnt]=ch;
			}
		}
		else
		{
			if(bin[0] =='1')
			{
				ch='2';
				octt[cnt]=ch;
			}
		}
	}
	else if(fin == 1)
	{
		if(bin[0] == '1')
		{
			ch='1';
			octt[cnt]=ch;
		}
	}
	printf("cnt: %d\n",cnt);
	for(int k=cnt; k>=0; k--)
	{
		printf("k %d c %c\n",k,octt[k]);
		result[cnt-k]=octt[k];
	}
/* 2021.01.19 00011000 => 030 to remove front 0
   atoi but not working well.*/

	int ans = atoi(result);
	cout<<ans<<"\n";


	return 0;
}
