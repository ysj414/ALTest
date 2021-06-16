#include<stdio.h>


int ChartoInt(char ch)
{
	switch(ch)
	{
		case 'A':
			return 0;
		case 'G':
			return 1;
		case 'C':
			return 2;
		case 'T':
			return 3;
		default:
			return -1;
	}
}

int main(void)
{
	char matrix[4][5]={{'A','C','A','G','\0'},{'C','G','T','A','\0'},
						{'A','T','C','G','\0'},{'G','A','G','T','\0'}};

	char buf[1000001];
	int len;

	scanf("%d", &len);
	scanf("%s",buf);

	for(int i=len-1; i>0; i--)
	{
		int p=ChartoInt(buf[i]);
		int q=ChartoInt(buf[i-1]);
		char trans = matrix[p][q];
		buf[i-1]=trans;
	}

	printf("%c\n",buf[0]);

	return 0;
}
