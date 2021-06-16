#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void move_pos(char *position, char how);

int main(void)
{
    char king[2],stone[2];
	int count;
	char move[5];
	scanf("%c%c %c%c %d",&king[1],&king[0],&stone[1],&stone[0],&count);
	while(count--)
	{
		memset(move,0x0,sizeof(move));
		scanf("%s",move);
//		printf("input: %s\n",move);
		int len = strlen(move);
		char next_king[2], next_stone[2];
		next_king[0]=king[0],next_king[1]=king[1],next_stone[0]=stone[0],next_stone[1]=stone[1];

//		printf("input:%c\n",move[0]);
		if(len == 1)
		{
			move_pos(next_king, move[0]);
		}
		else
		{
			move_pos(next_king, move[0]);
			move_pos(next_king, move[1]);
		}
		if(next_king[0] == stone[0] && next_king[1] == stone[1])
		{
			if(len == 1)
			{
				move_pos(next_stone,move[0]);
			}
			else
			{
				move_pos(next_stone,move[0]);
				move_pos(next_stone,move[1]);
			}
		}
//		printf("%d %d\n", (int)next_king[0],(int)next_king[1]);

		if((next_king[0]-49) < 0 || (next_king[0]-49) >= 8)
			continue;
		if((next_king[1]-65) < 0 || (next_king[1]-65) >= 8)
			continue;
		if((next_stone[0]-49) < 0 || (next_stone[0]-49) >= 8)
			continue;
		if((next_stone[1]-65) < 0 || (next_stone[1]-65) >= 8)
			continue;

		king[0]=next_king[0];
		king[1]=next_king[1];
		stone[0]=next_stone[0];
		stone[1]=next_stone[1];
		
//	    printf("debug: %c%c\n%c%c\n",king[1],king[0],stone[1],stone[0]);
	}
	printf("%c%c\n%c%c\n",king[1],king[0],stone[1],stone[0]);

	return 0;
}

void move_pos(char *position, char how)
{
	if(how == 'R')
		position[1]++;
	else if(how == 'L')
		position[1]--;
	else if(how == 'B')
		position[0]--;
	else if(how =='T')
		position[0]++;
}
