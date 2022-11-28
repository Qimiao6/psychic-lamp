#define _CRT_SECURE_NO_WARNINGS 1
#include"QL.h"

#include<stdio.h>
#include<string.h>

//层序遍历
void StOrder(TeDataType* x)
{
	assert(x);
	Node head;
	SLInit(&head);
	SLPush(&head,x);
	while (!SLEmpty(&head))//不为空进入
	{
		TeDataType* cur = SLFront(&head);//获取队中第一位
		printf("%d ", cur->data);//打印
		SLPop(&head);//出列
		if (cur->left)//如不为空入列
		{
			SLPush(&head, cur->left);//让他左节点入列
		}
		if (cur->right)//如不为空入列
		{
			SLPush(&head, cur->right);//让他的右节点入列
		}
	}
	printf("\n");
}

// 判断二叉树是否为完全二叉树
bool Entirely(TeDataType* x)
{
	assert(x);
	Node head;
	SLInit(&head);
	SLPush(&head, x);//pus第一位进去
	while (!SLEmpty(&head))
	{
		TeDataType* Front = SLFront(&head);//取头
		SLPop(&head);//删除头
		if (Front == NULL)
		{
			break;
		}
		else
		{
			SLPush(&head,Front->left);//把空也pus进去好用来判断
			SLPush(&head, Front->right);
		}
	}
	while (!SLEmpty(&head))
	{
		TeDataType* Front = SLFront(&head);//取头
		SLPop(&head);//删除头
		if (Front != NULL)
		{
			SLDestroy(&head);
			return false;
		}
	}
	SLDestroy(&head);
	return true;
}
//int main()
//{
//	TeDataType* n1 =  TreeInit(1);//创建二叉树节点
//	TeDataType* n2 = TreeInit(2);
//	TeDataType* n3 = TreeInit(3);
//	TeDataType* n4 = TreeInit(4);
//	TeDataType* n5 = TreeInit(5);
//	TeDataType* n6 = TreeInit(6);
//	TeDataType* n7 = TreeInit(7);
//	TeDataType* n8 = TreeInit(8);
//	n1->left = n2;
//	n1->right = n3;
//	n2->left = n4;
//	n2->right = n5;
//	n3->left = n6;
//	n3->right = n7;
//	//n6->left = n8;
//	StOrder(n1);//层序遍历
//	printf("%d", Entirely(n1)); //判断是否为完全二叉树
//	TreeDestroy(n1);
//	n1 = NULL;
//	return 0;
//}



//	排序
//向数组插入一个数并保持有序
//int main()
//{
//	
//	int arr[20] = { 2,5,6,8,9,11,44 };
//	int n = 1;
//	int size = 6;//数组最后一位的下标
//	while (size >= 0)
//	{
//		if (arr[size] > n)
//		{
//			arr[size + 1] = arr[size];
//			size--;
//		}
//		else
//		{
//			break;//如果把插入放这无法插入第一位
//		}
//	}
//	arr[size + 1] = n;
//	return 0;
//}


void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//直接插入排序

void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)//每次把i+1的下标作为需插入的数
	{
		int cur = arr[i + 1];
		int end = i;
		while (end >= 0)
		{
			if (arr[end] > cur)
			{
				arr[end + 1] = arr[end];//
				end--;  
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = cur;
	}
	//print(arr, size);
}

// 希尔排序
void ShellSort(int* arr, int size)
{

	int gap = size ;//分为三组
	while (gap > 1)//步距小于等于一说明上一次为一，不用再排了
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int cur = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > cur)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = cur;
		}
	}
	//print(arr, size);
}
// 测试排序的性能对比

int main()
{
	//int arr[11] = { 11,10,9,8,7,6,5,4,3,2,1 };
	int size = 11;
	//ShellSort(arr, size);
	//InsertSort(arr, size);
	TestOP();
	return 0;
}