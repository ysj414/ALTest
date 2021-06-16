#include<iostream>


using namespace std;

#define DO 		"A"
#define GAE 	"B"
#define GEOL	"C"
#define YOOT	"D"
#define MO		"E"

int main(void)
{

	int result = 0;
	int Y[4];
	for(int i=0;i<3;i++)
	{
		scanf("%d %d %d %d",&Y[0],&Y[1],&Y[2],&Y[3]);
		result =Y[0]+Y[1]+Y[2]+Y[3];
		switch(result)
		{
			case 0:
				printf("%s\n",YOOT);
				break;
			case 1:
				printf("%s\n",GEOL);
				break;
			case 2:
				printf("%s\n",GAE);
				break;
			case 3:
				printf("%s\n",DO);
				break;
			case 4:
				printf("%s\n",MO);
				break;
			default:
				break;
		}
	}

	return 0;
}
