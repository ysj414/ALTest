#include<iostream>
#include<cstring>

using namespace std;

int alpha[123]={0,};
int ans[32]={0,};

int main(void)
{
	char *p=NULL;
	char buf[102];
	do
	{
		memset(buf,0,sizeof(buf));
		p = fgets(buf,100,stdin);
		int len = strlen(buf);
		for(int i=0; i<len;i++)
		{
			if(buf[i]>=97 && buf[i]<=122)
				alpha[(int)buf[i]]++;
		}
//	if(buf[0]=='\n')
//		break;
	}while(p!=NULL);
	int m_index=97;
	for(int i=98; i<=122; i++)
	{
		if(alpha[i]>alpha[m_index])
			m_index=i;
	}		
	for(int i=97; i<=122;i++)
	{
		if(alpha[m_index] == alpha[i])
			printf("%c",(char)i);
	}
	printf("\n");

	return 0;
}
