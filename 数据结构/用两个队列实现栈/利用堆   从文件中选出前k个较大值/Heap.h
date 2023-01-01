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
	int size;//ʵ�����ݸ���
	int capacity;//�ռ�����
}HP; 

void HpInit(HP* head);//��ʼ��
void HpDestroy(HP* head);//����
void HpPus(HP* head, HeapData data);//��������
void print(HP* head);//��ӡ
void HpPop(HP* head);//ͷɾ
HeapData HpTop(HP* head);//�鿴ͷ������
int Hpsize(HP* head);//�鿴���ݸ���


/////////////////////////////////////
//���ļ�����ǰk���ϴ�ֵ
void HeapTop(HP* head);