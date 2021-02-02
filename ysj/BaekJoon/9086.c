#include<stdio.h>
#include<string.h>


int main(void)
{
	int T;
	char buf[1002];
	int len=0;
	scanf("%d", &T);

	while(T--)
	{
		memset(buf,0x0,sizeof(buf));
		scanf("%s",buf);
		printf("%c",buf[0]);
		len = strlen(buf);
		printf("%c\n",buf[len-1]);
	}

	return 0;
}
