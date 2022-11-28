#define _CRT_SECURE_NO_WARNINGS 1
//交换
void Swp(int* head, int son, int parent)
{
	int ch = head[son];
	head[son] = head[parent];
	head[parent] = ch;
}
//向下调整(大堆)
void AjustDown(int* head, int parent, int size)//数组，父节点，元素个数
{
	int son;
	while ((son = (parent * 2) + 1) < size)//结束说明此时的parent已为叶节点
	{

		if (son + 1 < size && head[son + 1] > head[son])//比较左右孩子大小
		{
			son += 1;
		}
		if (head[son] > head[parent])//父子对比
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
//建堆（堆是用完全二叉树作为存储结构的）
void TreeCreate(int* arr, int size)//
{
	int parent = (size - 1) / 2;//尾节点的父节点
	for (parent; parent >= 0; parent--)
	{
		AjustDown(arr, parent, size);
	}
}
//每次Top最大值
int TreeTop(int* arr, int* size)
{
	int cur = arr[0];
	arr[0] = arr[(*size) - 1];//删除最大值
	(*size)--;
	AjustDown(arr, 0, *size);//调整
	return cur;
}
