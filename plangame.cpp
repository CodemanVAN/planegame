#include<Windows.h>
#include<stdlib.h>
#include <iostream>
#include<conio.h>
#include<time.h>
#define high 20
#define width 20
using namespace std;
int step=1;
int scores = 0,dif=1;
int map[high+1][width+1];
int bx, by;
class plan
{
public:
	int x, y;
	plan() 
	{
		x = high / 2;
		y = width / 2;
	}
	void planfire()
	{
		bx = x - 1, by = y;
		map[bx][by] = 3;
	}

};
class eplan 
{
public:
	int x, y;
	int health;
	eplan() 
	{
		x = 1;
		y = rand()%(width-1)+1;
		health = 50;
	}
	void fire()
	{
		map[x + 1][y] = 5;
	}

};
void input(plan &ME) 
{
	char c;
	if (_kbhit())
	{
		c = _getch();
		if (c == 'w' || c == 'W') 
		{
			if(ME.x!=1)
			{
				map[ME.x][ME.y] = 0;
				ME.x--;
			}
		
		}
		if (c == 's' || c == 'S')
		{
			if (ME.x != high-1) {
				map[ME.x][ME.y] = 0;
				ME.x++;
			}
		}
		if (c == 'a' || c == 'A')
		{
			if (ME.y != 1)
			{
				map[ME.x][ME.y] = 0;
				ME.y--;
			}
		}
		if (c == 'd' || c == 'D')
		{
			if (ME.y != width-1) 
			{
				map[ME.x][ME.y] = 0;
				ME.y++;
		}
		}
		if (c == ' ')
		{
			ME.planfire();

		}
	}
}
void drawmap()
{
	system("cls");
	for (int i = 1; i < high+1; i++)
	{
		for (int j = 1; j < width+1; j++)
		{
			if (map[i][j] == 1)
			{
				printf("*");
			}
			else if (map[i][j] == 2)
			{
				printf("$");
			}
			else if (map[i][j] == 3)
			{
				printf("|");
				map[i-1][j] = 3;
				map[i][j] = 0;
			}
			else if (map[i][j] == 5)
			{
				printf("+");
			}
			else if (j ==width)
			{
				printf("!");
			}
			else if (i == high) 
			{
				printf("_");
			}
			else printf(" ");
		}
		 printf("\n");
	}
}
void noinput(plan &ME,eplan &emy)
{
	for (int i = 0; i < high; i++)
	{
		for (int j = 0; j < width; j++)
		{
			 if (i==ME.x&&j==ME.y)
			{
				map[i][j] = 1;
			}
			else if (i==emy.x&&j==emy.y)
			{
				map[i][j] = 2;
			}
		}
	}
}
void judge(plan& ME, eplan& emy) 
{
	if (ME.x == emy.x && ME.y == emy.y||emy.x==width+1)
			 {
			 system("cls");
			 printf("GAME OVER\nYour scores is: %d",scores);
			 getchar();
			 exit(0);
			 }
	for (int i = 1; i < high + 1; i++)
	{
		for (int j = 1; j < width + 1; j++)
		{
			if (map[i][j] == 2 && map[i + 1][j] == 3)
			{
				emy.x = 1, emy.y = rand() % (width-1) + 1;
				map[i + 1][j] = 0;
				map[i][j] = 0;
				scores++;
			}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	plan ME;
	eplan emy;
	while (1) 
	{
		drawmap();
		input(ME);
		noinput(ME,emy);
		step=step+dif;
		judge(ME, emy);
		dif = scores / 5;
		if (step > 15)
		{
			map[emy.x][emy.y] = 0;
				emy.x++;
				step = 0;
		}
		printf("得分：%d\n", scores);
		cout << "切换到英文输入法，空格开火，w,s,a,d移动，HAVE FUN！\nMade by 这风吹得我真冷\nPersonal Blog:https://codemanvan.github.io\n" << endl;
	}
}