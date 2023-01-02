#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
HP* CreateHeap(HeapData x)
{
	HP* cur = (HP*)malloc(sizeof(HP));
	if (NULL == cur)//����ڴ�����ʧ��
	{
		perror("malloc");
		exit(-1);
	}
	cur->data = x;
	cur->LeftNode = cur->RightNode = NULL;
	return cur;
}
//ǰ�����
void FrontHeap(HP* head)
{
	if (NULL == head)//��������
	{
		return;
	}
	printf("%d ", head->data);//��
	FrontHeap(head->LeftNode);//������
	FrontHeap(head->RightNode);//������
}

void MiddleHeap(HP* head)//�������
{
	if (NULL == head)
	{
		return;
	}
	MiddleHeap(head->LeftNode);//������
	printf("%d ", head->data);//��
	MiddleHeap(head->RightNode);//������
}
void TailHeap(HP* head)//�������
{
	if (NULL == head)
	{
		return;
	}
	TailHeap(head->LeftNode);//������
	TailHeap(head->RightNode);//������
	printf("%d ", head->data);//��
}

//��������ڵ����
int HeapSize(HP* head)
{
	return head == NULL ? 0 : 
		HeapSize(head->LeftNode) + HeapSize(head->RightNode) + 1;
}

//�������Ҷ�ӽڵ����
int HeapLeafSize(HP* head)
{
	if (head == NULL)
	{
		return 0;
	}
	if (head->LeftNode == NULL && head->RightNode == NULL)
	{
		return 1;
	}
	return HeapLeafSize(head->LeftNode) + HeapLeafSize(head->RightNode);
}
//��������߶�
int Heaplen(HP* head)
{
	if (head == NULL)
	{
		return 0;
	}
	int left, right;
	left = Heaplen(head->LeftNode)+1;
	right = Heaplen(head->RightNode)+1;
	return left > right ? left : right;
}
int HeapLevelSize(HP* head, int k )//���������K��ڵ����
{
	if (NULL == head)
	{
		return 0;
	}
	if (k == 1)//˵�������k����
	{
		return 1;
	}
	//���K>1
	return HeapLevelSize(head->LeftNode, k - 1) + HeapLevelSize(head->RightNode, k - 1);
}