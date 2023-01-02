#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

int main()
{
	HP *p1, * p2, * p3, * p4, * p5, * p6, * p7, * p8;
	p1 = CreateHeap(10);//创建节点
	p2 = CreateHeap(20);
	p3 = CreateHeap(30);
	p4 = CreateHeap(40);
	p5 = CreateHeap(50);
	p6 = CreateHeap(60);
	p7 = CreateHeap(70);
	p8 = CreateHeap(80);
	p1->LeftNode = p2;
	p1->RightNode = p3;
	p2->LeftNode = p4;
	p2->RightNode = p5;
	p3->LeftNode = p6;
	p3->RightNode = p7;
	p4->LeftNode = p8;
	FrontHeap(p1);
	printf("\n");
	MiddleHeap(p1);
	printf("\n");
	TailHeap(p1);
	printf("\n");
	printf("%d ", HeapSize(p1));
	printf("\n叶节点个数=>%d ", HeapLeafSize(p1));
	printf("\n树的高度=>%d ", Heaplen(p1)); 
	printf("\n第K层节点个数=>%d ", HeapLevelSize(p1,2));
	return 0;
}