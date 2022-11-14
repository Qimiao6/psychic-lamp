#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
//�ӵ�����
typedef int TeDataType;
//������ʵ��
typedef struct team
{
	TeDataType data;//����
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
void SLPush(Node* Pteam, TeDataType x);
//����
void SLPop(Node* Pteam);
//�����Ƿ�Ϊ�գ�Ϊ�շ����棬��Ϊ�շ��ؼ�
bool SLEmpty(Node* Pteam);
//��ȡͷ��Ԫ��
TeDataType SLFront(Node* Pteam);
//��ȡβ��Ԫ��
TeDataType SLTail(Node* Pteam);
//���ٶ�
void SLDestroy(Node* Pteam);
//��ȡ�������ݸ���
int SLsize(Node* Pteam);
void SLInit(Node* Pteam)
{
	//assert(Pteam);
	Pteam->Front = NULL;
	Pteam->Tail = NULL;
	Pteam->size = 0;
}
void SLPush(Node* Pteam, TeDataType x)
{
	//assert(Pteam);
	Team* cur = (Team*)malloc(sizeof(Team));
	if (NULL == cur)
	{
		printf("malloc\n");
		exit(-1);
	}
	cur->data = x;
	cur->next = NULL;
	if (Pteam->Tail == NULL)
	{
		Pteam->Front = cur;
		Pteam->Tail = cur;
	}
	else
	{
		Pteam->Tail->next = cur;
		Pteam->Tail = cur;
	}
	Pteam->size++;
}
bool SLEmpty(Node* Pteam)
{
	//assert(Pteam);

	return Pteam->size == 0;
}
void SLPop(Node* Pteam)
{
	//assert(Pteam);
	//assert(!SLEmpty(Pteam));
	Team* cur = Pteam->Front->next;
	free(Pteam->Front);
	Pteam->Front = cur;
	if (NULL == cur)
	{
		Pteam->Tail = NULL;
	}
	Pteam->size--;
}
TeDataType SLFront(Node* Pteam)
{
	//assert(Pteam);
	//assert(!SLEmpty(Pteam));
	return Pteam->Front->data;
}
TeDataType SLTail(Node* Pteam)
{
	//assert(Pteam);
	//assert(!SLEmpty(Pteam));
	return Pteam->Tail->data;
}
void SLDestroy(Node* Pteam)
{
	//assert(Pteam);
	while (Pteam->Front)
	{
		Team* cur = Pteam->Front->next;
		free(Pteam->Front);
		Pteam->Front = cur;
	}
}
int SLsize(Node* Pteam)
{
	//assert(Pteam);

	return Pteam->size;
}
//////////////////////////////////////////////
typedef struct
{
	Node p1;
	Node p2;
} MyStack;
MyStack* myStackCreate()
{
	MyStack* cur = (MyStack*)malloc(sizeof(MyStack));
	SLInit(&cur->p1);//���ó�ʼ��
	SLInit(&cur->p2);//���ó�ʼ��
	return cur;
}

void myStackPush(MyStack* obj, int x)
{
	if (!SLEmpty(&obj->p1))//�����пգ�����뵽��Ϊ�յĶ���
	{
		SLPush(&obj->p1, x);
	}
	else
	{
		SLPush(&obj->p2, x);
	}
}

int myStackPop(MyStack* obj)
{
	Node* mpty = &obj->p1;
	Node* notmpty = &obj->p2;
	if (!SLEmpty(mpty))
	{
		Node* mpty = &obj->p2;
		Node* notmpty = &obj->p1;
	}
	//���ǿ����е�n-1�����е���ն����У����һ�����ز�pop
	while (SLsize(notmpty) > 1)
	{
		SLPush(mpty, SLFront(notmpty));
		SLPop(notmpty);
	}
  	int bb = SLFront(notmpty);
	SLPop(notmpty);
	return bb;
}

int myStackTop(MyStack* obj)
{

	if (!SLEmpty(&obj->p1))
	{
		return SLTail(&obj->p1);
	}
	else
	{
		return SLTail(&obj->p2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	return SLEmpty(&obj->p1) && SLEmpty(&obj->p2);
}
void myStackFree(MyStack* obj)
{
	SLDestroy(&obj->p1);
	SLDestroy(&obj->p2);
	free(obj);
}

int main()
{
	MyStack* pp = myStackCreate();
	myStackPush(pp, 1);
	myStackPush(pp, 2);
	myStackTop(pp);
	myStackPop(pp);
	myStackPop(pp);
		myStackEmpty(pp);
		return 0;
}
