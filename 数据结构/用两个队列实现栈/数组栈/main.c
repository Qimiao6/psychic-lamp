#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	//����һ��ջ
	STK head;
	//��ʼ��
	Init(&head);
	int i = 0;
	int x;
	do
	{
		printf("1 ѹջ    2 ��ջ  3 �鿴ջ��Ԫ��  4 Ԫ�ظ���   0 �˳�\n");
		printf("��������Ҫ�Ĺ���\n");
		scanf("%d", &i);
		if (i == 1)
		{
			printf("�������ջ������\n");
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
	//����ջ
	Destroy(&head);
	return 0;
}