#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

/////////////////////////////

//����
typedef int SListData;
typedef struct list
{
	SListData data;
	struct list* next;
}SList;

///////////////////////////
//β��
void STLPusList(SList** Phead, SListData data);
//βɾ
void STLPosList(SList** Phead);
//����
SList* Find(SList* Phead, SListData val);
//ͷ��
void pushead(SList** Phead, SListData data);