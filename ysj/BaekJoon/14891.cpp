#include <iostream>
using namespace std;

int wheel[4][8];

void Rotate_Wheel(int num, int dir)
{
	int temp[4][8]={0,};
	int IsRotate[4] = {0,};
	int Dir[4] = {0,};
	int i, j;

	if (num == 1)
	{
		IsRotate[0] = 1;
		Dir[0] = dir;
		if (wheel[0][2]!=wheel[1][6])
		{
			IsRotate[1] = 1;
			Dir[1] = Dir[0]*(-1);
			if (wheel[1][2] != wheel[2][6])
			{
				IsRotate[2] = 1;
				Dir[2] = Dir[1]*(-1);
				if(wheel[2][2] != wheel[3][6])
				{
					IsRotate[3] = 1;
					Dir[3] = Dir[2] * (-1);
				}
			}

		}
	}
	else if (num == 2)
	{
		IsRotate[1] = 1;
		Dir[1] = dir;
		if (wheel[1][2] != wheel[2][6])
		{
			IsRotate[2] = 1;
			Dir[2] = Dir[1] * (-1);
			if (wheel[2][2] != wheel[3][6])
			{
				IsRotate[3] = 1;
				Dir[3] = Dir[2] * (-1);
			}
		}
		if (wheel[0][2] != wheel[1][6])
		{
			IsRotate[0] = 1;
			Dir[0] = Dir[1] * (-1);
		}
	}
	else if (num == 3)
	{
		IsRotate[2] = 1;
		Dir[2] = dir;
		if (wheel[2][6] != wheel[1][2])
		{
			IsRotate[1] = 1;
			Dir[1] = Dir[2] * (-1);
			if (wheel[1][6] != wheel[0][2])
			{
				IsRotate[0] = 1;
				Dir[0] = Dir[1] * (-1);
			}
		}
		if (wheel[2][2] != wheel[3][6])
		{
			IsRotate[3] = 1;
			Dir[3] = Dir[2] * (-1);
		}
	}
	else if (num == 4)
	{
		IsRotate[3] = 1;
		Dir[3] = dir;
		if (wheel[2][2] != wheel[3][6])
		{
			IsRotate[2] = 1;
			Dir[2] = Dir[3] * (-1);
			if (wheel[2][6] != wheel[1][2])
			{
				IsRotate[1] = 1;
				Dir[1] = Dir[2] * (-1);
				if (wheel[1][6] != wheel[0][2])
				{
					IsRotate[0] = 1;
					Dir[0] = Dir[1] * (-1);
				}
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (IsRotate[i] == 1)
		{
			if (Dir[i] == 1)
			{
				temp[i][0] = wheel[i][7];
				temp[i][1] = wheel[i][0];
				temp[i][2] = wheel[i][1];
				temp[i][3] = wheel[i][2];
				temp[i][4] = wheel[i][3];
				temp[i][5] = wheel[i][4];
				temp[i][6] = wheel[i][5];
				temp[i][7] = wheel[i][6];
			}
			else if (Dir[i] == -1)
			{
				temp[i][0] = wheel[i][1];
				temp[i][1] = wheel[i][2];
				temp[i][2] = wheel[i][3];
				temp[i][3] = wheel[i][4];
				temp[i][4] = wheel[i][5];
				temp[i][5] = wheel[i][6];
				temp[i][6] = wheel[i][7];
				temp[i][7] = wheel[i][0];
			}
		}
	}
	for (i = 0; i < 4;i++)
	{
	  if(IsRotate[i] == 1)
	  {
		for (j = 0; j < 8;j++)
			wheel[i][j] = temp[i][j];
	  }
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k,t;
	int i, j;
	int rotate;
	int answer = 0;
	char temp[9];
	int val;

	for (i=0;i<4;i++)
	{
		cin>>temp;
		for(j= 0;j < 8;j++)
			wheel[i][j]=temp[j]-'0';
	}
	cin >> k;
	while (k > 0)
	{
		cin >> t >> rotate;
		Rotate_Wheel(t, rotate);
		k--;
	}
	answer = 1*(wheel[0][0])+2*(wheel[1][0])+4*(wheel[2][0])+8*(wheel[3][0]);
	cout << answer << "\n";

	return 0;
}
