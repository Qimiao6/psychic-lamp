#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

int main()
{
	HP head;
	HpInit(&head);
	int i = 0;
	int x = 0;
	do
	{
		printf("\n1 ����  2 ɾ��  3 ��ӡ  4 �鿴ͷ������ \n");
		printf("��������Ҫ�Ĺ���\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("����������\n");
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
			HpTop(&head);
			break;
		}

	} while (i);
}