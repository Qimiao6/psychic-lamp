#define _CRT_SECURE_NO_WARNINGS 1
#include"Team.h"


void TmInit(Team* Tm)//初始化
{
	assert(Tm);
	Tm->size = 0;
	Tm->head = NULL;
	Tm->tail = NULL;
}
void TmDestroy(Team* Tm)//销毁
{
	assert(Tm);
	TmNode* cur = Tm->head;
	while (cur)
	{
		TmNode* pp = cur;
		cur = cur->next;
		free(pp);//可不置空因为别人访问不到pp
	}
	Tm->head = NULL;
	Tm->tail = NULL;
}
void TmPus(Team* Tm, TmData data)//入队
{
	assert(Tm);
	TmNode* newNode = (TmNode*)malloc(sizeof(TmNode));
	if (newNode == NULL)//如果申请失败
	{
		perror("malloc");
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;
	if (Tm->head == NULL)
	{
		Tm->head = newNode;
		Tm->tail = newNode;
	}
	else
	{
		Tm->tail->next = newNode;
		Tm->tail = newNode;
	}
	Tm->size++;
}
bool TmEmpty(Team* Tm)//判断队是否为空
{
	assert(Tm);
	return !Tm->size;//队内无数据返回真
}
void TmPop(Team* Tm)//出队
{
	assert(Tm);
	if (TmEmpty(Tm))
	{
		printf("队内无数据\n");
			return;
	}
	TmNode* cur = Tm->head;
	Tm->head = Tm->head->next;//头删
	free(cur);
	if (Tm->head == NULL)//如果已经删完了
	{
		Tm->tail = NULL;
	}
	Tm->size--;
}
TmData TmHead(Team* Tm)//获取头部数据
{
	assert(Tm);
	if (TmEmpty(Tm))
	{
		printf("队内无数据\n");
		return -1;
	}
	return Tm->head->data;

}
TmData TmTail(Team* Tm)//获取尾部数据
{
	assert(Tm);
	if (TmEmpty(Tm))
	{
		printf("队内无数据\n");
		return -1;
	}
	return Tm->tail->data;
}
int TmSize(Team* Tm)//获取队中数据个数
{
	assert(Tm);
	return Tm->size;
}
