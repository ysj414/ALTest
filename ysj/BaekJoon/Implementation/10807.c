#include <stdio.h>

int num_arr[201] = {0};
int main(void)
{
	int N = 0;
	int input_num = 0;
	int find_num = 0;

	scanf("%d",&N);

	while(N--)
	{
		scanf("%d",&input_num);
		if(input_num >=0)
			num_arr[input_num]++;
		else
			num_arr[100+input_num*-1]++;
	}

	scanf("%d",&find_num);
	if(find_num >=0)
		printf("%d\n",num_arr[find_num]);
	else
		printf("%d\n",num_arr[find_num*-1 + 100]);

	return 0;
}
