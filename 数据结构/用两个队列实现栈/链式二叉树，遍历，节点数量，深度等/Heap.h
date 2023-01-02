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

HP* CreateHeap(HeapData x);//创建二叉树节点

void FrontHeap(HP* head);//前序遍历
void MiddleHeap(HP* head);//中序遍历
void TailHeap(HP* head);//后序遍历
int HeapSize(HP* head);//求二叉树节点个数
int HeapLeafSize(HP* head);//求二叉树叶子节点个数
int Heaplen(HP* head);//求二叉树高度
int HeapLevelSize(HP* head , int k);//求二叉树第K层节点个数