#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//��ʼ��
void Init(STK* head)
{
	StackData* cur = (StackData*)malloc(sizeof(StackData) * 4);
	if (NULL == cur)
	{
		//����˵���ڴ�����ʧ��
		perror("malloc");
		exit(-1);
	}
	head->data = cur;
	head->capacity = 4;
	head->size = 0;
}
//�ж�ջ�Ƿ�Ϊ��
bool EmptyStack(STK* head)
{
	return !head->size;//Ϊ�շ�����
}
//����
void Create(STK* head)
{
	StackData* cur = (StackData*)realloc(head,sizeof(StackData) * (head->capacity + 2));
	if (NULL == cur)
	{
		//����˵���ڴ�����ʧ��
		perror("realloc");
		exit(-1);
	}
	head->data = cur;
	head->capacity = head->capacity + 2;
}
//ѹջ
void PusStack(STK* head ,StackData data)
{
	if (head->capacity == head->size)//��������˾�����
	{
		Create(head);
	}
	head->data[head->size] = data;
	head->size++;//�������ݺ�Ӽ�
	printf("ѹջ�ɹ�\n");
}
//��ջ
void PosStack(STK* head)
{
	if (head->size == 0)
	{
		printf("ջΪ��\n");
		return;
	}
	printf("%d\n", head->data[(head->size)-1]);
	head->size--;//ɾ�����ݼ���
	printf("�ѳ�ջ\n");
}
//�鿴ջ��Ԫ��
void Lookhead(STK* head)
{
	assert(head);
	if (EmptyStack(head))
	{
		printf("ջΪ��\n");
		return;
	}
	printf("%d\n", head->data[(head->size) - 1]);
}
//�鿴ջԪ�ظ���
int SizeStack(STK* head)
{
	assert(head);
	printf("%d��\n", head->size);
	return head->size;
}
//����
void Destroy(STK* head)
{
	assert(head);
	free(head->data);
	printf("ջ������\n");
}