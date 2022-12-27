#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	//创建一个栈
	STK head;
	//初始化
	Init(&head);
	int i = 0;
	int x;
	do
	{
		printf("1 压栈    2 出栈  3 查看栈顶元素  4 元素个数   0 退出\n");
		printf("请输入需要的功能\n");
		scanf("%d", &i);
		if (i == 1)
		{
			printf("请输入进栈的数据\n");
			scanf("%d", &x);
			PusStack(&head, x);
		}
		if (i == 2)
		{
			PosStack(&head);
		}
		if (i == 3)
		{
			Lookhead(&head);
		}
		if (i == 4)
		{
			SizeStack(&head);
		}
	} while (i);
	//销毁栈
	Destroy(&head);
	return 0;
}