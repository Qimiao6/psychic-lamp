#define _CRT_SECURE_NO_WARNINGS 1
#include"Team.h"

void main()
{
	Team Q1;
	TmInit(&Q1);//��ʼ��
	int i = 0;
	int x = 0;
	do
	{
		printf("  1 ���  2 ����  3 �鿴ͷ������  \n");
		printf("  4 �鿴β������  5 �鿴�������ݸ���  0 �˳�\n");
		printf("��������Ҫ�Ĺ���=>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("����������=>");
			scanf("%d", &x);
			TmPus(&Q1,x);//���
			break;
		case 2:
			TmPop(&Q1);//����
			break;
		case 3:
			printf("%d", TmHead(&Q1));//�鿴ͷ������
			break;
		case 4:
			printf("%d", TmTail(&Q1));//�鿴β������
			break; 
		case 5:
			printf("%d", TmSize(&Q1));; //�鿴ͷ������
				break;
		}

	} while (i);
}