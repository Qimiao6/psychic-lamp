#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
HP* CreateHeap(HeapData x)
{
	HP* cur = (HP*)malloc(sizeof(HP));
	if (NULL == cur)//如果内存申请失败
	{
		perror("malloc");
		exit(-1);
	}
	cur->data = x;
	cur->LeftNode = cur->RightNode = NULL;
	return cur;
}
//前序遍历
void FrontHeap(HP* head)
{
	if (NULL == head)//遍历完了
	{
		return;
	}
	printf("%d ", head->data);//根
	FrontHeap(head->LeftNode);//左子树
	FrontHeap(head->RightNode);//右子树
}

void MiddleHeap(HP* head)//中序遍历
{
	if (NULL == head)
	{
		return;
	}
	MiddleHeap(head->LeftNode);//左子树
	printf("%d ", head->data);//根
	MiddleHeap(head->RightNode);//右子树
}
void TailHeap(HP* head)//后序遍历
{
	if (NULL == head)
	{
		return;
	}
	TailHeap(head->LeftNode);//左子树
	TailHeap(head->RightNode);//右子树
	printf("%d ", head->data);//根
}

//求二叉树节点个数
int HeapSize(HP* head)
{
	return head == NULL ? 0 : 
		HeapSize(head->LeftNode) + HeapSize(head->RightNode) + 1;
}

//求二叉树叶子节点个数
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
//求二叉树高度
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
int HeapLevelSize(HP* head, int k )//求二叉树第K层节点个数
{
	if (NULL == head)
	{
		return 0;
	}
	if (k == 1)//说明到达第k层了
	{
		return 1;
	}
	//如果K>1
	return HeapLevelSize(head->LeftNode, k - 1) + HeapLevelSize(head->RightNode, k - 1);
}