#define _CRT_SECURE_NO_WARNINGS 1
#include"Team.h"


void TmInit(Team* Tm)//��ʼ��
{
	assert(Tm);
	Tm->size = 0;
	Tm->head = NULL;
	Tm->tail = NULL;
}
void TmDestroy(Team* Tm)//����
{
	assert(Tm);
	TmNode* cur = Tm->head;
	while (cur)
	{
		TmNode* pp = cur;
		cur = cur->next;
		free(pp);//�ɲ��ÿ���Ϊ���˷��ʲ���pp
	}
	Tm->head = NULL;
	Tm->tail = NULL;
}
void TmPus(Team* Tm, TmData data)//���
{
	assert(Tm);
	TmNode* newNode = (TmNode*)malloc(sizeof(TmNode));
	if (newNode == NULL)//�������ʧ��
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
bool TmEmpty(Team* Tm)//�ж϶��Ƿ�Ϊ��
{
	assert(Tm);
	return !Tm->size;//���������ݷ�����
}
void TmPop(Team* Tm)//����
{
	assert(Tm);
	if (TmEmpty(Tm))
	{
		printf("����������\n");
			return;
	}
	TmNode* cur = Tm->head;
	Tm->head = Tm->head->next;//ͷɾ
	free(cur);
	if (Tm->head == NULL)//����Ѿ�ɾ����
	{
		Tm->tail = NULL;
	}
	Tm->size--;
}
TmData TmHead(Team* Tm)//��ȡͷ������
{
	assert(Tm);
	if (TmEmpty(Tm))
	{
		printf("����������\n");
		return -1;
	}
	return Tm->head->data;

}
TmData TmTail(Team* Tm)//��ȡβ������
{
	assert(Tm);
	if (TmEmpty(Tm))
	{
		printf("����������\n");
		return -1;
	}
	return Tm->tail->data;
}
int TmSize(Team* Tm)//��ȡ�������ݸ���
{
	assert(Tm);
	return Tm->size;
}
