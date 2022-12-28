#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef int TmData;

typedef struct TeamNode
{
	TmData data;//队的数据
	struct TeamNode* next;//链表指针
}TmNode;

typedef struct Team
{
	TmNode* head;//队头
	TmNode* tail;//队尾
	int size;//队内数据个数
}Team;
//由于单链表尾删不太方便，所以咱采用头删尾插的思路
void TmInit(Team* Tm);//初始化
void TmDestroy(Team* Tm);//销毁
void TmPus(Team* Tm,TmData data);//入队
void TmPop(Team* Tm);//出队
TmData TmHead(Team* Tm);//获取头部数据
TmData TmTail(Team* Tm);//获取尾部数据
int TmSize(Team* Tm);//获取队中数据个数
bool TmEmpty(Team* Tm);//判断队是否为空
