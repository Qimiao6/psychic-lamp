#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//����ڵ�
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
//β��
void STLPusList(SList** Phead, SListData data)
{
	assert(Phead);
	//�ȴ���ڵ�
	SList* NewNode = CreateSList(data);
	if (*Phead == NULL)//�������Ϊ��
	{
		*Phead = NewNode;
		return;
	}
	SList* cur = *Phead;
	while (cur->next)//��β
	{
		cur = cur->next;
	}
	cur->next = NewNode;//β������
}
//ͷ��
void pushead(SList** Phead, SListData data)
{
	assert(Phead);
	//�ȴ���ڵ�
	SList* NewNode = CreateSList(data);
	if (*Phead == NULL)//�������Ϊ��
	{
		*Phead = NewNode;
		return;
	}
	SList* cur = *Phead;
	*Phead = NewNode;
	NewNode->next = cur;

}
//βɾ
void STLPosList(SList** Phead)
{
	assert(Phead);
	if (*Phead == NULL)
	{
		printf("�޿�ɾ����\n");
		return;
	}
	if ((*Phead)->next == NULL)
	{
		*Phead = NULL;
		printf("ɾ���ɹ�\n");
		return;
	}
	SList* cur = *Phead,* cur2;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	cur2 = cur->next;//�����һ������
	cur->next = NULL;//���βɾ
	free(cur2);//����ɾ���ڵ��ڴ��ͷ�
	printf("ɾ���ɹ�\n");
}
//����
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
	printf("�Ҳ���\n");
	return NULL;
}
//�޸�
void Amend(SList* Phead, SListData new)
{
	assert(Phead);
	Phead->data = new;
	printf("�޸ĳɹ�");
}
