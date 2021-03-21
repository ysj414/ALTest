#include<stdio.h>
#include<string.h>


char alpha[27]="nopqrstuvwxyzabcdefghijklm";
char Alpha[27]="NOPQRSTUVWXYZABCDEFGHIJKLM";
int main(void)
{
	char buf[105];
	int len=0;
	int i;
		
    fgets(buf,105,stdin);
	len = strlen(buf);
	buf[len-1]='\0';
	len--;
	for(i=0;i<len;i++)
	{
		if(buf[i]>=65 && buf[i]<=90)
		{
			buf[i]=Alpha[buf[i]-65];
		}
		else if(buf[i]>=97 && buf[i]<=122)
		{
			buf[i]=alpha[buf[i]-97];
		}
	}

	printf("%s\n",buf);

	return 0;
}

