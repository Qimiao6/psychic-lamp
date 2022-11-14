#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
//队的数据
typedef int TeDataType;
//用链表实现
typedef struct team
{
	TeDataType data;//数据
	struct team* next;
}Team;

//队的头，尾指针和元素个数
typedef struct kk
{
	int size;//数据个数
	Team* Front;//头
	Team* Tail;//尾
}Node;
//为方便采用头删，尾插的队结构
// 头为队的出口，尾为队的入口
//初始化列表
void SLInit(Node* Pteam);
//入列
void SLPush(Node* Pteam, TeDataType x);
//出列
void SLPop(Node* Pteam);
//检测队是否为空，为空返回真，不为空返回假
bool SLEmpty(Node* Pteam);
//获取头部元素
TeDataType SLFront(Node* Pteam);
//获取尾部元素
TeDataType SLTail(Node* Pteam);
//销毁队
void SLDestroy(Node* Pteam);
//获取队中数据个数
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
	SLInit(&cur->p1);//调用初始化
	SLInit(&cur->p2);//调用初始化
	return cur;
}

void myStackPush(MyStack* obj, int x)
{
	if (!SLEmpty(&obj->p1))//调用判空，需插入到不为空的队中
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
	//将非空数列的n-1个队列导入空队列中，最后一个返回并pop
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
