#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void HpInit(HP* head)//初始化
{
	assert(head);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void HpDestroy(HP* head)//销毁
{
	assert(head);
	free(head->data);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void print(HeapData* data , int size)//打印
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
	int leftson = parent * 2 + 1;//左孩子
	while (leftson < size)//
	{
		if (leftson + 1 < size && arr[leftson + 1] > arr[leftson])
		{
			leftson++;//如果右孩子大于左孩子
		}
		if (arr[leftson] < arr[parent])//如果孩子小于父亲
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
	head->data = (HeapData*)malloc(sizeof(int) * size);//给数组的复制开辟空间
	if (NULL == head->data)//如果开辟失败
	{
		perror("malloc");
		exit(-1);
	}
	memcpy(head->data, arr, sizeof(int) * size);//拷贝需要建堆的数组
	head->capacity = head->size = size;//开区间
	for (parent = (son - 1) / 2; parent >= 0; parent--)//传最后一个数字据的父亲开始建堆
	{
		AdjustDown(head->data, parent,head->size);//将父节点首地址传过去
	}
}

//堆排序
void HeapSort(int* arr, int size)
{
	assert(arr);
	int parent, son = size - 1;
	for (parent = (son - 1) / 2; parent >= 0; parent--)//传最后一个数据的父亲开始建堆
	{
		AdjustDown(arr, parent, size);//将父节点首地址传过去
	}
	//上面是建堆，下面需要进行堆排序
	int Hpsize = size-1;//数组最后一位
	for (Hpsize; Hpsize > 0; Hpsize--)
	{
		Sawp(arr, 0, Hpsize);//每次将较大值换到最后一位
		AdjustDown(arr, 0 , Hpsize);//交换完后调整,不调整刚刚换的那一位
	}
}