#include<iostream>

using namespace std;

#define ASC		1
#define DES		2
#define MIXED	3


int main(void)
{              
	int asc[8]={1,3,6,10,15,21,28,36};
	int des[8]={8,15,21,26,30,33,35,36};

	int flag=0;  // 1 asc 2 des 3 mix
	int num,sum=0;
	for(int i=0;i<8;i++)
	{
		cin>>num;
		sum+=num;
		
		if(i == 7)
		{
			if(sum != 36)
			{ 
				flag=MIXED;
				break;
			}
		  break;
		}
		if(sum == asc[i])
			flag = ASC;
		else if(sum == des[i])
			flag = DES;
		else
			flag = MIXED;
		
		if(flag == MIXED)
			break;
	}
	
	if(flag == ASC)
		cout<<"ascending"<<"\n";
	else if(flag == DES)
		cout<<"descending"<<"\n";
	else
		cout<<"mixed"<<"\n";
}


