#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define CMD_MOVECURSOR (0)
#define CMD_REVERT (1)
#define CMD_INPUT (2)
#define CMD_GETSUBSTRING (9)

int N;
static int score, curScore;

extern void init();
extern void cmd_input(char ch[]);
extern void cmd_revert();
extern void cmd_movecursor(int mCursor);
extern void get_substring(int mPosition,int mLength,char res[]);
void make_intput()
{
	char ch[30];
	scanf("%s",ch);
	cmd_input(ch);
}

static void run() 
{
	char ori[35],res[35];
	scanf("%d",&N);
	init();
	
	for(int i = 0; i < N;i++)
	{
		int cmd;
		scanf("%d",&cmd);
		if(cmd == CMD_INPUT)
		{
			make_intput();
		}else if(cmd == CMD_MOVECURSOR)
		{
			int pos;
			scanf("%d",&pos);
			cmd_movecursor(pos);
		}else if(cmd == CMD_GETSUBSTRING)
		{
			int pos,len;
			scanf("%d%d%s",&pos,&len,ori);
			get_substring(pos,len,res);
			if(strcmp(ori,res) != 0)
			{
				curScore = 0;
			}
		}
	}
}
int main()
{
	setbuf(stdout,NULL);
	//freopen("sampel_input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int tc = 1;tc<=T;tc++)
	{
		curScore = 100;
		run();
		printf("#%d %d\n",tc,curScore);
		score += curScore;
	}
	printf("Total Score = %d\n",score);
	return 0;
}