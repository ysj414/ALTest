#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{
	char grade[3];
	float score=0;
	cin>>grade;
	switch(grade[0])
	{
		case 'A':
			score+=4;
			break;
		case 'B':
			score+=3;
			break;
		case 'C':
			score+=2;
			break;
		case 'D':
			score+=1;
			break;
		default:
			break;
	}
	switch(grade[1])
	{
		case '+':
			score+=0.3;
			break;
		case '-':
			score-=0.3;
			break;
	}
	printf("%.1f\n",score);	

	return 0;
}
