#include<stdio.h>

int main(void)
{
	int halestone;
	int max;
	int testcase;
	scanf("%d", &testcase);

	while(testcase--)
	{
		max=1;
		scanf("%d", &halestone);

		while(halestone != 1)
		{
			if(halestone>max)
				max=halestone;

			if(halestone % 2 == 0)
				halestone = halestone/2;
			else
				halestone= halestone*3 +1;
		}
	printf("%d\n",max);
	}
	return 0;
}
