#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化
void Init(STK* head)
{
	StackData* cur = (StackData*)malloc(sizeof(StackData) * 4);
	if (NULL == cur)
	{
		//进来说明内存申请失败
		perror("malloc");
		exit(-1);
	}
	head->data = cur;
	head->capacity = 4;
	head->size = 0;
}
//判断栈是否为空
bool EmptyStack(STK* head)
{
	return !head->size;//为空返回真
}
//扩容
void Create(STK* head)
{
	StackData* cur = (StackData*)realloc(head,sizeof(StackData) * (head->capacity + 2));
	if (NULL == cur)
	{
		//进来说明内存申请失败
		perror("realloc");
		exit(-1);
	}
	head->data = cur;
	head->capacity = head->capacity + 2;
}
//压栈
void PusStack(STK* head ,StackData data)
{
	if (head->capacity == head->size)//如果存满了就扩容
	{
		Create(head);
	}
	head->data[head->size] = data;
	head->size++;//存入数据后加加
	printf("压栈成功\n");
}
//出栈
void PosStack(STK* head)
{
	if (head->size == 0)
	{
		printf("栈为空\n");
		return;
	}
	printf("%d\n", head->data[(head->size)-1]);
	head->size--;//删除数据减减
	printf("已出栈\n");
}
//查看栈顶元素
void Lookhead(STK* head)
{
	assert(head);
	if (EmptyStack(head))
	{
		printf("栈为空\n");
		return;
	}
	printf("%d\n", head->data[(head->size) - 1]);
}
//查看栈元素个数
int SizeStack(STK* head)
{
	assert(head);
	printf("%d个\n", head->size);
	return head->size;
}
//销毁
void Destroy(STK* head)
{
	assert(head);
	free(head->data);
	printf("栈已销毁\n");
}