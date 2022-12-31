#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
//在已有数组上建堆

//建堆函数，应复制后再建堆，不破坏原有数据
//Top函数
//pop函数
typedef int HeapData;

typedef struct heap
{
	HeapData* data;
	int size;//实际数据个数
	int capacity;//空间容量
}HP;
void CreateHeap(HP* head, int* arr, int size);//在无序二叉树上建堆
void print(HeapData* head, int size);//打印
void HpInit(HP* head);//初始化
void HpDestroy(HP* head);//销毁
void HeapSort(int* arr, int size);//对数组进行堆排序