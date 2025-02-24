#include<stdio.h>

char words[1001];

int main(void)
{
	int pos;

	scanf("%s", words);
	scanf("%d", &pos);

	printf("%c\n",words[pos-1]);

	return 0;
}
