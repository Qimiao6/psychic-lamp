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
	int size;//ʵ��������
	int capacity;//��������
}STK;
//��ʼ��
void Init(STK* head);
//ѹջ
void PusStack(STK* head, StackData data);
//��ջ
void PosStack(STK* head);
//�鿴ջ��Ԫ��
void Lookhead(STK* head);
//�鿴ջԪ�ظ���
int SizeStack(STK* head);