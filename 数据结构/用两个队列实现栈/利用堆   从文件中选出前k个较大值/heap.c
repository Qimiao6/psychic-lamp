#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void HpInit(HP* head)//初始化
{
	assert(head);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void HpDestroy(HP* head)//销毁
{
	assert(head);
	free(head->data);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void Swp(HP* head, int sor, int parent)//交换函数
{
	HeapData cur = head->data[sor];
	head->data[sor] = head->data[parent];
	head->data[parent] = cur;
}
//插入调整函数
void Adjustup(HP* head)
{
	assert(head);
	int sor = head->size;//要调整的数
	while (sor > 0)
	{
		int parent = (sor - 1) / 2;//求其父亲节点
		if (head->data[sor] >= head->data[parent])
		{
			break;//比父亲节点小或等于跳出
		}
		Swp(head, sor, parent);//如果比父亲节点大就交换
		sor = parent;
	}
}
void HpPus(HP* head , HeapData data)//插入数据
{
	assert(head);//
	if (head->capacity == head->size)//相等说明存满了
	{
		head->capacity == 0 ? (head->capacity = 4) : (head->capacity *= 2);
		//head->capacity = 4;
		HeapData* cur = (HeapData*)realloc(head->data, sizeof(HeapData) * head->capacity);
		if (cur == NULL)//如果内存申请失败
		{
			perror("realloc");
			exit(-1);
		}
		head->data = cur;
	}
	//开始插入
	head->data[head->size] = data;
	//调整部分
	Adjustup(head);
	head->size++;//插入完成
}
void print(HP* head)//打印
{
	assert(head);
	int i = 0;
	while (i < head->size)
	{
		printf("%d ", head->data[i]);
		if ( i != 0 && i % 10 == 0 )
		{
			printf("\n");
		}
		i++;
	}
}
//堆判空
bool HpEmpty(HP* head)
{
	assert(head);
	return !head->size;//为空返回真
}
void AdjustDown(HP* head)//删除后向下调整
{
	assert(head);
	int parent = 0;
	while (parent < head->size)
	{
		int leftsor = parent * 2 + 1;//左孩子下标
		if (leftsor >= head->size)//已经调整完成，没有这个不会有bug，误打误撞对了而已
		{
			break;
		}
		if (leftsor + 1 < head->size && head->data[leftsor] > head->data[leftsor + 1])
		{
			leftsor++;//找出左右孩子中较大的一位，注意leftsor + 1不要越界
		}
		if (head->data[parent] <= head->data[leftsor])//已经调整完成
		{
			break;
		}
		//如果parent小于他的孩子则交换
		Swp(head, leftsor, parent);
		parent = leftsor;
	}
	//调整完成结束
}
//堆的中间删没意义，一般都是删除堆顶
void HpPop(HP* head)
{
	assert(head);
	if (HpEmpty(head))
	{
		printf("无数据\n");
		return;
	}
	head->data[0] = head->data[head->size - 1];//删除头部数据
	head->size--;
	//向下调整数据
	AdjustDown(head);
	//删除完成
}
HeapData HpTop(HP* head)//查看头部数据
{
	assert(head);
	if (HpEmpty(head))
	{
		printf("无数据\n");
		return -1;
	}
	 return head->data[0];
}
int Hpsize(HP* head)//查看数据个数
{
	assert(head);
	return head->size;
}

//在文件中找前k个较大值
void HeapTop(HP* head)
{
	int x = 0;
	int K = 5;
	FILE* cur = fopen("Heap.txt", "w");//以写的形式打开文件
	if (cur == NULL)//如果打开失败
	{
		perror("fopen");
		return;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)//生成随机数
	{
		if (i == 1 || i == 9995 || i == 9996 || i == 9997 || i == 9998)
		{
			fprintf(cur, "%d\n", rand() );
		}
		else
		{
			fprintf(cur, "%d\n", rand() % 1000);
		}
	}
	fclose(cur);//关闭文件
	cur = NULL;
	cur = fopen("Heap.txt", "r");//以读的形式打开文件
	for (int i = 0; i < K; i++)
	{
		if (fscanf(cur, "%d", &x) < 1)
		{
			break;
		}
		HpPus(head,x);//插入数据,该函数已经嵌入数据调整功能
	}
	while(fscanf(cur, "%d", &x) == 1)//选较大值
	{
		if (x > head->data[0])
		{
			head->data[0] = x;
			AdjustDown(head);
		}
	}
	fclose(cur);//关闭文件
	cur = NULL;
}