#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
//�����������Ͻ���

//���Ѻ�����Ӧ���ƺ��ٽ��ѣ����ƻ�ԭ������
//Top����
//pop����
typedef int HeapData;

typedef struct heap
{
	HeapData* data;
	int size;//ʵ�����ݸ���
	int capacity;//�ռ�����
}HP;
void CreateHeap(HP* head, int* arr, int size);//������������Ͻ���
void print(HeapData* head, int size);//��ӡ
void HpInit(HP* head);//��ʼ��
void HpDestroy(HP* head);//����
void HeapSort(int* arr, int size);//��������ж�����