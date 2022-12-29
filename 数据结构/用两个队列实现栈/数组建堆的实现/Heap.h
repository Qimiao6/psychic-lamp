#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HeapData;

typedef struct heap
{
	HeapData* data;
	int size;//实际数据个数
	int capacity;//空间容量
}HP;

void HpInit(HP* head);//初始化
void HpDestroy(HP* head);//销毁
void HpPus(HP* head, HeapData data);//插入数据
void print(HP* head);//打印
void HpPop(HP* head);//头删
void HpTop(HP* head);//查看头部数据
int Hpsize(HP* head);//查看数据个数