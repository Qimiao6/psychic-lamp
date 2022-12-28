#define _CRT_SECURE_NO_WARNINGS 1
#include"Team.h"

void main()
{
	Team Q1;
	TmInit(&Q1);//初始化
	int i = 0;
	int x = 0;
	do
	{
		printf("  1 入队  2 出队  3 查看头部数据  \n");
		printf("  4 查看尾部数据  5 查看队中数据个数  0 退出\n");
		printf("请输入需要的功能=>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("请输入数据=>");
			scanf("%d", &x);
			TmPus(&Q1,x);//入队
			break;
		case 2:
			TmPop(&Q1);//出队
			break;
		case 3:
			printf("%d", TmHead(&Q1));//查看头部数据
			break;
		case 4:
			printf("%d", TmTail(&Q1));//查看尾部数据
			break; 
		case 5:
			printf("%d", TmSize(&Q1));; //查看头部数据
				break;
		}

	} while (i);
}