#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//创造节点
SList* CreateSList(SListData data)
{
	SList* cur = (SList*)malloc(sizeof(SList));
	if (NULL == cur)
	{
		perror("malloc");
		exit(-1);
	}
	cur->data = data;
	cur->next = NULL;
	return cur;
}
//尾插
void STLPusList(SList** Phead, SListData data)
{
	assert(Phead);
	//先创造节点
	SList* NewNode = CreateSList(data);
	if (*Phead == NULL)//如果链表为空
	{
		*Phead = NewNode;
		return;
	}
	SList* cur = *Phead;
	while (cur->next)//找尾
	{
		cur = cur->next;
	}
	cur->next = NewNode;//尾部插入
}
//头插
void pushead(SList** Phead, SListData data)
{
	assert(Phead);
	//先创造节点
	SList* NewNode = CreateSList(data);
	if (*Phead == NULL)//如果链表为空
	{
		*Phead = NewNode;
		return;
	}
	SList* cur = *Phead;
	*Phead = NewNode;
	NewNode->next = cur;

}
//尾删
void STLPosList(SList** Phead)
{
	assert(Phead);
	if (*Phead == NULL)
	{
		printf("无可删数据\n");
		return;
	}
	if ((*Phead)->next == NULL)
	{
		*Phead = NULL;
		printf("删除成功\n");
		return;
	}
	SList* cur = *Phead,* cur2;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	cur2 = cur->next;//存最后一个数据
	cur->next = NULL;//完成尾删
	free(cur2);//将被删除节点内存释放
	printf("删除成功\n");
}
//查找
SList* Find(SList* Phead,SListData val)
{
	assert(Phead);
	SList* cur = Phead;
	while (cur)
	{
		if (cur->data == val)
			return cur;
		else
			cur = cur->next;
	}
	printf("找不到\n");
	return NULL;
}
//修改
void Amend(SList* Phead, SListData new)
{
	assert(Phead);
	Phead->data = new;
	printf("修改成功");
}
