#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void Text1()
{
	HP head;
	HpInit(&head);
	int i = 0;
	int x = 0;
	do
	{
		printf("\n1 插入  2 删除  3 打印  4 查看头部数据 \n");
		printf("请输入需要的功能\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("请输入数据\n");
			scanf("%d", &x);
			HpPus(&head, x);
			break;
		case 2:
			HpPop(&head);
			break;
		case 3:
			print(&head);
			break;
		case 4:
			printf("%d", HpTop(&head));
			break;
		}

	} while (i);
}
void Text2()
{
	HP head;
	HpInit(&head);
	HeapTop(&head);//从文件中选出前K个较大值
	print(&head);
	HpDestroy(&head);
}
int main()
{
	//Text1();
	Text2();
	return 0;
}