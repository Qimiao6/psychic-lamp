#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef int TmData;

typedef struct TeamNode
{
	TmData data;//�ӵ�����
	struct TeamNode* next;//����ָ��
}TmNode;

typedef struct Team
{
	TmNode* head;//��ͷ
	TmNode* tail;//��β
	int size;//�������ݸ���
}Team;
//���ڵ�����βɾ��̫���㣬�����۲���ͷɾβ���˼·
void TmInit(Team* Tm);//��ʼ��
void TmDestroy(Team* Tm);//����
void TmPus(Team* Tm,TmData data);//���
void TmPop(Team* Tm);//����
TmData TmHead(Team* Tm);//��ȡͷ������
TmData TmTail(Team* Tm);//��ȡβ������
int TmSize(Team* Tm);//��ȡ�������ݸ���
bool TmEmpty(Team* Tm);//�ж϶��Ƿ�Ϊ��
