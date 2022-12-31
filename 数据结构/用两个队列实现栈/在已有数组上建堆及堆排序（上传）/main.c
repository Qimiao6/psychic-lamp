#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void Text1()//传数组直接建堆
{
	HP head;
	HpInit(&head);
	int arr[] = { 4,2,77,22,1,66,33,8,97,68,6,13,99,55,61,85 };
	CreateHeap(&head, arr , sizeof(arr) / sizeof(arr[0]));
	print(head.data , sizeof(arr) / sizeof(arr[0]));
	HeapSort(arr , sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
	HpDestroy(&head);
}
int main()
{
	Text1();
	return 0;
}