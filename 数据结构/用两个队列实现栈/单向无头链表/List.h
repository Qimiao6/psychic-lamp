#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

/////////////////////////////

//¡¥±Ì
typedef int SListData;
typedef struct list
{
	SListData data;
	struct list* next;
}SList;

///////////////////////////
//Œ≤≤Â
void STLPusList(SList** Phead, SListData data);
//Œ≤…æ
void STLPosList(SList** Phead);
//≤È’“
SList* Find(SList* Phead, SListData val);
//Õ∑≤Â
void pushead(SList** Phead, SListData data);