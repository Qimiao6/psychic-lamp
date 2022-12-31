#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void HpInit(HP* head)//��ʼ��
{
	assert(head);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void HpDestroy(HP* head)//����
{
	assert(head);
	free(head->data);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void print(HeapData* data , int size)//��ӡ
{
	assert(data);
	int i = 0;
	printf("\n");
	while (i < size)
	{
		printf("%d ",data[i]);
		if (i != 0 && i % 20 == 0)
		{
			printf("\n");
		}
		i++;
	}
}
void Sawp(HeapData* arr, int x, int y)
{
	HeapData ch = arr[x];
	arr[x] = arr[y];
	arr[y] = ch;
}
void AdjustDown(HeapData* arr,int parent, int size)
{
	int leftson = parent * 2 + 1;//����
	while (leftson < size)//
	{
		if (leftson + 1 < size && arr[leftson + 1] > arr[leftson])
		{
			leftson++;//����Һ��Ӵ�������
		}
		if (arr[leftson] < arr[parent])//�������С�ڸ���
		{
			break;
		}
		Sawp(arr, leftson, parent);
		parent = leftson;
		leftson = parent * 2 + 1;
	}
}
void CreateHeap(HP* head, int* arr, int size)
{
	assert(head);
	int parent, son = size - 1;
	head->data = (HeapData*)malloc(sizeof(int) * size);//������ĸ��ƿ��ٿռ�
	if (NULL == head->data)//�������ʧ��
	{
		perror("malloc");
		exit(-1);
	}
	memcpy(head->data, arr, sizeof(int) * size);//������Ҫ���ѵ�����
	head->capacity = head->size = size;//������
	for (parent = (son - 1) / 2; parent >= 0; parent--)//�����һ�����־ݵĸ��׿�ʼ����
	{
		AdjustDown(head->data, parent,head->size);//�����ڵ��׵�ַ����ȥ
	}
}

//������
void HeapSort(int* arr, int size)
{
	assert(arr);
	int parent, son = size - 1;
	for (parent = (son - 1) / 2; parent >= 0; parent--)//�����һ�����ݵĸ��׿�ʼ����
	{
		AdjustDown(arr, parent, size);//�����ڵ��׵�ַ����ȥ
	}
	//�����ǽ��ѣ�������Ҫ���ж�����
	int Hpsize = size-1;//�������һλ
	for (Hpsize; Hpsize > 0; Hpsize--)
	{
		Sawp(arr, 0, Hpsize);//ÿ�ν��ϴ�ֵ�������һλ
		AdjustDown(arr, 0 , Hpsize);//����������,�������ոջ�����һλ
	}
}