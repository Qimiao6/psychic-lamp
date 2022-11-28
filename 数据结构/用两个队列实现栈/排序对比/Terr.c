#define _CRT_SECURE_NO_WARNINGS 1
//����
void Swp(int* head, int son, int parent)
{
	int ch = head[son];
	head[son] = head[parent];
	head[parent] = ch;
}
//���µ���(���)
void AjustDown(int* head, int parent, int size)//���飬���ڵ㣬Ԫ�ظ���
{
	int son;
	while ((son = (parent * 2) + 1) < size)//����˵����ʱ��parent��ΪҶ�ڵ�
	{

		if (son + 1 < size && head[son + 1] > head[son])//�Ƚ����Һ��Ӵ�С
		{
			son += 1;
		}
		if (head[son] > head[parent])//���ӶԱ�
		{
			Swp(head, son, parent);
			parent = son;
		}
		else
		{
			break;
		}
	}
}
//���ѣ���������ȫ��������Ϊ�洢�ṹ�ģ�
void TreeCreate(int* arr, int size)//
{
	int parent = (size - 1) / 2;//β�ڵ�ĸ��ڵ�
	for (parent; parent >= 0; parent--)
	{
		AjustDown(arr, parent, size);
	}
}
//ÿ��Top���ֵ
int TreeTop(int* arr, int* size)
{
	int cur = arr[0];
	arr[0] = arr[(*size) - 1];//ɾ�����ֵ
	(*size)--;
	AjustDown(arr, 0, *size);//����
	return cur;
}
