#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>
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
HeapData HpTop(HP* head);//查看头部数据
int Hpsize(HP* head);//查看数据个数


/////////////////////////////////////
//在文件中找前k个较大值
void HeapTop(HP* head);