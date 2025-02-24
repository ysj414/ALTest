#include<stdio.h>

int main(void)
{
	int hw[31]={0,};
	int input = 28;
	int num = 0;
	int i = 0;

	while(input--)
	{
		scanf("%d",&num);
		hw[num] = 1;
	}

	for(i = 1; i<31; i++)
		if(hw[i] == 0)
			printf("%d\n",i);

	return 0;
}
