#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HeapData;

typedef struct Heap
{
	HeapData data;
	struct Heap* LeftNode;
	struct Heap* RightNode;
}HP;

HP* CreateHeap(HeapData x);//�����������ڵ�

void FrontHeap(HP* head);//ǰ�����
void MiddleHeap(HP* head);//�������
void TailHeap(HP* head);//�������
int HeapSize(HP* head);//��������ڵ����
int HeapLeafSize(HP* head);//�������Ҷ�ӽڵ����
int Heaplen(HP* head);//��������߶�
int HeapLevelSize(HP* head , int k);//���������K��ڵ����