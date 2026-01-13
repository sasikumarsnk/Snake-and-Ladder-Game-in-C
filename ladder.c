#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void display_ladder(int play_1,int play_2)
{
	int ladder[10][10] = {
		{1,2,3,4,5,6,7,8,9,10},
		{20,19,18,17,16,15,14,13,12,11},
		{21,22,23,24,25,26,27,28,29,30},
		{40,39,38,37,36,35,34,33,32,31},
		{41,42,43,44,45,46,47,48,49,50},
		{60,59,58,57,56,55,54,53,52,51},
		{61,62,63,64,65,66,67,68,69,70},
		{80,79,78,77,76,75,74,73,72,71},
		{81,82,83,84,85,86,87,88,89,90},
		{100,99,98,97,96,95,94,93,92,91}
	};
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<10;j++)
		{
			if(ladder[i][j]==play_1 && ladder[i][j] == play_2)
			{
				printf("p12 ");
				continue;
			}
			else if(ladder[i][j] == play_1)
			{
				printf("\033[31m%s \033[0m","#p1");
				continue;
			}
			else if(ladder[i][j]==play_2)
			{
				printf("\033[32m%s \033[0m","#p2");
				continue;
			}

			if(ladder[i][j]< 10)
				printf("%d   ",ladder[i][j]);
			else if(ladder[i][j]<100)
				printf("%d  ",ladder[i][j]);
			else
				printf("%d ",ladder[i][j]);
		}
		printf("\n");
	}
}

int dice()
{
	int ret;
	srand(time(NULL));
	ret = (rand()%6)+1;
	return ret;
}

int game(int cur_pos,int dice)
{
	int check=cur_pos+dice;
	if(check == 9)
		return 27;
	else if(check == 16)
		return 7;
	else if(check == 18)
		return 37;
	else if(check ==28)
		return 51;
	else if(check == 59)
		return 17;
	else if(check ==63)
		return 19;
	else if(check == 56)
		return 64;
	else if(check == 67)
		return 30;
	else if(check == 68)
		return 88;
	else if(check == 79)
		return 100;
	else if(check == 76)
		return 97;
	else if(check == 87)
		return 24;
	else if(check == 93)
		return 69;
	else if(check == 95)
		return 75;
	else if(check==99)
		return 77;
	if(check > 100)
		return cur_pos;
}
int main()
{
	char rot;
	int dice_val;
	int play_1=0,play_2=0;
	int play_change=0;
	printf("Welcome to Snake & Ladder Game\n");
	while(play_1!=100&&play_2!=100)
	{
		scanf(" %c",&rot);
		if(play_change==0)
		{
			dice_val = dice();
			play_1 = game(play_1,dice_val);
			printf("player_1 dice val :%d\n",dice_val);
			play_change =1;
		}
		else if(play_change == 1)
		{
			dice_val = dice();
			play_2 = game(play_2,dice_val);
			printf("player_2 dice val :%d\n",dice_val);
			play_change =0;
		}
		display_ladder(play_1,play_2);
	}
	if(play_1 ==100)
		printf("Player 1 Winner\n");
	else
		printf("Player 2 Winner\n");

}
