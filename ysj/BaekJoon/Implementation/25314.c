#include<stdio.h>

char digit[6]="long ";

int main(void)
{
	int num = 0;
	
	scanf("%d", &num);
	num = num/4;

	while(num--)
	{
		printf("%s", digit);
	}

	printf("int\n");

	return 0;
}
