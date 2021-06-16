#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int n1, n2;
	char buf1[105];
	char buf2[105];
	char result[210];
	int i,j;
	char temp;
	int T,temp_T;
	scanf("%d %d",&n1, &n2);

	scanf("%s",buf1);
	scanf("%s",buf2);
	scanf("%d",&T);


	for(i=0; i<n1/2; i++)
	{
		temp = buf1[i];
		buf1[i]=buf1[strlen(buf1)-1-i];
		buf1[strlen(buf1)-1-i]=temp;
	}
	
	temp_T=T;
	for(i=n1-1; i>=0; i--)
	{
		if(temp_T>0)
			result[i+temp_T]=buf1[i];
		else
			result[i]=buf1[i];
		temp_T--;
	}

	temp_T=T;
	for(i=0; i<n2; i++)
	{
		if(temp_T>0)
			result[n1+i-temp_T]=buf2[i];
		else
			result[n1+i]=buf2[i];
		temp_T--;
	}
	printf("%s\n",result);
	 
	return 0;
}
