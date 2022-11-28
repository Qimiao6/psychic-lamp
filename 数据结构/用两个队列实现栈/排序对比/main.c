#define _CRT_SECURE_NO_WARNINGS 1
#include"QL.h"

#include<stdio.h>
#include<string.h>

//�������
void StOrder(TeDataType* x)
{
	assert(x);
	Node head;
	SLInit(&head);
	SLPush(&head,x);
	while (!SLEmpty(&head))//��Ϊ�ս���
	{
		TeDataType* cur = SLFront(&head);//��ȡ���е�һλ
		printf("%d ", cur->data);//��ӡ
		SLPop(&head);//����
		if (cur->left)//�粻Ϊ������
		{
			SLPush(&head, cur->left);//������ڵ�����
		}
		if (cur->right)//�粻Ϊ������
		{
			SLPush(&head, cur->right);//�������ҽڵ�����
		}
	}
	printf("\n");
}

// �ж϶������Ƿ�Ϊ��ȫ������
bool Entirely(TeDataType* x)
{
	assert(x);
	Node head;
	SLInit(&head);
	SLPush(&head, x);//pus��һλ��ȥ
	while (!SLEmpty(&head))
	{
		TeDataType* Front = SLFront(&head);//ȡͷ
		SLPop(&head);//ɾ��ͷ
		if (Front == NULL)
		{
			break;
		}
		else
		{
			SLPush(&head,Front->left);//�ѿ�Ҳpus��ȥ�������ж�
			SLPush(&head, Front->right);
		}
	}
	while (!SLEmpty(&head))
	{
		TeDataType* Front = SLFront(&head);//ȡͷ
		SLPop(&head);//ɾ��ͷ
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
//	TeDataType* n1 =  TreeInit(1);//�����������ڵ�
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
//	StOrder(n1);//�������
//	printf("%d", Entirely(n1)); //�ж��Ƿ�Ϊ��ȫ������
//	TreeDestroy(n1);
//	n1 = NULL;
//	return 0;
//}



//	����
//���������һ��������������
//int main()
//{
//	
//	int arr[20] = { 2,5,6,8,9,11,44 };
//	int n = 1;
//	int size = 6;//�������һλ���±�
//	while (size >= 0)
//	{
//		if (arr[size] > n)
//		{
//			arr[size + 1] = arr[size];
//			size--;
//		}
//		else
//		{
//			break;//����Ѳ�������޷������һλ
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
//ֱ�Ӳ�������

void InsertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)//ÿ�ΰ�i+1���±���Ϊ��������
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

// ϣ������
void ShellSort(int* arr, int size)
{

	int gap = size ;//��Ϊ����
	while (gap > 1)//����С�ڵ���һ˵����һ��Ϊһ������������
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
// ������������ܶԱ�

int main()
{
	//int arr[11] = { 11,10,9,8,7,6,5,4,3,2,1 };
	int size = 11;
	//ShellSort(arr, size);
	//InsertSort(arr, size);
	TestOP();
	return 0;
}