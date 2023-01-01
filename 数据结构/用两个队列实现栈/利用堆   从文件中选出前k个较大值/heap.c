#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void HpInit(HP* head)//��ʼ��
{
	assert(head);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void HpDestroy(HP* head)//����
{
	assert(head);
	free(head->data);
	head->data = NULL;
	head->size = head->capacity = 0;
}
void Swp(HP* head, int sor, int parent)//��������
{
	HeapData cur = head->data[sor];
	head->data[sor] = head->data[parent];
	head->data[parent] = cur;
}
//�����������
void Adjustup(HP* head)
{
	assert(head);
	int sor = head->size;//Ҫ��������
	while (sor > 0)
	{
		int parent = (sor - 1) / 2;//���丸�׽ڵ�
		if (head->data[sor] >= head->data[parent])
		{
			break;//�ȸ��׽ڵ�С���������
		}
		Swp(head, sor, parent);//����ȸ��׽ڵ��ͽ���
		sor = parent;
	}
}
void HpPus(HP* head , HeapData data)//��������
{
	assert(head);//
	if (head->capacity == head->size)//���˵��������
	{
		head->capacity == 0 ? (head->capacity = 4) : (head->capacity *= 2);
		//head->capacity = 4;
		HeapData* cur = (HeapData*)realloc(head->data, sizeof(HeapData) * head->capacity);
		if (cur == NULL)//����ڴ�����ʧ��
		{
			perror("realloc");
			exit(-1);
		}
		head->data = cur;
	}
	//��ʼ����
	head->data[head->size] = data;
	//��������
	Adjustup(head);
	head->size++;//�������
}
void print(HP* head)//��ӡ
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
//���п�
bool HpEmpty(HP* head)
{
	assert(head);
	return !head->size;//Ϊ�շ�����
}
void AdjustDown(HP* head)//ɾ�������µ���
{
	assert(head);
	int parent = 0;
	while (parent < head->size)
	{
		int leftsor = parent * 2 + 1;//�����±�
		if (leftsor >= head->size)//�Ѿ�������ɣ�û�����������bug�������ײ���˶���
		{
			break;
		}
		if (leftsor + 1 < head->size && head->data[leftsor] > head->data[leftsor + 1])
		{
			leftsor++;//�ҳ����Һ����нϴ��һλ��ע��leftsor + 1��ҪԽ��
		}
		if (head->data[parent] <= head->data[leftsor])//�Ѿ��������
		{
			break;
		}
		//���parentС�����ĺ����򽻻�
		Swp(head, leftsor, parent);
		parent = leftsor;
	}
	//������ɽ���
}
//�ѵ��м�ɾû���壬һ�㶼��ɾ���Ѷ�
void HpPop(HP* head)
{
	assert(head);
	if (HpEmpty(head))
	{
		printf("������\n");
		return;
	}
	head->data[0] = head->data[head->size - 1];//ɾ��ͷ������
	head->size--;
	//���µ�������
	AdjustDown(head);
	//ɾ�����
}
HeapData HpTop(HP* head)//�鿴ͷ������
{
	assert(head);
	if (HpEmpty(head))
	{
		printf("������\n");
		return -1;
	}
	 return head->data[0];
}
int Hpsize(HP* head)//�鿴���ݸ���
{
	assert(head);
	return head->size;
}

//���ļ�����ǰk���ϴ�ֵ
void HeapTop(HP* head)
{
	int x = 0;
	int K = 5;
	FILE* cur = fopen("Heap.txt", "w");//��д����ʽ���ļ�
	if (cur == NULL)//�����ʧ��
	{
		perror("fopen");
		return;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)//���������
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
	fclose(cur);//�ر��ļ�
	cur = NULL;
	cur = fopen("Heap.txt", "r");//�Զ�����ʽ���ļ�
	for (int i = 0; i < K; i++)
	{
		if (fscanf(cur, "%d", &x) < 1)
		{
			break;
		}
		HpPus(head,x);//��������,�ú����Ѿ�Ƕ�����ݵ�������
	}
	while(fscanf(cur, "%d", &x) == 1)//ѡ�ϴ�ֵ
	{
		if (x > head->data[0])
		{
			head->data[0] = x;
			AdjustDown(head);
		}
	}
	fclose(cur);//�ر��ļ�
	cur = NULL;
}