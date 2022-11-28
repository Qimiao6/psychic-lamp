#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
//���µ���
void AjustDown(int* head, int parent, int size);//���飬���ڵ㣬Ԫ�ظ���
//����
void Swp(int* head, int son, int parent);
//����
void TreeCreate(int* arr, int size);
//Top���ֵ
int TreeTop(int* arr, int size);


/// /////////////

void TestOP();//���ܲ���

//β��ͷ��
typedef int TreeDataType;
typedef struct cc
{
	TreeDataType data;//����
	struct cc* left;//ͷ
	struct cc* right;//β
}TeDataType;
//�ӵ�����
//typedef int TeDataType;
//������ʵ��
typedef struct team
{
	TeDataType* data;//����
	struct team* next;
}Team;

//�ӵ�ͷ��βָ���Ԫ�ظ���
typedef struct kk
{
	int size;//���ݸ���
	Team* Front;//ͷ
	Team* Tail;//β
}Node;
//Ϊ�������ͷɾ��β��Ķӽṹ
// ͷΪ�ӵĳ��ڣ�βΪ�ӵ����
//��ʼ���б�
void SLInit(Node* Pteam);
//����
void SLPush(Node* Pteam, TeDataType* x);
//����
void SLPop(Node* Pteam);
//�����Ƿ�Ϊ�գ�Ϊ�շ����棬��Ϊ�շ��ؼ�
bool SLEmpty(Node* Pteam);
//��ȡͷ��Ԫ��
TeDataType* SLFront(Node* Pteam);
//��ȡβ��Ԫ��
TeDataType* SLTail(Node* Pteam);
//���ٶ�
void SLDestroy(Node* Pteam);
//��ȡ�������ݸ���
int SLsize(Node* Pteam);


////////////////////////////
TeDataType* TreeInit(TreeDataType x);//�����������ڵ�
//���ٶ�����
void TreeDestroy(TeDataType* n1);


///////////////////////

// ϣ������
void ShellSort(int* arr, int size);
//ֱ�Ӳ�������

void InsertSort(int* arr, int size);