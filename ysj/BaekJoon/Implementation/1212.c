#include<stdio.h>
#include<string.h>

char eightdigit[333335];
char transform[8][4] = {
	{"000"},
	{"001"},
	{"010"},
	{"011"},
	{"100"},
	{"101"},
	{"110"},
	{"111"}};   
// if arr size is [8][3] no space to save NULL '\0'

int main(void)
{
	int i = 0;
	int len = 0;
	scanf("%s", eightdigit);

	len = strlen(eightdigit);
	if (eightdigit[0] == '0')
		printf("%s", "0");
	else if(eightdigit[0] == '1')
		printf("%s", "1");
	else if(eightdigit[0] == '2')
		printf("%s", "10");
	else if(eightdigit[0] == '3')
		printf("%s", "11");
	else
		printf("%s", transform[eightdigit[0]-'0']);
	
	for(i = 1; i<len; i++)
		printf("%s", transform[eightdigit[i]-'0']);
	
	return 0;
}
