#pragma once

//向下调整
void AjustDown(int* head, int parent, int size);//数组，父节点，元素个数
//交换
void Swp(int* head, int son, int parent);
//建堆
void TreeCreate(int* arr, int size);
//Top最大值
int TreeTop(int* arr, int* size);