#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
//////////////////////////////////////////////////////////

typedef int StackData;

typedef struct Stack
{
	StackData* data;
	int size;//实际数据量
	int capacity;//数据容量
}STK;
//初始化
void Init(STK* head);
//压栈
void PusStack(STK* head, StackData data);
//出栈
void PosStack(STK* head);
//查看栈顶元素
void Lookhead(STK* head);
//查看栈元素个数
int SizeStack(STK* head);